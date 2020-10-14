#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "segment.h"
#include "list.h"
#include <CUnit/basic.h>

int init_suite(void) {
  return 0;
}

int clean_suite(void) {
  return 0;
}

//Test the "floats_equal()" function
void test_floats_equal(void) {
  CU_ASSERT(floats_equal(1.0, 1.0));
  float f1 = 0.2;
  float f2 = 0.2;
  CU_ASSERT(floats_equal(f1, f2));
  float f3 = 0.3;
  float f4 = 0.31;
  float f5 = 1.1;
  float f6 = 1.2;
  CU_ASSERT(floats_equal(f5, f5));
  CU_ASSERT(!floats_equal(1.0, f1));
  CU_ASSERT(!floats_equal(f1, f3));
  CU_ASSERT(!floats_equal(f3, f4));
  CU_ASSERT(!floats_equal(f5, f6));
  CU_ASSERT(!floats_equal(f4, f3));
}

//Test the "float_less_than()" function
void test_float_less_than(void) {
  float f1 = 0.2;
  float f2 = 0.3;
  float f3 = 0.4;
  float f4 = 1.0;
  float f5 = 1.1;
  float f6 = 1.2;
  float f7 = 2.0;
  float f8 = 2.1;
  CU_ASSERT(float_less_than(f1, f2));
  CU_ASSERT(float_less_than(f1, f3));
  CU_ASSERT(float_less_than(f2, f3));
  CU_ASSERT(float_less_than(f3, f4));
  CU_ASSERT(float_less_than(f4, f5));
  CU_ASSERT(float_less_than(f5, f6));
  CU_ASSERT(float_less_than(f4, f6));
  CU_ASSERT(float_less_than(f6, f7));
  CU_ASSERT(float_less_than(f7, f8));
  CU_ASSERT(!float_less_than(f1, f1));
  CU_ASSERT(!float_less_than(f4, f4));
  CU_ASSERT(!float_less_than(f2, f1));
  CU_ASSERT(!float_less_than(f5, f4));
  CU_ASSERT(!float_less_than(f8, f8));
}

//Test the "float_greater_than()" function
void test_float_greater_than(void) {
  float f1 = 0.2;
  float f2 = 0.3;
  float f3 = 0.4;
  float f4 = 1.0;
  float f5 = 1.1;
  float f6 = 1.2;
  float f7 = 2.0;
  float f8 = 2.1;
  CU_ASSERT(float_greater_than(f2, f1));
  CU_ASSERT(float_greater_than(f4, f3));
  CU_ASSERT(float_greater_than(f5, f4));
  CU_ASSERT(float_greater_than(f6, f5));
  CU_ASSERT(float_greater_than(f6, f5));
  CU_ASSERT(float_greater_than(f7, f4));
  CU_ASSERT(float_greater_than(f7, f6));
  CU_ASSERT(float_greater_than(f8, f7));
  CU_ASSERT(!float_greater_than(f1, f2));
  CU_ASSERT(!float_greater_than(f1, f3));
  CU_ASSERT(!float_greater_than(f2, f3));
  CU_ASSERT(!float_greater_than(f3, f4));
  CU_ASSERT(!float_greater_than(f4, f5));
  CU_ASSERT(!float_greater_than(f5, f6));
  CU_ASSERT(!float_greater_than(f4, f6));
  CU_ASSERT(!float_greater_than(f6, f7));
  CU_ASSERT(!float_greater_than(f7, f8));
  CU_ASSERT(!float_greater_than(f1, f1));
  CU_ASSERT(!float_greater_than(f4, f4));

}

