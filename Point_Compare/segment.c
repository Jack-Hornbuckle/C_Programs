#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "segment.h"
#include "helper.h"

Segment* make_segment(Point* first, Point* second) {

  //initialize the new line segment
  Segment* new_segment;
  new_segment = calloc(1, sizeof(Segment*));
  new_segment->first = calloc(1, sizeof(Point*));
  new_segment->second = calloc(1, sizeof(Point*));
  new_segment->top = calloc(1, sizeof(Point*));
  new_segment->bottom = calloc(1, sizeof(Point*));

  //Now set those points accordingly
  if (is_before(first, second)) {
    new_segment->first = make_point(first->x, first->y);
    new_segment->second = make_point(second->x, second->y);
  } else {
    new_segment->first = make_point(second->x, second->y);
    new_segment->second = make_point(first->x, first->y);
  }


  //initialize the top and bottom points in vertical order on the line segment
  if (is_above(first, second)) {
    new_segment->top = make_point(first->x, first->y);
    new_segment->bottom = make_point(second->x, second->y);
  } else {
    new_segment->top = make_point(second->x, second->y);
    new_segment->bottom = make_point(first->x, first->y);
  }


  //Compute the numerator and denominator of the slope
  float upper = float_subtract(first->y, second->y); //numerator of slope
  float lower = float_subtract(first->x, second->x); //denominator of slope


  //if denominator is not 0
  if (!floats_equal(lower, 0)) {
     new_segment->m = float_divide(upper, lower); //compute the slope

     //check if slope is negative for future operations
     new_segment->slope_type = float_greater_than(new_segment->m, 0);

     //compute the y intercept "b"
     float m_x = float_mulitply(new_segment->m, first->x);
     new_segment->b = float_subtract(first->y, m_x);

  //otherwise set m to 0 and indicate that the slope is completely vertical
  } else {
     new_segment->m = 0;
     new_segment->slope_type = 2;
  }
  return new_segment;

}


//Converts two points written on the line of a text file into
//two "Point" objects and then combines those two "Point" objects into a "Segment"
Segment line_to_seg(char* line) {
  float coordinates[2];
  Point points[2];
  int coord = 0;
  int point_num = 0;
  char* extract_num;
  extract_num = strtok(line, " ");
  while (extract_num != NULL) {
    coordinates[coord] = string_to_float(extract_num);
    if (coord == 1) {
      points[point_num] = *make_point(coordinates[0], coordinates[1]);
      point_num = point_num + 1;
    }
    coord = 1 + (coord * -1);
    extract_num = strtok(NULL, " ");
  }
  Segment return_segment;
  return_segment = *make_segment(&points[0], &points[1]);
  return return_segment;
}

//Check if a point is in range of a line segment
int point_in_range_segment(Point* point, Segment* segment) {

  //checks if the intersect point's x coordinate is in range of the x coordiantes of the points on the line segment
  int before_equal_second_x = (is_before(point, segment->second) || floats_equal(point->x, segment->second->x));
  int after_equal_first_x = (is_after(point, segment->first) || floats_equal(point->x, segment->first->x));
  int x_in_range = (before_equal_second_x && after_equal_first_x);

  //checks if the intersect point's y coordinate is in range of the y coordinates of the points of the line segment
  int below_equal_top_y = (is_below(point, segment->top) || floats_equal(point->y, segment->top->y));
  int above_equal_bottom_y = (is_above(point, segment->bottom) || floats_equal(point->y, segment->bottom->y));
  int y_in_range = (below_equal_top_y && above_equal_bottom_y);

  return (x_in_range && y_in_range);
}


//check if a completely vertical line segment "second" intersects a less vertical line segment "first"
int intersect_on_vertical_line(Segment* first, Segment* second) {
  float m_x = float_mulitply(second->top->x, first->m);
  float y_coord = float_add(m_x, first->b);
  Point* intersection = make_point(second->top->x, y_coord);
  int return_value = (point_in_range_segment(intersection, first) && point_in_range_segment(intersection, second));
  free_point(intersection);
  return return_value;
}


