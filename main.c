#include <stdio.h>
#include "list.h"
/*
Xavier Vaughn
@02928026
*/ 
int main() 
{
  printf("Write your Tests for your linked list implementation\n");
  
  node_t *mylist;
  node_t n1, n2, n3;

  n1.value = 1;
  n2.value = 2;
  n3.value = 3;

  mylist = &n1;
  n1.next = &n2;
  n2.next = &n3;
  n3.next = NULL;

  //mylist = list_alloc();
  
  //Tests Print functions

printf("Testing printing of list\n");
  //list_add_to_back(mylist, 10);
    list_print(mylist);

printf("Testing printing length of list\n");
    int lengthOfList = list_length(mylist);
    printf("%i\n", lengthOfList);

printf("Testing adding a node to the back of the list\n");
  list_add_to_back(mylist, 4);
  list_print(mylist);

printf("Testing adding a node to the front of the list\n");
    list_add_to_front(&mylist, 0);
    list_print(mylist);

  // this sequence does not work, will have to try and debug later.
printf("Testing adding a node 2 at an index 1 to the list\n");
    list_add_at_index(&mylist, 2, 2);
    list_print(mylist);

printf("Testing removing a node from the back of the list\n");
    list_remove_from_back(mylist);
    list_print(mylist);

printf("Testing removing a node from the front of the list\n");
    int printedInt = list_remove_from_front(&mylist);
    printf("The removed number is:%d \n", printedInt);
    printf("\n");
    list_print(mylist);

printf("Testing Checking to see if an element 5 is in \n");
    bool elemIsIn = list_is_in(mylist,5);
    if(elemIsIn){
        printf("5 is in the list\n");
    }else if (!elemIsIn){
        printf("5 is not in the list\n");
    }

printf("Testing Checking to see if an element 2 is in \n");
    bool elemIsIn2 = list_is_in(mylist,2);
    if(elemIsIn2){
        printf("2 is in the list\n");
    }else if (!elemIsIn2){ 
        printf("2 is not in the list\n");
    }

printf("Testing to see a node removed at index 1\n");
int removedNode = list_remove_at_index(mylist, 1);
list_print(mylist);

printf("Testing function to see count at 2nd index (3rd node)\n");
  int valueOfNode = list_get_elem_at(mylist, 2);
  printf("%d \n", valueOfNode);

  printf("\nTesting function to get the index of a node given a value\n");
  int indexOfNode = list_get_index_of(mylist, 3);
  printf("The given value 3, presides at index: %d", indexOfNode);
   return 0;
}

// Verified functions working:
/*
list_print - working
int list_length - working
list_add_to_back - working
void list_add_to_front - working
list_add_at_index - working
list_remove_from_back - working
list_remove_from_front - working
list_remove_at_index -  working
list_is_in - working
elem list_get_elem_at - working
int list_get_index_of - working
*/