//Test the "float_subtract()" function
void test_float_subtract(void) {
  float f1 = 0.2;
  float f2 = 0.3;
  float f3 = 0.4;
  float f4 = 1.0;
  float f5 = 1.1;
  float f6 = 1.2;
  float f7 = 2.0;
  float f8 = 2.1;
  CU_ASSERT(floats_equal(0.1, float_subtract(f2, f1)));
  CU_ASSERT(floats_equal(0.2, float_subtract(f3, f1)));
  CU_ASSERT(floats_equal(0.6, float_subtract(f4, f3)));
  CU_ASSERT(floats_equal(0.1, float_subtract(f5, f4)));
  CU_ASSERT(floats_equal(0.1, float_subtract(f6, f5)));
  CU_ASSERT(floats_equal(0.2, float_subtract(f6, f4)));
  CU_ASSERT(floats_equal(1.0, float_subtract(f6, f1)));
  CU_ASSERT(floats_equal(0.8, float_subtract(f7, f6)));
  CU_ASSERT(floats_equal(1.0, float_subtract(f7, f4)));
  CU_ASSERT(floats_equal(0.1, float_subtract(f8, f7)));
  CU_ASSERT(floats_equal(1.0, float_subtract(f8, f5)));
  CU_ASSERT(floats_equal(0, float_subtract(f1, f1)));
  CU_ASSERT(floats_equal(0, float_subtract(f4, f4)));
}


//Test the "float_add()" function
void test_float_add(void) {
  float f1 = 0.2;
  float f2 = 0.3;
  float f3 = 0.4;
  float f4 = 1.0;
  float f5 = 1.1;
  float f6 = 1.2;
  float f7 = 2.0;
  float f8 = 2.1;
  CU_ASSERT(floats_equal(0.4, float_add(f1, f1)));
  CU_ASSERT(floats_equal(0.5, float_add(f2, f1)));
  CU_ASSERT(floats_equal(0.6, float_add(f2, f2)));
  CU_ASSERT(floats_equal(0.7, float_add(f3, f2)));
  CU_ASSERT(floats_equal(1.4, float_add(f4, f3)));
  CU_ASSERT(floats_equal(2.0, float_add(f4, f4)));
  CU_ASSERT(floats_equal(2.1, float_add(f5, f4)));
  CU_ASSERT(floats_equal(2.2, float_add(f5, f5)));
  CU_ASSERT(floats_equal(2.3, float_add(f6, f5)));
  CU_ASSERT(floats_equal(3.2, float_add(f7, f6)));
  CU_ASSERT(floats_equal(4.0, float_add(f7, f7)));
  CU_ASSERT(floats_equal(4.1, float_add(f8, f7)));
}


//Test the "float_mulitply()".
void test_float_multiply(void) {
  float f1 = 0.2;
  float f2 = 0.3;
  float f3 = 0.4;
  float f4 = 1.0;
  float f5 = 1.1;
  float f6 = 1.2;
  float f7 = 2.0;
  float f8 = 2.1;
  CU_ASSERT(floats_equal(0.06, float_mulitply(f2, f1)));
  CU_ASSERT(floats_equal(0.12, float_mulitply(f3, f2)));
  CU_ASSERT(floats_equal(1.2, float_mulitply(f3, 3.0)));
  CU_ASSERT(floats_equal(0.4, float_mulitply(f4, f3)));
  CU_ASSERT(floats_equal(1.0, float_mulitply(f1, 5.0)));
  CU_ASSERT(floats_equal(1.1, float_mulitply(f5, f4)));
  CU_ASSERT(floats_equal(1.32, float_mulitply(f6, f5)));
  CU_ASSERT(floats_equal(2.40, float_mulitply(f7, f6)));
  CU_ASSERT(floats_equal(2.0, float_mulitply(f7, f4)));
  CU_ASSERT(floats_equal(0.8, float_mulitply(f7, f3)));
  CU_ASSERT(floats_equal(4.0, float_mulitply(f7, f7)));
  CU_ASSERT(floats_equal(1.0, float_mulitply(f7, 0.5)));
  CU_ASSERT(floats_equal(4.20, float_mulitply(f8, f7)));
  CU_ASSERT(floats_equal(4.41, float_mulitply(f8, f8)));
}


