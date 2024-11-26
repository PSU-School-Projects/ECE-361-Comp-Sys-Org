/**
 * @file 		test_colors.c
 *
 * @author 		ECE 361 Fall 2024 students
 * @date 		25-Oct-2024
 *
 * @brief 		This program utilizes functions to; 
 *					o Create an RGB struct from given Red, Blue, and Green values
 *					o Determine an individual color value from a given RGB struct
 *					o Compare two RGB color structs
 *					o Display all colors of an RGB struct
 *					
**/
#include <stdio.h>
#include "colors.h"

int main() {
	//initialize test colors
    int R = 1, G = 11, B = 111;

    //uses makeColor function to create new color
    color_t testColor = makeColor(R, G, B);

    //uses getColor function to print the green value of the test color
    G = getColor(GREEN, testColor);
    printf("\nHint: The green value of the test color is %d.\n", G);

    //uses makeColor function and user input to create new color
    printf("Please guess the test color's red, green, and blue values:  ");
    scanf("%d %d %d", &R, &G, &B);

    color_t usersColor = makeColor(R, G, B);

    //uses equalColor function to determine if both colors are identical
    if (equalColor(testColor, usersColor))
        printf("You are correct.\n");
    else
        printf("You are incorrect.\n");

    //uses printColor function to print out the RGB values of the test color
    printf("The RGB values of the test color are:  ");
    printColor(testColor);

    return 0;
}