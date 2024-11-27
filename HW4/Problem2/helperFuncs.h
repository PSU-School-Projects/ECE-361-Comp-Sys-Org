#ifndef _HELPER_FUNCS_H
#define _HELPER_FUNCS_H

#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include <errno.h>
#include "../libs/stackADT_LL/stackADT_LL.h"


/**
 * @brief Takes in a C string and removes all the spaces
 * taken from the example here: https://stackoverflow.com/questions/1726302/remove-spaces-from-a-string-in-c 
 *
 *
 * @param s a pointer to the string to be operated on
 */
void remove_spaces(char* s);

/**
 * @brief takes in a RPN expression and prints the result of the expression
 * to the console. Returns false if the expression is not in reverse polish notation
 *
 * @param expr the RPN expression
 * 
 * @return `bool`
 */
bool parseRPN(char expr[]);

#endif