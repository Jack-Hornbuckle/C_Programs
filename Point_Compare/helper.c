#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "helper.h"

//Check if two floats are equal
int floats_equal(float f1, float f2) {
  float precision = 0.00001;
  return (((f1 - precision) < f2) && (f1 + precision) > f2);
}

//Check if float f1 is less than float f2
int float_less_than(float f1, float f2) {
  return (!floats_equal(f1, f2) && (f1 < f2));
}

//Check if float f1 is greater than float f2
int float_greater_than(float f1, float f2) {
  return (!floats_equal(f1, f2) && (f1 > f2));
}

//subtract float f1 from f2.
float float_subtract(float f1, float f2) {
  return (f1 - f2);
}

//add float f1 and f2
float float_add(float f1, float f2) {
  return (f1 + f2);
}

//multiply float f1 and f2
float float_mulitply(float f1, float f2) {
  return (f1 * f2);
}

//divide float f1 by float f2
float float_divide(float f1, float f2) {
  return (f1/f2);
}

//used for converting part of a line to a float, check if a chr does not belong
//in the string representing a float.
int is_invalid_char(char chr) {
  return (chr == '(' || chr == ')' || chr == ',' || chr == ' ');
}


//convert a string to a float
float string_to_float(char* string) {

  //Scan for invalid characters
  int num_float_chars = (int) strlen(string); //used to create the return float string
  //Loop through the string and check if each char is invalid
  for (int i=0; i < strlen(string); i++) {
    //if an invalid char is detected, decrement num_float_chars by 1.
    num_float_chars = num_float_chars - is_invalid_char(string[i]);
  }

  //declare our float string
  char* float_str;
  float_str = malloc(num_float_chars*sizeof(char)); //allocate the memory
  int counter = 0; //our counter

  //loop through the original string again
  for (int j=0; j < strlen(string); j++) {
    if (!is_invalid_char(string[j])) { //if the char is valid
      float_str[counter] = string[j]; //add that char to the float string
      counter = counter + 1;   //increment the counter by 1.
    }
  }
  float_str[counter] = '\0'; //add a null terminator character to the end of the string
  return strtof(float_str, NULL);  //return the string converted to a float.

}
