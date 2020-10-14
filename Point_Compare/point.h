#include "helper.h"

typedef struct point_type{

  float x; //x coordinate
  float y; // y coordinate
} Point;

Point* make_point(float x, float y);
int is_below(Point* below, Point* above);
int is_above(Point* above, Point* below);
int is_before(Point* first, Point* second);
int is_after(Point* second, Point* first);
void print_point(Point* point);
void free_point(Point* point);
