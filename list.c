// list/list.c
//
// Implementation for linked list.
//
/* 
Xavier Vaughn
@02928026
*/

#include <stdio.h>
#include <stdlib.h>
#include "list.h"


list_t *list_alloc(){
  list_t* list = (list_t*)malloc(sizeof(list_t));
  list->head = NULL;
  return list;
}
//void list_free(list_t *l);
// node_t *node_alloc(){
// }
//void node_free(node_t *n) {}


/* Prints the list in some format. */
void list_print(node_t *head){
  node_t * current = head;
  while (current != NULL){
    printf("%d ", current->value);
    current = current->next;
  }

  printf("\n");
}

/* Returns the length of the list. */

int list_length(node_t *head){
  int length = 0;
  node_t *current = head;
  //struct Node* current = head;
  while (current != NULL){
    length++;
    current = current->next;
  }
  return length;
}


/* Methods for adding to the list. */

void list_add_to_back(node_t *head, elem value){
  node_t * current = head;
  while(current ->next != NULL){
    current = current ->next;
  }
  current->next = (node_t *) malloc(sizeof(node_t));
  current->next->value = value;
  current->next->next = NULL;
}



void list_add_to_front(node_t **head, elem new_value){
  node_t*  new_node;
  new_node = (node_t*) malloc(sizeof(node_t));
  new_node->value = new_value;
  new_node->next = *head;
  *head = new_node;
}


void list_add_at_index(node_t **head, elem value, int index){  // adds to end of list if out of bounds

  while(index--){
    if (index == 0){
      node_t* new_node;
      new_node = (node_t*) malloc(sizeof(node_t));
      new_node->value = value;
      new_node->next = *head; 
      *head = new_node;
    }else{
      head = &(*head)->next;
    }
  }
}

/* Methods for removing from the list. Returns the removed element, or -1 for empty list */

elem list_remove_from_back(node_t *head){
  elem retval = 0;
  if(head->next == NULL){
    retval = head->value;
    free(head);
    return retval;
  }
  node_t *current = head;
  while(current->next->next != NULL){
    current = current->next;
  }

  retval = current->next->value;
  free(current->next);
  current->next = NULL;
  return retval;
}




elem list_remove_from_front(node_t **head){
  node_t *temp = NULL;
  elem tempElem;
  if(head == NULL){
    return -1;
  }
  temp = *head;
  tempElem = temp->value;
  *head = (*head)->next;
  //free(temp);
  return tempElem;
}



elem list_remove_at_index(node_t *head, int index){
  int i = 0;
  elem retval = -1;
  node_t * current = head;
  //node_t * temp_node = NULL;

  if(index == 0){
    printf("\nNode deleted: %d\n", current->value);
    head = head->next;
    current->next = NULL;
    free(current);
  }else{
    for(i = 0; i < index-1; i++){
      if(current->next == NULL){
        return -1;
      }
      current = current->next;
    }

    if(current->next == NULL){
      return -1;
    }

    node_t *temp_node = current->next;
    retval = temp_node->value;
    current->next = current->next->next;
     printf("\nNode deleted: %d\n", temp_node->value);
     temp_node->next = NULL;
    //free(temp_node);
  }
  return retval;
}


/* Checks to see if the given element exists in the list. */
bool list_is_in(node_t *head, elem value){
  node_t *temp = head;
  while (temp != NULL){
      if(temp->value == value){
          return true;
      }
      temp = temp->next;
  }
  return false;

}

/* Returns the element at the given index, or -1 if empty or out of bounds */
elem list_get_elem_at(node_t *head, int index){
  node_t *current = head;
  int count = 0;
  while(current != NULL){
    if(count == index) return(current->value);
    count++;
    current = current->next;
  }

}

/* Returns the index at which the given element appears, or -1 if not found */
int list_get_index_of(node_t *head, elem value){
  node_t *temp = head;
  int index = 0;

  while(temp != NULL){
    if(temp->value == value){
      return index;
    }
    temp = temp->next;
    index++;
  }
  return -1;
}