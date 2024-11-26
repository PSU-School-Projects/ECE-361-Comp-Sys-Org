/**
 * @file stackADT_LL.c
 *
 * @version <your version>
 * @author <your name> (<your email address>)
 * @date   <date>
 *
 * @brief
 * Source code for linked list-based stack. This stack is based on Roy's Linked List ADT.
 *
 * @details
 * Revision History
 * ----------------
 *	1.0.1	(10-Nov-2024)	Modified to use version 1.0.1 of the Linked List ADT
 *	1.0.0	(07-Nov-2022)	Initial version
 *
 * @note The Linked List ADT does most of the "heavy lifting"
 *  This ADT is more of a wrapper around the Linked List ADT that
 *  implements specific functionality
 */
 
// include files
#include <stdio.h>
#include <stdlib.h>
#include "stackADT_LL.h"

/***** API functions *****/

// creates a new stack instance
llStackPtr_t createStack() {
    //TODO:  Implement your functionality
}


// pushes data onto the stack
void push(llStackPtr_t stk, ll_data_t data){
    // TODO: implement your functionality
}


// returns the number of valid elements in the linked list
int size(llStackPtr_t stk){
    //TODO:  implement your functionality
}


// returns true if the stack is empty, false otherwise
bool isEmpty(llStackPtr_t stk) {
    //TODO:  implement your functionality
}


// returns and removes the top element of the stack
ll_data_t pop(llStackPtr_t stk){ 
   //TODO:  implement your functionality
}


// returns the top element of the stack but does not pop the element off the stack
ll_data_t peek(llStackPtr_t stk){
    //TODO:  implement your functionality
}

// deletes the linked list that implements the stack and the stack instance
void deleteStack(llStackPtr_t stk){
    //TODO:  implement your functionality
 }


// FREEBIE - prints (displays) n elements on the stack
// {Editor's note]  This function turned out to be useful
 void printStackElements(llStackPtr_t stk, int n) {
	 int maxPos = 0;
	 
	 if (isEmpty(stk)) {
		 printf("INFO[printStackElements]: stack is empty\n");
		 return;
	 }
	 
	 maxPos = (n < 0) ? size(stk) : n;
	 printf("stack[1..%d]: ", maxPos);
	 for (int pos = 1; pos < maxPos; pos++) {
		 printf("%d <= ", getNodeDataInLList(stk->top, pos));
	 }
	 printf("%d\n", getNodeDataInLList(stk->top, maxPos));
 }



 