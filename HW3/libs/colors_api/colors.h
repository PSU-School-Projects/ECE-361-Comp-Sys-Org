/**
* colors.h - Header file for struct example
*
* @author: 	ECE 361 Fall 2024 students
* @date: 	25-Oct-2024
*
* This is the header file for a simple ADT that can be used to create 24-bit color structs and manipulate them.
* These functions use a struct to hold three 8-bit values (red, green and blue) representing a RGB color (24-bit color)
*
*/

#ifndef _COLORS_H
#define _COLORS_H

#include <stdint.h>
#include <stdbool.h>

// The colors
typedef enum {
    RED,
    GREEN,
    BLUE
    } thecolors_t;

// The color struct
typedef struct color {
    uint8_t red;
    uint8_t green;
    uint8_t blue;
} color_t;

// Function prototypes
/**
* makeColor() - returns a populated color_t struct
*
* @param redvalue, greenvalue, bluevalue - The values to initialize the color
*		 struct fields to
* @return the initialized color_t struct
*/
color_t makeColor(uint8_t redvalue, uint8_t greenvalue, uint8_t bluevalue);

/**
* getColor() - gets the value of the specified color
*
* @param thecolors_t whichColor - which color to return
* @param color_t color - the struct to return the colorvalue from
* @return uint8_t value of selected color
*/
uint8_t getColor(thecolors_t whichColor, color_t color);

/**
* equalColor() - compares two color_t structs to see the they are equal
*
* @param color_t color1, color2 - the two colors to compare
* @return true if the colors are equal, false otherwise
*/
bool equalColor(color_t color1, color_t color2);

/**
* printColor() - prints the colors in a color_t
*
* @param c - the color struct to print
* @return void
*/
void printColor(color_t color);

uint32_t makeRGBLedReg(color_t s, bool enable);

 
#endif