//Test the "float_divide()" function.
void test_float_divide(void) {
  float f1 = 0.2;
  float f2 = 0.3;
  float f3 = 0.4;
  float f4 = 1.0;
  float f5 = 1.1;
  float f6 = 1.2;
  float f7 = 2.0;
  float f8 = 2.1;
  CU_ASSERT(floats_equal(1.5, float_divide(f2, f1)));
  CU_ASSERT(floats_equal(1.0, float_divide(f2, f2)));
  CU_ASSERT(floats_equal(2.5, float_divide(f4, f3)));
  CU_ASSERT(floats_equal(1.1, float_divide(f5, f4)));
  CU_ASSERT(floats_equal(1.2, float_divide(f6, f4)));
  CU_ASSERT(floats_equal(3.0, float_divide(f6, f3)));
  CU_ASSERT(floats_equal(4.0, float_divide(f6, f2)));
  CU_ASSERT(floats_equal(6.0, float_divide(f6, f1)));
  CU_ASSERT(floats_equal(2.0, float_divide(f7, f4)));
  CU_ASSERT(floats_equal(5.0, float_divide(f7, f3)));
  CU_ASSERT(floats_equal(10.0, float_divide(f7, f1)));
  CU_ASSERT(floats_equal(7.0, float_divide(f8, f2)));
}


//Test the "invalid_char()" function
void test_invalid_char(void) {
  char chr1 = '(';
  char chr2 = ')';
  char chr3 = ',';
  char chr4 = ' ';
  char chr5 = '.';
  char chr6 = '6';
  char chr7 = '7';
  char chr8 = '0';
  CU_ASSERT(is_invalid_char(chr1));
  CU_ASSERT(is_invalid_char(chr2));
  CU_ASSERT(is_invalid_char(chr3));
  CU_ASSERT(is_invalid_char(chr4));
  CU_ASSERT(!is_invalid_char(chr5));
  CU_ASSERT(!is_invalid_char(chr6));
  CU_ASSERT(!is_invalid_char(chr7));
  CU_ASSERT(!is_invalid_char(chr8));
}


//Test the "string_to_float()" function.
void test_string_to_float(void) {
  char* flt_str1 = "(2.6";
  char* flt_str2 = "2.5";
  char* flt_str3 = "3.0,";
  char* flt_str4 = "(3.1,";
  char* flt_str5 = " (3.33";
  char* flt_str6 = ", 2.0)";
  char* flt_str7 = "4.3)";
  char* flt_str8 = " 6.9";

  CU_ASSERT(floats_equal(2.6, string_to_float(flt_str1)));
  CU_ASSERT(floats_equal(2.5, string_to_float(flt_str2)));
  CU_ASSERT(floats_equal(3.0, string_to_float(flt_str3)));
  CU_ASSERT(floats_equal(3.1, string_to_float(flt_str4)));
  CU_ASSERT(floats_equal(3.33, string_to_float(flt_str5)));
  CU_ASSERT(floats_equal(2.0, string_to_float(flt_str6)));
  CU_ASSERT(floats_equal(4.3, string_to_float(flt_str7)));
  CU_ASSERT(floats_equal(6.9, string_to_float(flt_str8)));

}


//Test the "is_below()" function
void test_is_below(void) {
  Point* p1 = make_point(3.3, 1.1);
  Point* p2 = make_point(3.3, 2.2);
  Point* p3 = make_point(4.2, 2.2);
  Point* p4 = make_point(3.3, 3.5);
  Point* p5 = make_point(2.1, 7.0);
  Point* p6 = make_point(2.3, 77.0);
  CU_ASSERT(is_below(p1, p2));
  CU_ASSERT(!is_below(p1, p1));
  CU_ASSERT(!is_below(p2, p3));
  CU_ASSERT(is_below(p3, p4));
  CU_ASSERT(is_below(p4, p5));
  CU_ASSERT(is_below(p5, p6));
  CU_ASSERT(!is_below(p2, p1));
  free_point(p1);
  free_point(p2);
  free_point(p3);
  free_point(p4);
  free_point(p5);
  free_point(p6);
}


//Test the "is_above()" function.
void test_is_above(void) {
  Point* p1 = make_point(3.3, 1.1);
  Point* p2 = make_point(3.3, 2.2);
  Point* p3 = make_point(4.2, 2.2);
  Point* p4 = make_point(3.3, 3.5);
  Point* p5 = make_point(2.1, 7.0);
  Point* p6 = make_point(2.3, 77.0);
  CU_ASSERT(is_above(p2, p1));
  CU_ASSERT(!is_above(p1, p2));
  CU_ASSERT(!is_above(p3, p2));
  CU_ASSERT(is_above(p4, p3));
  CU_ASSERT(is_above(p5, p4));
  CU_ASSERT(is_above(p6, p5));
  CU_ASSERT(!is_above(p6, p6));
  free_point(p1);
  free_point(p2);
  free_point(p3);
  free_point(p4);
  free_point(p5);
  free_point(p6);
}


