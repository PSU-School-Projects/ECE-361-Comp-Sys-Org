/**
 *  @author: Jeremiah Vandagrift (j.c.vandagrift@gmail.com)
 *  @date:   10-Oct-2024
 *
 *  @brief: A program that decrypts BIFF speak
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <stdbool.h> 

#include "helperFuncs.h"
#include "../libs/lineHelper.h"

#define MAX_LENGTH 100

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
    "If you're looking to run HW2 you've come to the right place.\n"
    "Lets begin!\n");
    /*********END of Greeting**********/

    bool exit = false;
    do {
        char str[MAX_LENGTH];
        printf("\nInput BIFF message:\n");
        getaLine(str, MAX_LENGTH);
        if (str[0] == '\n' || str[0] == EOF || strlen(str) == 0) {
            printf("No (more) content received.\n\"Gracefully\" exiting...\n");
            exit = true; 
        }
        else {
            char trans_str[MAX_LENGTH];
            BIFF_translate(str, trans_str);
            printf("BIFF Message: %sTranslation: %s", str, trans_str);
        }
    } while (!exit);

    return 0;
}