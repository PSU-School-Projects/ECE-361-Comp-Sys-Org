/**
 * @file test_LinkedList.c
 *
 * @version 1.0.1
 * @author Roy Kravitz (roy.kravitz@pdx.edu)
 * @date   10-Nov-2024
 * 
 * @brief
 * This is the source code file for a  test program for a Link List ADT.
 * Although it shouldn't matter as long as the API doesn't change, this
 * test if based on Karumanchi's SinglyLinkedList example.
 *
 * @details
 *	Revision History
 *  ----------------
 *	1.0.1	(10-Nov-2024)	Modified to use the ll_data_t alias for the linked list data type
 *	1.0.0	(07-Nov-2022)	Initial version
 *
 * @note Code is based on DynamicStack.c from Narasimha Karumanchi
 * Data Structures and Algorithms Made Easy, Career Monk Publishers, 2016
 */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include "linkedList.h"

int main(){  
	// display a greeting and the current working directory
    printf("Linked List ADT test program by Roy Kravitz (roy.kravitz@pdx.edu)\n\n");
    errno = 0;
    char *buf = getcwd(NULL, 0);    // allocates a buffer large enough to hold the path
    if (buf == NULL) {
        perror("getcwd");
        printf("Could not display the path\n");
    }
    else {
        printf("Current working directory: %s\n", buf);
        free(buf);
    }
    printf("\n");
	
	// create a Linked List
	linkedListPtr_t LL = createLList();
	printf("Created a new Linked List\n");
	printf("Number of nodes in List: %d\n", LListLength(LL));
		
	// insert a few items in the list
	printf("Inserting 5 and 2 into list...\n");
	insertNodeInLList(LL, 5, 5);
	insertNodeInLList(LL, 2, 5);
    
    // get the data from the nodes
    ll_data_t d1 = getNodeDataInLList(LL, 1); 
    ll_data_t d2 = getNodeDataInLList(LL, 2);
    printf(" Data from the Linked list nodes are:  node(1)= %d, node(2)= %d\n",
        d1, d2);
        
    // get a node that's not in the list.  Watch for error message
    getNodeDataInLList(LL, 3); 
	
	// check that the number of elements is correct
	// and then print them
	printf("Number of nodes in List: %d\n", LListLength(LL));
	printf("List contents: ");
	printLList(LL);
	
	// delete the first item on the list and
	// check the list to make sure it has been removed
	printf("Deleting a node from list...\n");
	deleteNodeFromLLinkedList(LL, 1);
	printf("Number of nodes in List: %d\n", LListLength(LL));
	printf("List contents: ");
	printLList(LL);
    
    //  delete the entire list
    deleteLList(LL);
    if (LL == NULL) {
        printf("The linked list has been deleted\n");
    }
	return 0;
}