//Test the "is_before()" function.
void test_is_before(void) {
  Point* p1 = make_point(3.3, 1.1);
  Point* p2 = make_point(3.6, 2.2);
  Point* p3 = make_point(4.2, 2.2);
  Point* p4 = make_point(4.8, 1.6);
  Point* p5 = make_point(4.0, 7.0);
  Point* p6 = make_point(4.0, 77.0);
  CU_ASSERT(is_before(p1, p2));
  CU_ASSERT(is_before(p2, p3));
  CU_ASSERT(is_before(p3, p4));
  CU_ASSERT(!is_before(p4, p5));
  CU_ASSERT(!is_before(p5, p6));
  CU_ASSERT(!is_before(p6, p6));
  free_point(p1);
  free_point(p2);
  free_point(p3);
  free_point(p4);
  free_point(p5);
  free_point(p6);
}


//Test the "is_after()" function.
void test_is_after(void) {
  Point* p1 = make_point(3.3, 1.1);
  Point* p2 = make_point(3.6, 2.2);
  Point* p3 = make_point(4.2, 2.2);
  Point* p4 = make_point(4.8, 1.6);
  Point* p5 = make_point(4.0, 7.0);
  Point* p6 = make_point(4.0, 77.0);
  CU_ASSERT(is_after(p2, p1));
  CU_ASSERT(is_after(p3, p2));
  CU_ASSERT(is_after(p4, p3));
  CU_ASSERT(!is_after(p5, p4));
  CU_ASSERT(!is_after(p6, p5));
  CU_ASSERT(!is_after(p6, p6));
  free_point(p1);
  free_point(p2);
  free_point(p3);
  free_point(p4);
  free_point(p5);
  free_point(p6);
}


//Test the "intersect_on_vertical_line()" function.
void test_intersect_on_vertical_line(void) {
  Point* p1 = make_point(3.0, 1.0);
  Point* p2 = make_point(3.0, 4.0);
  Segment* seg1 = make_segment(p1, p2);

  Point* p3 = make_point(2.0, 1.0);
  Point* p4 = make_point(4.0, 3.0);
  Segment* seg2 = make_segment(p3, p4);

  Point* p5 = make_point(0, -1.0);
  Segment* seg3 = make_segment(p5, p3);

  Point* p6 = make_point(5.0, 4.0);
  Segment* seg4 = make_segment(p4, p6);

  Point* p7 = make_point(0, 0);
  Point* p8 = make_point(3.0, 3.0);
  Segment* seg5 = make_segment(p7, p8);

  CU_ASSERT(intersect_on_vertical_line(seg2, seg1));
  CU_ASSERT(!intersect_on_vertical_line(seg3, seg1));
  CU_ASSERT(!intersect_on_vertical_line(seg4, seg1));
  CU_ASSERT(intersect_on_vertical_line(seg5, seg1));
  free_point(p1);
  free_point(p2);
  free_point(p3);
  free_point(p4);
  free_point(p5);
  free_point(p6);
  free_point(p7);
  free_point(p8);

  /*free_segment(seg1);
  free_segment(seg2);
  free_segment(seg3);
  free_segment(seg4);
  free_segment(seg5);*/
}

