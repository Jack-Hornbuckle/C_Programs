#include <stdlib.h>
#include <stdio.h>
#include "point.h"
#include "helper.h"

//Create a point
Point* make_point(float x, float y){
  Point* the_point; //our point
  the_point = calloc(1, sizeof(Point*)); //allocate space
  the_point->x = x;  //set the x value
  the_point->y = y;  //set the y value
  return the_point;
}


//Check if the point "below" is below the point "above" on the y axis.
int is_below(Point* below, Point* above){
  return (!(floats_equal(below->y, above->y) || below->y > above->y));
}


//check if the point "above" is above the point "below" on the y axis.
int is_above(Point* above, Point* below){
  return (!(floats_equal(below->y, above->y) || below->y > above->y));
}



//Check if the point "first" precedes the point "second"
int is_before(Point* first, Point* second) {
  return (!(floats_equal(first->x, second->x) || first->x > second->x));
}


//Check if the point "second" follows the point "first" on the x axis
int is_after(Point* second, Point* first) {
  return (!(floats_equal(first->x, second->x) || first->x > second->x));
}

//Print the point
void print_point(Point* point) {
  printf("x: %f\n", point->x);
  printf("y: %f\n\n", point->y);
  return;
}

//Free the point
void free_point(Point* point) {
  free(point);
  return;
}
