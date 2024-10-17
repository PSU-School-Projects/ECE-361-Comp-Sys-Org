/*****
 * prob3_starter.c - starter code for nursery rhyme counter
 * 
 * @author: <Jeremiah Vandagrift> (j.c.c.vandagrift@gmail.com)
 * @date:   <10-12-2024>
 * 
 * This program counts things like in the "one little indian" nursery-rhyme. 
 */
 
// header files go here
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

#include "HW1-JeremiahV.h"
 
// contants, typedefs, global variables, etc. go here
#define MAXTHINGS  10
#define MINTHINGS 1
 
char thing[] = "spider";    // the thing we're counting 
 
// function prototypes go here

 
/********** main() **********/
int main() {
	// greet the user and display the working directory for the application
    // this code should be included in all of the applications you submit for ECE 361
    errno = 0;
    char *buf = getcwd(NULL, 0);    // allocates a buffer large enough to hold the path
    
    if (buf == NULL) {
        printf("ERROR (main): Could not display the path\n");
    }
    else {
        printf("\nCurrent working directory: %s\n", buf);
        free(buf);
    }

    printf("\nGreatings traveler. . .\n"
    "If you're looking to run HW1 you've come to the right place.\n");

    printf("Lets begin!\n");

    for (int i = 1; i <= MAXTHINGS; i++) {
	
		if (i == MAXTHINGS)
            printf("\n%s little %s bugs\n", getNumStrName(i), thing);
        else if (i % 3 == 0)
            printf(" %s little %ss\n", getNumStrName(i), thing);
        else
            printf (" %s little,", getNumStrName(i));
	}

    printf("\n\n");

    for (int i = 10; i >= MINTHINGS; i--) {
	
		if (i == MINTHINGS)
            printf("\n%s little %s bugs\n", getNumStrName(i), thing);
        else if (i % 3 == 2)
            printf(" %s little %ss\n", getNumStrName(i), thing);
        else
            printf (" %s little,", getNumStrName(i));
	}
	return 0;
}
 