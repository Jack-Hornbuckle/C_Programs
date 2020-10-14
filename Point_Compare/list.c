#include <stdlib.h>
#include "list.h"
#include <stdio.h>
#include <string.h>

Node* make_node(char* data, Node* next){
	
	Node* assign_node; //create a temporary node that we will use for our return value
	assign_node = calloc(1, sizeof(Node*)); //allocate memory for a node
  assign_node->item = malloc(strlen(data)*sizeof(char));
	strcpy(assign_node->item, data); //assign the  node's item to data
	assign_node->next = next; //assign the node's following Node to next.
	return assign_node;
}

List* make_list(){
  List* assign_list;
	assign_list = calloc(1, sizeof(struct List*)); //allocate memory for the new list
	assign_list->head = NULL; //set its head to null
	assign_list->size = 0; //set its size to 0
	return assign_list; //return  the base list.
}

void free_node(Node* node){

  free(node->item); //free the nodes item as it is a separate data type
	node->item = NULL; //clarify that the item is now NULL
	free(node); //free the memory of the node itself
	node = NULL; //set the node to null.
	return;
}

//frees an entire linked list
void free_list(List* list) {

  Node* free_iter = list->head; //the node we use to loop through the linked list
	while(free_iter != NULL) { //while free_iter is not NULL
		  Node* prev = free_iter; //save the current iteration so we can move to the next iteration while freeing the current one.
			free_iter = free_iter->next; //increment free_iter to the next iteration
			free_node(prev); //free the previous iteration before we move on to the next one.
	}
	free(list); //now free the list itself
	return;
}

//add an item to the linked list
void add_to_list(List* list, int index, char* data) {

	Node* nuller = NULL; //a null node to be assigned as a Node's following node
  Node* newest = make_node(data, nuller); //create the newest node.
	if (index == 0) { //if we are adding to the front of the list
		  if (list->head != NULL) { //if the list is not empty
		      Node* temp_head = list->head; //save the head
		      newest->next = temp_head; //set the head to come after the newest node
			    list->head = newest; //set the head to be the newest node
					list->size = list->size + 1; //increment the size by 1 indicating that we added a new node
			    return;
			} else { //if the list is empty
				  list->head = newest; //set the head to be the newest node
					list->size = list->size + 1; //increment the size by 1.
					return;
			}
	}
	//if we are adding to the middle or end of the list
  Node* iterator = list->head; //iterator node to loop through the list starting with the head
	int inc = 0; //iterator incrementor to tell the program where we are in the linked list
	int placement = index - 1; //when we reach index - 1, we are going to use this variable to add the item
	while (inc != placement) { //loop throught the linked list until we reach placement
		  iterator = iterator->next; //move iterator to the next node
			inc = inc + 1; //increment inc by 1
	}
	Node* temp = iterator->next; //save the current node of the index we are trying to add to
	if (iterator->next != NULL) { //if the index we are trying to add to is not NULL
		  iterator->next = newest; //assign iterator->next to newest
		  iterator->next->next = temp; //assign the node after the index we are adding to to the original node of the index we are trying to add to
	} else {
		  iterator->next = newest; //if the index we are trying to add to is NULL, add the new node to the end of the list
	}
	list->size = list->size + 1; //increment size by 1.
	return;
}

//retrieves the item of a certain index of a linked list
char* get(List* list, int index) {
  Node* getter = list->head; //an iterator to move between nodes as we loop through the list
	int counter = 0; //a counter to loop through the list until we reach index
	while (counter != index){
		  counter = counter + 1; //increment counter and getter
			getter = getter->next;
	}
	return getter->item; //return the item of getter
}

//changes the item of a node of index in the list
void set(List* list, int index, char* data) {


  Node* set_iter = list->head; //our node iterator
	int set_count = 0; //our node counter
	while (set_count != index) { //iterate through the list until we reach our index
		  set_iter = set_iter->next;
			set_count = set_count + 1;
	}
  set_iter->item = malloc(strlen(data)*sizeof(char));
	strcpy(set_iter->item, data); //change the data of the node at our index
	return;
}
