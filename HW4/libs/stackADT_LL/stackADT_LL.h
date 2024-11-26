/**
 * @file stackADT_LL.h
 *
 * @version 1.0.1
 * @author 	Roy Kravitz (roy.kravitz@pdx.edu)
 * @date 	10-Nov-2024
 *
 * @brief
 * This is the header file for a refactored implementation of Karumanchi's linked
 * list stack ADT
 *
 * @details
 * Revision History
 * ----------------
 *	1.0.1	(10-Nov-2024)	Modified to use version 1.0.1 of the Linked List ADT
 *	1.0.0	(07-Nov-2022)	Initial version
 *
 * @note Code is based on Roy's Linked List ADT
 */

#ifndef _STACKADT_LL_H
#define _STACKADT_LL_H

#include <limits.h> 
#include <stdbool.h> 
#include "linkedList.h"

/**
 * @struct Stack
 * @brief Struct for the stack
 */
typedef struct _stack{
    linkedListPtr_t top;
} llStack_t, *llStackPtr_t;


// API function prototypes

/**
 * @brief Creates a Stack instance
 * @return Pointer to the newly created stack
 */
llStackPtr_t createStack();

/**
 * @brief Pushes a new long onto the stack
 * @param stk is the pointer to the stack instance
 * @param data is the data item to push onto the stack
 * @return	void
 *
 * @details
 * Makes use of the insertNodeInLList() function.  In a stack
 * all new entries are added at the front of the linked list (pos = 1)
 */
void push(llStackPtr_t, ll_data_t data);

/**
 * @brief Returns the number of items on the stack
 * @param stk is the pointer to the stack instance
 * @return	an int containing the number of items on the stack
 *
 * @details
 * Makes use of the LListLength() function which returns the
 * number of nodes in the linked list
 */
int size(llStackPtr_t stk);


/**
 * @brief Returns true if the stack is empty
 * @param stk is the pointer to the stack instance
 * @returns	true if the stack is empty, false otherwise
 *
 * @details
 * Makes use of the LListLength() function which returns the
 * number of nodes in the linked list.  An empty stack is an empty
 * linked list so the number of nodes on the linked list is 0
 */
bool isEmpty(llStackPtr_t stk);

/**
 * @brief pops the top entry from the stack
 * @param stk is the pointer to the stack instance
 * @returns	a ll_data_t containing the data from the top of the stack
 *
 * @details
 * Makes use of the getNodeDataInLList() function.  In a stack
 * entries are returned from the front of the linked list (pos = 1) and
 * then then deleted by using the deleteNodeFromLLinkedList() function in the
 * Linked List ADT
 */
ll_data_t pop(llStackPtr_t stk);

/**
 * @brief returns the top entry on the stack but does not remove it fromt the stack
 * @param stk is the pointer to the stack instance
 * @return	a ll_data_t containing the data from the top of the stack
 *
 * @details 
 * Makes use of the getNodeDataInLList() function.  In a stack
 * entries are returned from the front of the linked list (pos = 1).  Like pop()
 * except the entry is not removed from the linked list
 */
ll_data_t peek(llStackPtr_t stk); 


/**
 * @brief deletes all of the entries on the stack and the stack instance
 * @param stk is the pointer to the stack instance
 * @returns	void
 *
 * @details
 * Makes use of the deleteLList() function from the Linked List ADT
 * to remove the linked list and then frees the stack instance, itself
 */
void deleteStack(llStackPtr_t stk);


/**
 * @brief prints (displays) the values on the stack
 * @param stk is the pointer to the stack instance
 * @param n is the number of items to print. n < 0 for entire stack
 * @return	void
 *
 * @details 
 * Makes use of the getNodeDataInLList() function. to retrieve the data from the nodes
 */
 void printStackElements(llStackPtr_t stk, int n);
		 


#endif