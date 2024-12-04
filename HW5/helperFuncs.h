#ifndef _HELPER_FUNCS_H
#define _HELPER_FUNCS_H

#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include <errno.h>
#include <stdio.h>
#include <time.h>

#include "./libs/iom361_r2/iom361_r2.h"
#include "./libs/BST.h"

#define MAX_DATE_STR_SIZE 12
#define TEMP_RANGE_LOW	32.2
#define TEMP_RANGE_HI	65.5
#define HUMID_RANGE_LOW	72.2
#define HUMID_RANGE_HI	88.8

// forward declaration to allow BST to work in prototypes without defining in this file
struct BST;

/**
 * @brief Given a date, populates the passed in BST with the next 30 days
 * of temperature and humidity data
 *
 * @param date a char pointer to the date string
 * @param tree a pointer to the binary search tree that the data will be stored in
 * @param io_base the iom module address
 */
void populateBST(const char* date, struct BST* tree, int numDays, uint32_t* io_base);

/**
 * @brief parse a date string (mm/dd/yyyy or mm-dd-yyyy)
 *
 * @param date a char pointer to the date string
 * @param month an int pointer to the variable the month will be stored in
 * @param day an int pointer to the variable the day will be stored in
 * @param year an int pointer to the variable the year will be stored in
 */
int parse_date(const char *date, int *month, int *day, int *year);

/**
 * @brief converts a date string to epoch timestamp
 *
 * @param date a char pointer to the date string
 */
time_t date_to_epoch(const char *date);

/**
 * @brief converts an epoch timestamp to a date string in mm/dd/yyyy format
 *
 * @param date a char pointer to the date string
 */
void epoch_to_date(time_t epoch_time, char *date);

/**
 * @brief converts an epoch timestamp to a date string in mm/dd/yyyy format
 *
 * @param date a char pointer to the date string
 */
void epoch_to_date(time_t epoch_time, char *date);

/**
 * @brief takes in an epoch timestamp and packages it together with randomly generated
 * temperature and humidity data into a temp_humid_data struct
 *
 * @param timestamp the timestamp to gather data for
 */
struct temp_humid_data get_node_data(time_t timestamp, uint32_t* io_base);

#endif //_HELPER_FUNCS_H