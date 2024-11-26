/**
 * @file test_stackADT_LL.c - Source code for program to test the stack ADT
 *
 * @version 1.0.1
 * @author Roy Kravitz (roy.kravitz@pdx.edu)
 * @date   10-Nov-2024
 *
 * @details
 * This is the a test program for the refactored Karumanchi's linked
 * list stack ADT that I implemented.  You may find it useful for
 * testing your stack ADT implementation. 
 *
 * You do not need to execute this or submit results.  It's yours to use/modify if you want too.
 *
 * Revision History
 * ----------------
 *	1.0.1	(10-Nov-2024)	Modified to use version 1.0.1 of the Linked List ADT
 *	1.0.0	(07-Nov-2022)	Initial version
 *
 * @note Stack code is based on Roy's Linked List ADT
 */
 
// include files
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <unistd.h>
#include <errno.h>
#include "stackADT_LL.h"

int main(){
    int i = 0;
    llStackPtr_t stk = createStack();
    
    // display a greeting and the current working directory
    printf("Minimal test program for the stack ADT by Roy Kravitz (roy.kravitz@pdx.edu)\n");
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
    printf("\n\n");

    for(i = 0; i <= 10; i++){
        push(stk, i);
    }

    printf("Top element is %d\n", peek(stk));
    printf("Stack size is %d\n", size(stk));
	printStackElements(stk, -1);

	printf("Top two elements on the stack are:\n");
	
	printStackElements(stk, 2);
    for (i = 0; i <= 10; i++){
        printf("Popped element is %d\n", pop(stk));
    }

    if (isEmpty(stk))
        printf("Stack is empty");
    else {
        printf("Stack is not empty");
		printStackElements(stk, size(stk));
	}

    deleteStack(stk);
    return 0;
 }