//Test the "two_vertical_lines_intersect()" function
void test_two_vertical_lines_intersect(void) {
  Point* p1 = make_point(3.0, 1.0);
  Point* p2 = make_point(3.0, 4.0);
  Segment* seg1 = make_segment(p1, p2);

  Point* p3 = make_point(3.0, 0);
  Point* p4 = make_point(3.0, 3.0);
  Segment* seg2 = make_segment(p3, p4);

  Point* p5 = make_point(3.0, 5.0);
  Point* p6 = make_point(3.0, 6.0);
  Segment* seg3 = make_segment(p5, p6);

  Point* p7 = make_point(3.0, -1.0);
  Segment* seg4 = make_segment(p7, p3);

  Segment* seg5 = make_segment(p4, p5);

  Point* p8 = make_point(2.0, 2.0);
  Point* p9 = make_point(2.0, 4.0);
  Segment* seg6 = make_segment(p8, p9);

  CU_ASSERT(two_vertical_lines_intersect(seg1, seg2));
  CU_ASSERT(!two_vertical_lines_intersect(seg1, seg3));
  CU_ASSERT(!two_vertical_lines_intersect(seg1, seg4));
  CU_ASSERT(two_vertical_lines_intersect(seg1, seg5));
  CU_ASSERT(!two_vertical_lines_intersect(seg1, seg6));

  free_point(p1);
  free_point(p2);
  free_point(p3);
  free_point(p4);
  free_point(p5);
  free_point(p6);
  free_point(p7);
  free_point(p8);
  free_point(p9);

  free_segment(seg1);
  free_segment(seg2);
  free_segment(seg3);
  free_segment(seg4);
  free_segment(seg5);
  free_segment(seg6);
}


//test the "point_in_range_segment()" function.
void test_point_in_range_segment(void) {
   Point* p1 = make_point(0, 0);
   Point* p2 = make_point(5.0, 5.0);
   Segment* seg1 = make_segment(p1, p2);

   Point* p3 = make_point(0, 1.0);
   Point* p4 = make_point(2.0, 0);
   Point* p5 = make_point(2.0, 2.0);
   Point* p6 = make_point(0, -1.0);
   Point* p7 = make_point(6.0, 5.0);
   Point* p8 = make_point(6.0, 5.5);
   Point* p9 = make_point(6.0, 2.0);
   Point* p10 = make_point(4.0, 6.0);
   Point* p11 = make_point(2.0, 2.0);

   CU_ASSERT(point_in_range_segment(p1, seg1));
   CU_ASSERT(point_in_range_segment(p2, seg1));
   CU_ASSERT(point_in_range_segment(p3, seg1));
   CU_ASSERT(point_in_range_segment(p4, seg1));
   CU_ASSERT(point_in_range_segment(p5, seg1));
   CU_ASSERT(!point_in_range_segment(p6, seg1));
   CU_ASSERT(!point_in_range_segment(p6, seg1));
   CU_ASSERT(!point_in_range_segment(p7, seg1));
   CU_ASSERT(!point_in_range_segment(p8, seg1));
   CU_ASSERT(!point_in_range_segment(p9, seg1));
   CU_ASSERT(!point_in_range_segment(p10, seg1));
   CU_ASSERT(point_in_range_segment(p11, seg1));

   free_point(p1);
   free_point(p2);
   free_point(p3);
   free_point(p4);
   free_point(p5);
   free_point(p6);
   free_point(p7);
   free_point(p8);
   free_point(p9);
   free_point(p10);

   free_segment(seg1);
}


//Test the "normal_intersect_check()" function.
void test_normal_intersect_check(void) {
  Point* p1 = make_point(0, 0);
  Point* p2 = make_point(5.0, 5.0);
  Segment* seg1 = make_segment(p1, p2);

  Point* p3 = make_point(0, 5.0);
  Point* p4 = make_point(5.0, 0);
  Segment* seg2 = make_segment(p3, p4);

  Point* p5 = make_point(2.0, 3.0);
  Segment* seg3 = make_segment(p5, p3);

  Point* p6 = make_point(1.0, 6.0);
  Segment* seg4 = make_segment(p6, p5);

  Segment* seg5 = make_segment(p6, p3);

  Point* p7 = make_point(-1.0, -1.0);
  Point* p8 = make_point(-2.0, -2.0);
  Segment* seg6 = make_segment(p7, p8);

  Point* p9 = make_point(2.5, 2.5);
  Segment* seg7 = make_segment(p9, p3);

  CU_ASSERT(normal_intersect_check(seg1, seg2));
  CU_ASSERT(!normal_intersect_check(seg1, seg3));
  CU_ASSERT(!normal_intersect_check(seg1, seg4));
  CU_ASSERT(!normal_intersect_check(seg1, seg5));
  CU_ASSERT(!normal_intersect_check(seg1, seg6));
  CU_ASSERT(normal_intersect_check(seg1, seg7));

  free_point(p1);
  free_point(p2);
  free_point(p3);
  free_point(p4);
  free_point(p5);
  free_point(p6);
  free_point(p7);
  free_point(p8);
  free_point(p9);

  free_segment(seg1);
  free_segment(seg2);
  free_segment(seg3);
  free_segment(seg4);
  free_segment(seg5);
  free_segment(seg6);
  free_segment(seg7);
}


