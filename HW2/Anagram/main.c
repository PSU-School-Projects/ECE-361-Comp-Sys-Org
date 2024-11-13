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
    "If you're looking to run the anagram detector from HW2 you've come to the right place.\n"
    "Lets begin!\n");
    /*********END of Greeting**********/

    bool exit = false;
    do {
        char line1[MAX_LENGTH];
        char line2[MAX_LENGTH];
        printf("\nInput first word: ");
        getaLine(line1, MAX_LENGTH);
        exit = checkExit(line1);
        if (exit) break;

        printf("Input second word: ");
        getaLine(line2, MAX_LENGTH);
        exit = checkExit(line2);
        if (exit) break;
        printf("The words are%sanagrams\n", checkAnagram(line1, line2) ? " " : " not ");
    } while (!exit);

    return 0;
}