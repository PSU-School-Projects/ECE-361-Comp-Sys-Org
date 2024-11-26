/**
 * @file linkedList.h
 *
 * @version 1.0.1
 * @author Roy Kravitz (roy.kravitz@pdx.edu)
 * @date   08-Nov-2024
 * 
 * @brief
 * This is the header file for a Linked list ADT that
 * implements a pointer-based singly linked list
 *
 * @details
 * Revision History
 * ----------------
 *	1.0.1	(10-Nov-2024)	Modified to use the ll_data_t alias for the linked list data type
 *	1.0.0	(07-Nov-2022)	Initial version
 *
 * @note Code is based on SinglyLinkedList.c from Narasimha Karumanchi
 * Data Structures and Algorithms Made Easy, Career Monk Publishers, 2016
 *
 * @note The data in this implementation can be changed by redefining the ll_data_t
 */

#ifndef _LINKEDLIST_H_
#define _LINKEDLIST_H_

// include required header files
#include <stddef.h>
#include <stdint.h>
#include <limits.h> 
#include <malloc.h>

/**
 * @typedef ll_data
 * @brief Defines the data type for a linked list node
 */
typedef int16_t		ll_data_t;  // makes ll_data_t an alias for int16_t
#define LL_DATA_MAX (INT16_MAX);

/**
 * @struct listNode
 * @brief Struct for a node on the linked list
 */
typedef struct listNode {
	ll_data_t data;			// data for the node
	struct listNode *next;	// next pointer for the node
} listNode_t, *listNodePtr_t;

// define the struct that contains an instance of the Linked List
/**
 * @struct linkedList
 * @brief Struct for the linked list
 */
typedef struct linkedList {
	listNodePtr_t head;		// pointer to the head node of the list
	int count;				// number of elements on the list
} linkedList_t, *linkedListPtr_t;


// function prototypes
/**
 * @brief Creates a new instance of the Linked List
 * @return Pointer to the new Linked List instance if it succeeds.  NULL if it fails
 */
linkedListPtr_t createLList(void);

/**
 * @brief Returns the number of items in the list
 * @param L is a Pointer to a LinkedList instance
 * @return	Returns the number of nodes in the Linked List
 */
int LListLength(linkedListPtr_t L);

/**
 * @brief Inserts a new node into the linked list
 * @param L is a Pointer to a LinkedList instance
 * @param data is the data item to put into the new node
 * @param pos is the position in the list to insert the item
 *
 * @returns	void
 */
void insertNodeInLList(linkedListPtr_t L, ll_data_t data, int pos);

/**
 * @brief Returns the data from a selected node
 * @param L is a Pointer to a LinkedList instance
 * @param pos is the position in the list to insert the item
 * @return	the data from the selected node
 */
ll_data_t getNodeDataInLList(linkedListPtr_t L, int pos);

/**
 * @brief Removes the node at pos from the linked list
 * @param L is a pointer to a LinkedList instance
 * @param pos is the position in the list of the node to delete
 * @return	void
 */
void deleteNodeFromLLinkedList(linkedListPtr_t L, int pos);

/**
 * @brief Prints all of the data items in the Linked List
 * @param L is a Pointer to a LinkedList instance
 * @return	void
 */
void printLList(linkedListPtr_t L);

/**
 * @brief Deletes all of the nodes in the linked list and then the LinkedList instance
 * @param L is a Pointer to a LinkedList instance
 * @return	void
 */
void deleteLList(linkedListPtr_t L);
  
#endif