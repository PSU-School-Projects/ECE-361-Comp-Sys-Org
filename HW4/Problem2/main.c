#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <unistd.h>
#include <errno.h>

#include "helperFuncs.h"
#include "../libs/lineHelper.h"
#include "../libs/colors_api/colors.h"
#include "../libs/iom361_r2/iom361_r2.h"


#define MAX_USER_DATA_LEN 50

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
    "If you're looking to run the RPN calculator from HW4 you've come to the right place.\n"
    "Lets begin!\n\n");
    /*********END of Greeting**********/
	 

    bool getInput = true;
    do {
        char userInput[MAX_USER_DATA_LEN];
        printf("\nInput Data: ");
        getaLine(userInput, MAX_USER_DATA_LEN);
        getInput = parseRPN(userInput);
        if (!getInput) {
            printf("No valid expressions received. Exiting program...\n");
        }
    } while (getInput);
    
	return 0;
 }
 
