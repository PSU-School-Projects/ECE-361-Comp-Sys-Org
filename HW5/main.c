/**
 * main.c source file
 *
 * @file:		main.c
 * @author:		Jeremiah Vandagrift (jcv3@pdx.edu)
 * @date:		04-Dec-2023
 * @version:	1.0
 */

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <unistd.h>
#include <errno.h>

#include "helperFuncs.h"
#include "./libs/lineHelper.h"
#include "./libs/iom361_r2/iom361_r2.h"


#define TEMP_RANGE_LOW	32.2
#define TEMP_RANGE_HI	65.5
#define HUMID_RANGE_LOW	72.2
#define HUMID_RANGE_HI	88.8
#define NUM_DAYS 31

uint32_t* io_base;

int main() {
    int rtn_code;
    bool exit = false;
    bool abort = false;
    bool populated = false;
    struct node* query = NULL;
    
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

    printf("\nGreetings traveler. . .\n"
    "If you're looking for ECE 361 HW5, the temperature and humidity logger, you've come to the right place.\n"
    "Lets begin!\n\n");
    /*********END of Greeting**********/
	 
	printf("Initializing the I/O registers...\n");
    sleep(1);
	io_base = iom361_initialize(16, 16, &rtn_code);
	if (rtn_code != 0) {
		// initialization failed
		printf("Could not initialize I/O module\n");
		return 1;
	}
	printf("Successfully Initialized\n");


    printf("Initializing BST...\n");  
	struct BST* bst = createBST();
    printf("Successfully Initialized\n");
    
    printf("\nInput a start date to populate a month worth of data from: ");
    char start_str[MAX_DATE_STR_SIZE];
    getaLine(start_str, MAX_DATE_STR_SIZE);
    if (date_to_epoch(start_str) != -1) {
        printf("\nEvenly populating binary search tree...");
        populateBST(start_str, bst, NUM_DAYS, io_base);
        populated = true;
    }
    else {
        printf("Aborting...\n");
        exit = abort = true;
        return 1;
    } 

    while (!exit) {
        char str[MAX_DATE_STR_SIZE];
        printf("\nInput a date to look up the temperature and humidty for: ");
        getaLine(str, MAX_DATE_STR_SIZE);
        if (strlen(str) == 0 || str[0] == '\n' || str[0] == EOF) {
            printf("No (more) content received.\nDisplaying full tree contents before \"gracefully\" exiting...");
            exit = true; 
        }
        else {
            time_t time = date_to_epoch(str);
            
            if (time == -1) {
                fprintf(stderr, "ERROR[main.c] Bad date provided, exiting...");
                exit = abort = true;
            }
            else query = bst->search(bst->root, time);
        }
    };

    if (populated && !abort) bst->displayTree(bst->root);

    return 0;
}
 
