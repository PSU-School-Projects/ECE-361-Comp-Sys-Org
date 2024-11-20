#ifndef _HELPER_FUNCS_H
#define _HELPER_FUNCS_H

#include <ctype.h>
#include <stdbool.h>
#include <string.h>

/**
 * @brief Checks if the two strings are anograms
 *
 * returns true if the anograms and prints a message to console.
 *
 * @param str1 the first string to compare
 * @param str1 the second string to compare
 * 
 * @return bool
 */
bool checkAnagram(char str1[], char str2[]);

/**
 * @brief Checks if the string matches the exit input
 *
 *
 * @param str the string to check
 * 
 * @return bool
 */
bool checkExit(char str[]);

#endif