//Check if two completely vertical line segments overlap
int two_vertical_lines_intersect(Segment* first, Segment* second) {
  if (!floats_equal(first->top->x, second->top->x)) {
    return 0;
  } else if (float_greater_than(second->top->y, first->top->y) || floats_equal(second->top->y, first->top->y)) {
    return is_below(second->bottom, first->top);
  } else {
    return is_below(first->bottom, second->top);
  }
}



//Checks if two line segments that are not completely verticle intersect.
int normal_intersect_check(Segment* first, Segment* second) {

  //solve for the x coordinate of the point of intersection
  float m_diff = float_subtract(first->m, second->m); //get the difference the slopes on the left hand side
  float b_diff = float_subtract(second->b, first->b); //now get the difference of the y intercepts on the right hand side

  //If the differences between the m values and between the b values are both 0
  if ((floats_equal(m_diff, 0)) && floats_equal(b_diff, 0)) {
     Segment* before; //the preceding segment according to the x values of their first coordinates
     Segment* after; //the following segment according to he x values of the first coordinates

     //if the first segment's first cooridnate precedes that of the second segment
     if (is_before(first->first, second->first)) {
       //Set "before" to the first segment and "after" to the second segment.
       before = make_segment(first->first, first->second);
       after = make_segment(second->first, second->second);

       //Otherwise perform the opposite action
     } else {
       before = make_segment(second->first, second->second);
       after = make_segment(first->first, first->second);
     }

     //return whether the second point of "before" does not precede the first point of "after"
     return (!is_before(before->second, after->first));

  //Otherwise if only the differnce in the m values is 0 return 0.
  } else if (floats_equal(m_diff, 0)) {
     return 0;
  }


  /*If the difference between the m values is not 0, we procede to check for an
  intersection by finding a point of intersection and seeing if that point is on both
  segments*/

  //now divide the y intercept difference by the slope difference to get the x coordinate
  float x_coord = float_divide(b_diff, m_diff);

  //Now plug the x coordinate into the equation of the first line to get the y coordinate of the intersection point
  float y_coord = float_add(float_mulitply(x_coord, first->m), first->b);

  //create our intersection point to check if its in range of the line segments
  Point* intersect_point;
  intersect_point = make_point(x_coord, y_coord);

  //Check if the intersection point is in range of the line segments if so set the return value to 1 otherwise set it to 0
  int return_value = (point_in_range_segment(intersect_point, first) && point_in_range_segment(intersect_point, second));

  //free the intersection point and return the return value.
  free_point(intersect_point);
  return return_value;
}




int intersect(Segment* first, Segment* second) {

    //If onkly the first segment is horizontal check and see if the two segments cross each other
   if ((first->slope_type == 2) && (second->slope_type < 2)) {
      return intersect_on_vertical_line(second, first);
    //do the same if only the second is horizontal
   } else if ((first->slope_type < 2) && (second->slope_type == 2)) {
      return intersect_on_vertical_line(first, second);
    //if both are horizontal, check if they overlap
   } else if ((first->slope_type == 2) && (second->slope_type == 2)) {
      return two_vertical_lines_intersect(first, second);
    //otherwise check to see if the segments intersect normally
   } else {
      return normal_intersect_check(first, second);
   }
}


//Print out a line segment
void print_segment(Segment* segment) {
  printf("m: %f\n", segment->m);
  printf("b: %f\n", segment->b);
  printf("slope_type: %d\n", segment->slope_type);
  printf("top point:\n");
  print_point(segment->top);
  printf("bottom point:\n");
  print_point(segment->bottom);
  printf("first point on x axis:\n");
  print_point(segment->first);
  printf("second point on x axis: \n");
  print_point(segment->second);
  printf("\n\n");
}

//Free a line segment
void free_segment(Segment* segment) {
  free_point(segment->first);
  free_point(segment->second);
  free_point(segment->bottom);
  free_point(segment->top);
  free(segment);
  return;
}
