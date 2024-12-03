#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Custom function to parse a date string (mm/dd/yyyy or mm-dd-yyyy)
int parse_date(const char *date_str, int *month, int *day, int *year) {
    char delimiter;
    if (strchr(date_str, '/') != NULL) {
        delimiter = '/';
    } else if (strchr(date_str, '-') != NULL) {
        delimiter = '-';
    } else {
        return 0; // Invalid format
    }

    // Parse the date string
    if (sscanf(date_str, "%d%c%d%c%d", month, &delimiter, day, &delimiter, year) != 5) {
        return 0; // Parsing failed
    }

    return 1; // Successfully parsed
}

// Function to convert a date string to epoch timestamp
time_t date_to_epoch(const char *date_str) {
    int month, day, year;
    struct tm tm = {0};

    // Parse the date string
    if (!parse_date(date_str, &month, &day, &year)) {
        fprintf(stderr, "Invalid date format: %s\n", date_str);
        return -1;
    }

    // Set the tm structure
    tm.tm_year = year - 1900; // Years since 1900
    tm.tm_mon = month - 1;    // Months since January (0-11)
    tm.tm_mday = day;

    // Convert to epoch time
    return mktime(&tm);
}

// Function to convert an epoch timestamp to a date string in mm/dd/yyyy format
void epoch_to_date(time_t epoch_time, char *date_str, size_t size) {
    struct tm *tm = localtime(&epoch_time);

    if (tm == NULL) {
        fprintf(stderr, "Failed to convert epoch time\n");
        snprintf(date_str, size, "Invalid");
        return;
    }

    // Format the tm structure into the date string
    strftime(date_str, size, "%m/%d/%Y", tm);
}

int main() {
    const char *date_str = "12/3/2024";
    time_t epoch;
    char formatted_date[11];

    // Convert date to epoch time
    epoch = date_to_epoch(date_str);
    if (epoch != -1) {
        printf("Epoch time for %s: %ld\n", date_str, epoch);
    }

    // Convert epoch time back to date
    epoch_to_date(epoch, formatted_date, sizeof(formatted_date));
    printf("Date for epoch time %ld: %s\n", epoch, formatted_date);

    return 0;
}
