/**
 * @file linkedList.c
 *
 * @version 1.0.1
 * @author Roy Kravitz (roy.kravitz@pdx.edu)
 * @date   10-Nov-2024
 *
 * @brief 
 * This is the source code file for a Linked List ADT that
 * implements a singly linked list.  I've tried to define the
 * API in a way that we can change implementations but keep
 * the API the same
 *
 * @details
 * Revision History
 * ----------------
 *	1.0.1	(10-Nov-2024)	Modified to use the ll_data_t alias for the linked list data type
 *	1.0.0	(07-Nov-2022)	Initial version
 *
 * @note Code is based on DynamicStack.c from Narasimha Karumanchi
 * Data Structures and Algorithms Made Easy, Career Monk Publishers, 2016
 *
 * @note Prints messages to stdout.  This is Karumanchi's doing, not mine
 */

#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"

/***** API functions *****/

// creates a new instance of the linked list
linkedListPtr_t createLList(void) {
	linkedListPtr_t L = malloc(sizeof(linkedList_t));
	if(L == NULL){
        printf("ERROR: LinkedList ADT(createLList): Could not create Linked List\n");
		return NULL;
    }
    
	L->head = NULL;
	L->count = 0;
	return L;
}


// returns the number of nodes in the linked list
int LListLength(linkedListPtr_t L){
    if (L == NULL) {
        printf("ERROR: LinkedList ADT(LListLength): Linked List does not exist\n");
		return 0;
    }        
	return L->count;
}


// returns the data from the listNode at pos
ll_data_t getNodeDataInLList(linkedListPtr_t L, int pos) {
    listNodePtr_t p = L->head;
    int k = 1;

	if(p == NULL){
		printf("ERROR: LinkedList ADT(getNodeDataInLList): List Empty\n");
		return LL_DATA_MAX;
	}
	else if(pos == 1){
        return p->data;
	}
	else {
		while((p != NULL) && (k < pos)){
			k++;			
			p = p->next;
		}
		if(p == NULL){
			printf("ERROR: LinkedList ADT(getNodeDataInLList): Position %d is not in the list\n", pos);
            return LL_DATA_MAX;
		}
		else{
			return p->data;
		}
	}
}


// inserts a new listNode with data at pos in the linked list
void insertNodeInLList(linkedListPtr_t L, ll_data_t data, int pos){
	listNodePtr_t head = L->head;
	listNodePtr_t q, p;
	listNodePtr_t newNode = malloc(sizeof(listNode_t));		
	int k = 1;
    
    if (L == NULL) {
        printf("ERROR: LinkedList ADT(insertNodeInLList): Linked List does not exist\n");
		return;
    }
	
	if(!newNode){
		printf("ERROR: LinkedList ADT(insertNodeInLList): Could not create new node\n");
		return;
	}
	newNode->data = data;
	p = head;
	if ((pos == 1) || (p == NULL)){
		newNode->next = head;
		L->head = newNode;
		L->count++;
	}
	else {
		while((p != NULL) && (k < pos)){
			k++;
			q = p;
			p = p->next;
		}
		newNode->next = q->next;
		q->next = newNode;
		L->count++;
	}
}

// deletes the node at pos in the linked list
void deleteNodeFromLLinkedList(linkedListPtr_t L, int pos) {
	listNodePtr_t head = L->head;
	listNodePtr_t q, p;	
	int k = 1;
    
    if (L == NULL) {
        printf("ERROR: LinkedList ADT(deleteNodeFromLLinkedList): Linked List does not exist\n");
		return;
    }   
	
	p = head;
	if(head == NULL){
		printf("LinkedList ADT(deleteNodeFromLLinkedList): List Empty\n");
		return;
	}
	else if( pos == 1){
		L->head = head->next;
		free(p);
		L->count--;
	}
	else {
		while((p!=NULL) && (k < pos)){
			k++;
			q = p;
			p = p->next;
		}
		if(p == NULL){
			printf("LinkedList ADT(deleteNodeFromLLinkedList): Position does not exist\n");
		}
		else{
			q->next = p->next;
			free(p);
			L->count--;
		}

	}
}

// prints (displays) all of the nodes in the linked list
void printLList(linkedListPtr_t L) {	
	listNodePtr_t p = L->head;

    if (L == NULL) {
        printf("ERROR: LinkedList ADT(printLList): Linked List does not exist\n");
		return;
    }
	
	while(p != NULL){
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}

// deletes all of the nodes in the linked list and the linked list instance
void deleteLList(linkedListPtr_t L) {
    listNodePtr_t p = L->head, temp = NULL;
    
    if (L == NULL) {
        printf("ERROR: LinkedList ADT(deleteLList): Linked List does not exist\n");
		return;
    }
	
	while(p != NULL){
        // delete the node and move on until end of list
        temp = p;
        p = p->next;
        free(temp);
	}
    // free the LinkedLlist instance
	free(L);
}


