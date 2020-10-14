#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "segment.h"
#include "list.h"


int main(int argc, char** argv){
    FILE *points; //file pointer
    char* point_file; //pointer to the string containing the file with the points

    //Get the file name
    if (argc > 1) {
      point_file = malloc(strlen(argv[1])*sizeof(char));
      strcpy(point_file, argv[1]);
    } else {
      point_file = malloc(strlen("point_list.txt") * sizeof(char));
      strcpy(point_file, "point_list.txt");
    }

    //open the file.
    points = fopen(point_file, "r");
    free(point_file);
    if (points == NULL) {
      exit(EXIT_FAILURE);
    }


   /*Loop through the file and extract each line */

   //Set up variables to loop through the file
    size_t len = 0;
    ssize_t the_size;
    char * line;
    line = malloc(10000 * sizeof(char)); //will contain each line
    List* line_list; //linked list pointer
    line_list = make_list(); //initialize the linked list for the loop to use.
    int counter = 0; //the counter for the linked list to use to add lines to the list

    //Now loop through the file and extract each line
    while ((the_size = getline(&line, &len, points)) != -1) {
      add_to_list(line_list, counter, line); //add the line to the linked list
      free(line); //free the pointer to the line
      line = malloc(10000*sizeof(char)); //reinitialize the pointer to the line
      counter = counter + 1;   //increment the counter by 1.
    }
    free(line); //free the line pointer



    //now create our array of segments by looping through the linked list
    //and creating line segments out of each line
    Segment segment_list[line_list->size]; //the array of line segments
    for (int i=0; i < line_list->size; i++) { //For each line
      char* our_line = get(line_list, i);  //extract the line
      segment_list[i] = line_to_seg(our_line);  //convert the line into a line segment.
    }

   //Now determine how many pairs of segments intersect by looping through the array
    int intersect_count = 0;
    //For each index of the line segment array
    for (int j=0; j < line_list->size; j++) {
      //loop through the subsequent indexex
      for (int k=j; k < line_list->size; k++) {
          //determine whether the line segments intersect and if so add 1 to the count.
          intersect_count = intersect_count + (intersect(&segment_list[j], &segment_list[k]) && (j != k));
      }
    }

    //print out the number of intersection
    printf("%d pairs of line segments intersect\n", intersect_count);

}
