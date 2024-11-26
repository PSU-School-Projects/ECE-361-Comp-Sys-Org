/**
 * @file 		colors.c
 *
 * @author 		ECE 361 Fall 2024 students
 * @date 		25-Oct-2024
 *
 * @brief 		This is the source code for the colors API we developed in class
 * The API has functions to make a color struct, get individual colors, and display
 * the contents of a color struct. 
 *					
**/

#include <stdio.h>
#include "colors.h"

color_t makeColor(uint8_t redvalue, uint8_t greenvalue, uint8_t bluevalue) {
    color_t newColor = {redvalue, greenvalue, bluevalue};
    return newColor;
}

uint8_t getColor(thecolors_t whichColor, color_t color) {
    if (whichColor == RED)
        return color.red;
    else if (whichColor == GREEN)
        return color.green;
    else
        return color.blue;
}

bool equalColor(color_t color1, color_t color2) {
    if (color1.red == color2.red &&
        color1.green == color2.green &&
        color1.blue == color2.blue)
        return true;
    else
        return false;
}

void printColor(color_t color) {
    printf("%d, %d, %d\n", color.red, color.green, color.blue);
}

uint32_t makeRGBLedReg(color_t s, bool enable) {
    uint32_t RGB_LED_REG = 0;
    RGB_LED_REG |= (s.blue & 0xFF) << 0;              // Blue occupies bits 0-7
    RGB_LED_REG |= (s.green & 0xFF) << 8;             // Green occupies bits 8-15
    RGB_LED_REG |= (s.red & 0xFF) << 16;              // Red occupies bits 16-23
    RGB_LED_REG |= ((enable ? 1 : 0) & 0x01) << 31;   // Enable bit occupies bit 31

    return RGB_LED_REG;;
}