//Test the "intersect()" function.
void test_intersect(void) {
  Point* p1 = make_point(3.0, 1.0);
  Point* p2 = make_point(3.0, 4.0);
  Segment* seg1 = make_segment(p1, p2);

  Point* p3 = make_point(2.0, 1.0);
  Point* p4 = make_point(4.0, 3.0);
  Segment* seg2 = make_segment(p3, p4);

  Point* p5 = make_point(0, -1.0);
  Segment* seg3 = make_segment(p5, p3);

  Point* p6 = make_point(5.0, 4.0);
  Segment* seg4 = make_segment(p4, p6);

  Point* p7 = make_point(0, 0);
  Point* p8 = make_point(3.0, 3.0);
  Segment* seg5 = make_segment(p7, p8);

  CU_ASSERT(intersect(seg2, seg1));
  CU_ASSERT(!intersect(seg3, seg1));
  CU_ASSERT(!intersect(seg4, seg1));
  CU_ASSERT(intersect(seg5, seg1));

  Point* p9 = make_point(3.0, 1.0);
  Point* p10 = make_point(3.0, 4.0);
  Segment* seg6 = make_segment(p9, p10);

  Point* p11 = make_point(3.0, 0);
  Point* p12 = make_point(3.0, 3.0);
  Segment* seg7 = make_segment(p11, p12);

  Point* p13 = make_point(3.0, 5.0);
  Point* p14 = make_point(3.0, 6.0);
  Segment* seg8 = make_segment(p13, p14);

  Point* p15 = make_point(3.0, -1.0);
  Segment* seg9 = make_segment(p15, p11);

  Segment* seg10 = make_segment(p12, p13);

  Point* p16 = make_point(2.0, 2.0);
  Point* p17 = make_point(2.0, 4.0);
  Segment* seg11 = make_segment(p16, p17);

  CU_ASSERT(intersect(seg6, seg7));
  CU_ASSERT(!intersect(seg6, seg8));
  CU_ASSERT(!intersect(seg6, seg9));
  CU_ASSERT(intersect(seg6, seg10));
  CU_ASSERT(!intersect(seg6, seg11));


  Point* p18 = make_point(0, 0);
  Point* p19 = make_point(5.0, 5.0);
  Segment* seg12 = make_segment(p18, p19);

  Point* p20 = make_point(0, 5.0);
  Point* p21 = make_point(5.0, 0);
  Segment* seg13 = make_segment(p20, p21);

  Point* p22 = make_point(2.0, 3.0);
  Segment* seg14 = make_segment(p22, p20);

  Point* p23 = make_point(1.0, 6.0);
  Segment* seg15 = make_segment(p23, p22);

  Segment* seg16 = make_segment(p23, p20);

  Point* p24 = make_point(-1.0, -1.0);
  Point* p25 = make_point(-2.0, -2.0);
  Segment* seg17 = make_segment(p24, p25);

  Point* p26 = make_point(2.5, 2.5);
  Segment* seg18 = make_segment(p26, p20);

  CU_ASSERT(intersect(seg12, seg13));
  CU_ASSERT(!intersect(seg12, seg14));
  CU_ASSERT(!intersect(seg12, seg15));
  CU_ASSERT(!intersect(seg12, seg16));
  CU_ASSERT(!intersect(seg12, seg17));
  CU_ASSERT(intersect(seg12, seg18));

  free_point(p1);
  free_point(p2);
  free_point(p3);
  free_point(p4);
  free_point(p5);
  free_point(p6);
  free_point(p7);
  free_point(p8);
  free_point(p9);
  free_point(p10);
  free_point(p11);
  free_point(p12);
  free_point(p13);
  free_point(p14);
  free_point(p15);
  free_point(p16);
  free_point(p17);
  free_point(p18);
  free_point(p19);
  free_point(p20);
  free_point(p21);
  free_point(p22);
  free_point(p23);
  free_point(p24);
  free_point(p25);
  free_point(p26);

  free_segment(seg1);
  free_segment(seg2);
  free_segment(seg3);
  free_segment(seg4);
  free_segment(seg5);
  free_segment(seg6);
  free_segment(seg7);
  free_segment(seg8);
  free_segment(seg9);
  free_segment(seg10);
  free_segment(seg11);
  free_segment(seg12);
  free_segment(seg13);
  free_segment(seg14);
  free_segment(seg15);
  free_segment(seg16);
  free_segment(seg17);
  free_segment(seg18);


}


