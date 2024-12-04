/**
 * helperFuncs.c source file
 *
 * @file:		helperFuncs.c
 * @author:		Jeremiah Vandagrift (jcv3@pdx.edu)
 * @date:		04-Dec-2023
 * @version:	1.0
 */

#include "helperFuncs.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

/**
 * @brief parse a date string (mm/dd/yyyy or mm-dd-yyyy)
 *
 * @param date a char pointer to the date string
 * @param month an int pointer to the variable the month will be stored in
 * @param day an int pointer to the variable the day will be stored in
 * @param year an int pointer to the variable the year will be stored in
 */
int parse_date(const char *date, int *month, int *day, int *year) {
    char delimiter;
    if (strchr(date, '/') != NULL) {
        delimiter = '/';
    } 
    else if (strchr(date, '-') != NULL) {
        delimiter = '-';
    } 
    else {
        // bad string format
        return 0; 
    }
    // Parse the date string
    if (sscanf(date, "%d%c%d%c%d", month, &delimiter, day, &delimiter, year) != 5) {
        // Failed to parse
        return 0; 
    }
    // Successfully parsed
    return 1;
}

/**
 * @brief converts a date string to epoch timestamp
 *
 * @param date a char pointer to the date string
 */
time_t date_to_epoch(const char *date) {
    int month, day, year;
    struct tm time = {0};

    // Parse the date string
    if (!parse_date(date, &month, &day, &year)) {
        fprintf(stderr, "Invalid date format: %s\n", date);
        return -1;
    }
    // Set up the time structure
    time.tm_year = year - 1900; // Years since 1900
    time.tm_mon = month - 1;    // Months since January (0-11)
    time.tm_mday = day;         // Days since the start of the month

    // Convert to epoch timestamp
    return mktime(&time);
}


/**
 * @brief converts an epoch timestamp to a date string in mm/dd/yyyy format
 *
 * @param date a char pointer to the date string
 */
void epoch_to_date(time_t epoch_time, char *date) {
    struct tm *time = localtime(&epoch_time);

    if (time == NULL) {
        fprintf(stderr, "Failed to convert epoch time\n");
        return;
    }

    // Format the time structure into the date string
    strftime(date, MAX_DATE_STR_SIZE, "%m/%d/%Y", time);
}


struct temp_humid_data get_node_data(time_t timestamp, uint32_t* io_base) {
    uint32_t tempVal, humidVal;
    float temp, humid;

    _iom361_setSensor1_rndm(TEMP_RANGE_LOW, TEMP_RANGE_HI, HUMID_RANGE_LOW,
                            HUMID_RANGE_HI);

    tempVal = iom361_readReg(io_base, TEMP_REG, NULL);
    temp = (tempVal / powf(2, 20)) * 200.0 - 50;
    humidVal = iom361_readReg(io_base, HUMID_REG, NULL);
    humid = (humidVal / powf(2, 20)) * 100;
    struct temp_humid_data data = {timestamp, temp, humid};

    return data;
}


/**
 * @brief Given a date, populates the passed in BST with the next 30 days
 * of temperature and humidity data
 *
 * @param tree a pointer to the binary search tree that the data will be stored in
 * @param start_time the start time for the range of days being inserted
 * @param end_time the end time for the range of days being inserted 
 * @param io_base the iom module address
 */
void populateBST_recursive(struct BST* tree, time_t start_time, time_t end_time, uint32_t* io_base) {
    // Base case check
    if (start_time > end_time) {
        return; 
    }
    // Find the middle day of the current sub range to ensure an even distribution of the tree
    time_t mid_time = start_time + ((end_time - start_time) / 2);

    // Insert the middle day into the tree
    struct temp_humid_data data = get_node_data(mid_time, io_base);
    tree->insert(tree, data);

    // Recursively insert the left and right halves 
    populateBST_recursive(tree, start_time, mid_time - 86400, io_base); 
    populateBST_recursive(tree, mid_time + 86400, end_time, io_base);
}


/**
 * @brief Given a date, populates the passed in BST with the next 30 days
 * of temperature and humidity data
 *
 * @param date a char pointer to the date string
 * @param tree a pointer to the binary search tree that the data will be stored in
 * @param io_base the iom module address
 */
void populateBST(const char* date, struct BST* tree, int numDays, uint32_t* io_base) {
    // Define the start and end range of days to insert
    time_t start_time = date_to_epoch(date);
    time_t end_time = start_time + 86400 * (numDays - 1);

    // Recursively insert the days
    populateBST_recursive(tree, start_time, end_time, io_base);
}