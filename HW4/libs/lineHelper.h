/**
 * lineHelper.h - Header file for the helper functions for lineHelper
 *
 * @author:     Roy Kravitz (roy.kravitz@pdx.edu)
 * @date:       12-Oct-2024
 * @version:    2
 *
 * Based on longestLine.c (as implemented by profroyk) from K & R Chapter 1
 *
 */

#ifndef _LINEHELPER_H
#define _LINEHELPER_H

// define constants
#define MAXLINE 1000    // maximum input line length (no error checking)

// no global variables in this implementation

// function prototypes
/**
  * getaLine() - read a line into s, return length
  * 
  * @param  s[]     The character array holding the line
  * @param lim     The maximum number of characters read
  *
  * @return The length of the line or 0 if EOF or an empty line
  */
 int getaLine(char s[],int lim);
 
/**
 * copyLine() - copy 'from' into 'to'.  Assume to is big enough
 *
 * @param   from    character array to copy from
 * @param   to      character array to copy to 
 *
 * @note:  WARNING - There is no bounds checking so make sure to[] is large enough
 */
 void copyLine(char to[], char from[]);
 
 #endif