//main code that calls the unit tests

int main(int argc, char** argv) {

  //initialize the test registry
  if (CUE_SUCCESS != CU_initialize_registry()) {
    return CU_get_error();
  }
  CU_basic_set_mode(CU_BRM_VERBOSE);

  //Initialize the first test suite with the test it requires
  CU_pSuite suite1 = NULL;
  suite1 = CU_add_suite("Test floats_equal", init_suite, clean_suite);
  if (NULL == suite1) {
    CU_cleanup_registry();
    return CU_get_error();
  }

  //add the test for this suite
  if ((NULL == CU_add_test(suite1," testing floats_equal \n\n", test_floats_equal))) {
    CU_cleanup_registry();
    return CU_get_error();
  }

  //initialize rest of suites and add tests in the same fashion
  CU_pSuite suite2 = NULL;
  suite2 = CU_add_suite("\n\n Float less than test", init_suite, clean_suite);
  if (NULL == suite2) {
    CU_cleanup_registry();
    return CU_get_error();
  }

  if ((NULL == CU_add_test(suite2," testing floats_equal", test_float_less_than))) {
    CU_cleanup_registry();
    return CU_get_error();
  }

  CU_pSuite suite3 = NULL;
  suite3 = CU_add_suite("\n\n float greater than test", init_suite, clean_suite);
  if (NULL == suite3) {
    CU_cleanup_registry();
    return CU_get_error();
  }

  if ((NULL == CU_add_test(suite3," testing float greater than \n\n", test_float_greater_than))) {
    CU_cleanup_registry();
    return CU_get_error();
  }


  CU_pSuite suite4 = NULL;
  suite4 = CU_add_suite("\n\n float subtract test", init_suite, clean_suite);
  if (NULL == suite4) {
    CU_cleanup_registry();
    return CU_get_error();
  }

  if ((NULL == CU_add_test(suite4," testing float subtract \n\n", test_float_subtract))) {
    CU_cleanup_registry();
    return CU_get_error();
  }

  CU_pSuite suite5 = NULL;
  suite5 = CU_add_suite("\n\n float add test", init_suite, clean_suite);
  if (NULL == suite5) {
    CU_cleanup_registry();
    return CU_get_error();
  }

  if ((NULL == CU_add_test(suite5," testing float add \n\n", test_float_add))) {
    CU_cleanup_registry();
    return CU_get_error();
  }

  CU_pSuite suite6 = NULL;
  suite6 = CU_add_suite("\n\n float multiply test", init_suite, clean_suite);
  if (NULL == suite6) {
    CU_cleanup_registry();
    return CU_get_error();
  }

  if ((NULL == CU_add_test(suite6," testing float multiply \n\n", test_float_multiply))) {
    CU_cleanup_registry();
    return CU_get_error();
  }

  CU_pSuite suite7 = NULL;
  suite7 = CU_add_suite("\n\n float divide test", init_suite, clean_suite);
  if (NULL == suite7) {
    CU_cleanup_registry();
    return CU_get_error();
  }

  if ((NULL == CU_add_test(suite7," testing float divide \n\n", test_float_divide))) {
    CU_cleanup_registry();
    return CU_get_error();
  }

  CU_pSuite suite8 = NULL;
  suite8 = CU_add_suite("\n\n invalid char test", init_suite, clean_suite);
  if (NULL == suite8) {
    CU_cleanup_registry();
    return CU_get_error();
  }

  if ((NULL == CU_add_test(suite8," testing invalid_char \n\n", test_invalid_char))) {
    CU_cleanup_registry();
    return CU_get_error();
  }

  CU_pSuite suite9 = NULL;
  suite9 = CU_add_suite("\n\n string to float test", init_suite, clean_suite);
  if (NULL == suite9) {
    CU_cleanup_registry();
    return CU_get_error();
  }

  if ((NULL == CU_add_test(suite9," testing string to float \n\n", test_string_to_float))) {
    CU_cleanup_registry();
    return CU_get_error();
  }

  CU_pSuite suite10 = NULL;
  suite10 = CU_add_suite("\n\n is below test", init_suite, clean_suite);
  if (NULL == suite10) {
    CU_cleanup_registry();
    return CU_get_error();
  }

  if ((NULL == CU_add_test(suite10," testing is_below() \n\n", test_is_below))) {
    CU_cleanup_registry();
    return CU_get_error();
  }

  CU_pSuite suite11 = NULL;
  suite11 = CU_add_suite("\n\n is_above test", init_suite, clean_suite);
  if (NULL == suite11) {
    CU_cleanup_registry();
    return CU_get_error();
  }

  if ((NULL == CU_add_test(suite11," testing is_above \n\n", test_is_above))) {
    CU_cleanup_registry();
    return CU_get_error();
  }

  CU_pSuite suite12 = NULL;
  suite12 = CU_add_suite("\n\n is_before test", init_suite, clean_suite);
  if (NULL == suite12) {
    CU_cleanup_registry();
    return CU_get_error();
  }

  if ((NULL == CU_add_test(suite12," testing float greater than \n\n", test_is_before))) {
    CU_cleanup_registry();
    return CU_get_error();
  }


  CU_pSuite suite13 = NULL;
  suite13 = CU_add_suite("\n\n is_after test", init_suite, clean_suite);
  if (NULL == suite13) {
    CU_cleanup_registry();
    return CU_get_error();
  }

  if ((NULL == CU_add_test(suite13," testing float greater than \n\n", test_is_after))) {
    CU_cleanup_registry();
    return CU_get_error();
  }


  CU_pSuite suite14 = NULL;
  suite14 = CU_add_suite("\n\n intersect on vertical line test", init_suite, clean_suite);
  if (NULL == suite14) {
    CU_cleanup_registry();
    return CU_get_error();
  }

  if ((NULL == CU_add_test(suite14," testing intersect on vertical line \n\n", test_intersect_on_vertical_line))) {
    CU_cleanup_registry();
    return CU_get_error();
  }


  CU_pSuite suite15 = NULL;
  suite15 = CU_add_suite("\n\n intersect on two vertical lines test", init_suite, clean_suite);
  if (NULL == suite15) {
    CU_cleanup_registry();
    return CU_get_error();
  }

  if ((NULL == CU_add_test(suite15," testing intersect on two vertical lines \n\n", test_two_vertical_lines_intersect))) {
    CU_cleanup_registry();
    return CU_get_error();
  }

  CU_pSuite suite16 = NULL;
  suite16 = CU_add_suite("\n\n point in range test", init_suite, clean_suite);
  if (NULL == suite16) {
    CU_cleanup_registry();
    return CU_get_error();
  }

  if ((NULL == CU_add_test(suite16," testing point in range \n\n", test_point_in_range_segment))) {
    CU_cleanup_registry();
    return CU_get_error();
  }


  CU_pSuite suite17 = NULL;
  suite17 = CU_add_suite("\n\n normal intersect test", init_suite, clean_suite);
  if (NULL == suite17) {
    CU_cleanup_registry();
    return CU_get_error();
  }

  if ((NULL == CU_add_test(suite17," testing normal_intersect_check \n\n", test_normal_intersect_check))) {
    CU_cleanup_registry();
    return CU_get_error();
  }

  CU_pSuite suite18 = NULL;
  suite18 = CU_add_suite("\n\n intersect test", init_suite, clean_suite);
  if (NULL == suite18) {
    CU_cleanup_registry();
    return CU_get_error();
  }

  if ((NULL == CU_add_test(suite18," testing intersect  \n\n", test_intersect))) {
    CU_cleanup_registry();
    return CU_get_error();
  }


  //Run the tests
  CU_basic_run_tests();
  return CU_get_error();
}
