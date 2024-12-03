#include "helperFuncs.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


/**
 * @brief parse a date string (mm/dd/yyyy or mm-dd-yyyy)
 *
 * @param date_str a char pointer to the date string
 * @param month an int pointer to the variable the month will be stored in
 * @param day an int pointer to the variable the day will be stored in
 * @param year an int pointer to the variable the year will be stored in
 */
int parse_date(const char *date_str, int *month, int *day, int *year) {
    char delimiter;
    if (strchr(date_str, '/') != NULL) {
        delimiter = '/';
    } else if (strchr(date_str, '-') != NULL) {
        delimiter = '-';
    } else {
        // bad string format
        return 0; 
    }

    // Parse the date string
    if (sscanf(date_str, "%d%c%d%c%d", month, &delimiter, day, &delimiter, year) != 5) {
        // Failed to parse
        return 0; 
    }

    // Successfully parsed
    return 1;
}

/**
 * @brief converts a date string to epoch timestamp
 *
 * @param date_str a char pointer to the date string
 */
time_t date_to_epoch(const char *date_str) {
    int month, day, year;
    struct tm time = {0};

    // Parse the date string
    if (!parse_date(date_str, &month, &day, &year)) {
        fprintf(stderr, "Invalid date format: %s\n", date_str);
        return -1;
    }

    // Set up the time structure
    time.tm_year = year - 1900; // Years since 1900
    time.tm_mon = month - 1;    // Months since January (0-11)
    time.tm_mday = day;

    // Convert to epoch time
    return mktime(&time);
}


/**
 * @brief converts an epoch timestamp to a date string in mm/dd/yyyy format
 *
 * @param date_str a char pointer to the date string
 */
void epoch_to_date(time_t epoch_time, char *date_str) {
    struct tm *time = localtime(&epoch_time);

    if (time == NULL) {
        fprintf(stderr, "Failed to convert epoch time\n");
        return;
    }

    // Format the time structure into the date string
    strftime(date_str, MAX_DATE_STR_SIZE, "%m/%d/%Y", time);
}