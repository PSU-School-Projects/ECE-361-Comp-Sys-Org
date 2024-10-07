/*****
 * prob3_starter.c - starter code for nursery rhyme counter
 * 
 * @author: <Your Name> (<Your email)
 * @date:   <Creation date>
 * 
 * This program counts things like in the "one little indian" nursery-rhyme. 
 */
 
// header files go here
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
 
// contants, typedefs, global variables, etc. go here
#define MAXTHINGS  10 
 
char thing[] = "spider";    // the thing we're counting 
 
// function prototypes go here

 
/********** main() **********/
int main() {
	// greet the user and display the working directory for the application
    // this code should be included in all of the applications you submit for ECE 361
    printf("TODO: ADD YOUR GREETING MESSAGE\n");
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
	
	// TODO: REPLACE THIS CODE WITH YOUR IMPLEMENTATION
    for (int i = 1; i <= MAXTHINGS; i++) {
	
		if (i == MAXTHINGS)
            printf("%2d little %s bugs\n", i, thing);
        else if (i % 3 == 0)
            printf("%2d little %ss\n", i, thing);
        else
            printf (" %2d little,", i);
	}
	return 0;
}
 
 /***** helper functions *****/
 
 // PUT ADDITIONAL FUNCTIONS HERE
 