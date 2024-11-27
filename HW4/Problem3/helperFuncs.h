#ifndef _HELPER_FUNCS_H
#define _HELPER_FUNCS_H

#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include <errno.h>
#include "../libs/stackADT_LL/stackADT_LL.h"

#include "helperFuncs.h"
#include <stdio.h>

/**
 * @brief Inserts a value into a presorted array without breaking the sorting order
 *
 * @param val the value to be inserted
 * @param arr a pointer to the array that the value will be inserted into
 * @param size the size of the array
 */
void sortedInsert(float val, float* arr, int size);


/**
 * @brief calculate the average of the values in an array
 *
 * @param arr a pointer to the array that the value will be inserted into
 * @param size the size of the array
 */
float calculateAverage(float* arr, int size);

#endif