#include "point.h"

typedef struct segment_type {
  float m;
  float b;
  Point* first;
  Point* second;
  Point* top;
  Point* bottom;
  int slope_type;
} Segment;

Segment* make_segment(Point* first, Point* second);
Segment line_to_seg(char* line);
int point_in_range_segment(Point* point, Segment* segment);
int intersect_on_vertical_line(Segment* first, Segment* second);
int two_vertical_lines_intersect(Segment* first, Segment* second);
int normal_intersect_check(Segment* first, Segment* second);
int intersect(Segment* first, Segment* second);
void print_segment(Segment* segment);
void free_segment(Segment* segment);
