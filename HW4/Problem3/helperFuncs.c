#include "helperFuncs.h"
#include <stdio.h>

/**
 * @brief Inserts a value into a presorted array without breaking the sorting order
 *
 * @param val the value to be inserted
 * @param arr a pointer to the array that the value will be inserted into
 * @param size the size of the array
 */
void sortedInsert(float val, float* arr, int size) {
    int i = size - 1;
    while (i >= 0 && arr[i] > val) {
        // Shift elements up
        arr[i+1] = arr[i];
        i--;
    }
    arr[i+1] = val;
}

/**
 * @brief calculate the average of the values in an array
 *
 * @param arr a pointer to the array that the value will be inserted into
 * @param size the size of the array
 */
float calculateAverage(float* arr, int size) {
    float sum = 0.0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum / size;
}