#ifndef _HELPER_FUNCS_H
#define _HELPER_FUNCS_H

#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include <errno.h>
#include <stdio.h>
#include <time.h>

#include "helperFuncs.h"

#define MAX_DATE_STR_SIZE 11

/**
 * @brief parse a date string (mm/dd/yyyy or mm-dd-yyyy)
 *
 * @param date_str a char pointer to the date string
 * @param month an int pointer to the variable the month will be stored in
 * @param day an int pointer to the variable the day will be stored in
 * @param year an int pointer to the variable the year will be stored in
 */
int parse_date(const char *date_str, int *month, int *day, int *year);

/**
 * @brief converts an epoch timestamp to a date string in mm/dd/yyyy format
 *
 * @param date_str a char pointer to the date string
 */
void epoch_to_date(time_t epoch_time, char *date_str);

/**
 * @brief converts an epoch timestamp to a date string in mm/dd/yyyy format
 *
 * @param date_str a char pointer to the date string
 */
void epoch_to_date(time_t epoch_time, char *date_str);

#endif