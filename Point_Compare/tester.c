/**Whole System Testing file **/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "segment.h"

int main(int argc, char** argv) {

  /*test helper functions*/
  float f1 = 4.0;
  float f2 = 10.234;
  printf("f1 check f1 is: %f\n", f1);
  printf("f2 check f2 is: %f\n", f2);
  printf("testing float subtract f2 - f1: %f\n", float_subtract(f2, f1));
  printf("equality check float subtract and normal f2 - f1: %d\n", (float_subtract(f2, f1) == (f2 - f2)));
  printf("equality check float subtract and normal f2 - f1 using floats_equal: %d\n", floats_equal(float_subtract(f2, f1), (f2 - f1)));
  printf("equality check float subtract and hard coded f2 - f1 result: %d\n", (float_subtract(f2, f1) == 6.234));
  printf("equality check float subtract and normal f2 - f1 result using floats_equal: %d\n", floats_equal(float_subtract(f2, f1), 6.234));

  printf("testing float_add f1 + f2: %f, and normal addition: %f \n", float_add(f1, f2), (f1 + f2));

  float f3 = 3.3;
  float f4 = 3.2;
  printf("testing floats greater than f3 > f4: %d\n", float_greater_than(f3, f4));
  printf("testing floats greater than, is f3 greater than the hard coded value of f3?: %d\n", float_greater_than(f3, 3.3));


  //Test point class
  Point* point1;
  point1 = make_point(f1, f2);
  printf("point1 x: %f, y: %f\n", point1->x, point1->y);

  Point* point2;
  point2 = make_point(f3, f4);
  printf("point2 x: %f, y: %f\n", point2->x, point2->y);

  printf("is point2 above point1?: %d\n", is_above(point2, point1));
  printf("is point1 above point2?: %d\n", is_above(point1, point2));
  printf("is point2 below point1?: %d\n", is_below(point2, point1));
  printf("is point1 below point2?: %d\n", is_below(point1, point2));
  printf("is point2 before point1?: %d\n", is_before(point2, point1));
  printf("is point1 before point2?: %d\n", is_before(point1, point2));
  printf("is point2 after point1?: %d\n", is_after(point2, point1));
  printf("is point1 after point2?: %d\n", is_after(point1, point2));
  free_point(point1);
  free_point(point2);

  Point points[2];
  points[0] = *make_point(f1, f2);
  points[1] = *make_point(f3, f4);
  printf("points[0] x: %f, y: %f\n", points[0].x, points[0].y);
  printf("points[1] x: %f, y: %f\n", points[1].x, points[1].y);

  printf("point[0] above point[1]?: %d\n", is_above(&points[0], &points[1]));

  Segment* segment1;
  segment1 = make_segment(&points[0], &points[1]);
  print_segment(segment1);

  float f5 = 0;
  float f6 = 0;
  Point* point3;
  point3 = make_point(f5, f6);

  float f7 = 4.0;
  float f8 = 10.0;
  Point* point4;
  point4 = make_point(f7, f8);

  Segment* segment2;
  segment2 = make_segment(point3, point4);
  printf("Segment2:\n");
  print_segment(segment2);

  float f9 = 0;
  float f10 = 1.0;
  Point* point5;
  point5 = make_point(f9, f10);

  Point* point6;
  point6 = make_point(f10, f9);

  Segment* segment3;
  segment3 = make_segment(point5, point6);

  printf("Segment3:\n");
  print_segment(segment3);


  printf("do segment2 and segment 3 intersect?: %d\n", intersect(segment2, segment3));


  free_segment(segment1);
  free_segment(segment2);
  free_segment(segment3);
  free_point(point3);
  free_point(point4);
  free_point(point5);
  free_point(point6);
}
