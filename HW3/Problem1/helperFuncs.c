#include "helperFuncs.h"
#include <stdio.h>


/**
 * @brief Allocates memory for the country code lookup table
 *
 * @param table A pointer to an array of pointers to country code entry structs.
 * @param country_codes A poitner to an array containing a predefined set of countries and their country codes
 * @param numEntries The number of entryies in the in *tablePtr
 * 
 * @return void
 */
void allocateLookUpTable(country_code_entry_t** table, int numEntries, const country_code_entry_t* country_codes) {
    //Allocate memory for the array of pointers to country_code_entry_t
    *table = (country_code_entry_t*)malloc(numEntries * sizeof(country_code_entry_t));
    if (*table == NULL) {
        fprintf(stderr, "Memory allocation failed for lookup table.\n");
        exit(1);
    }

    // Allocate memory and copy each country string
    for (int i = 0; i < numEntries; i++) {
        int country_length = strlen(country_codes[i].country);
        (*table)[i].country = (char*)malloc((country_length + 1) * sizeof(char)); // +1 for the null terminator
        if ((*table)[i].country == NULL) {
            fprintf(stderr, "Memory allocation failed for country strings.\n");
            // Free previously allocated memory before exiting
            for (int j = 0; j < i; j++) {
                free(table[j]->country);
            }
            free(*table);
            exit(1);
        }
        // Copy the country string and the code from country_codes
        strcpy((*table)[i].country, country_codes[i].country);
        (*table)[i].code = country_codes[i].code;
    }
}


/**
 * @brief Frees the memory for the country code lookup table
 *
 * @param table A pointer to an array of pointers to country code entry structs (the look up table).
 * @param numEntries The number of entryies in the in table
 * 
 * @return void
 */
void freeLookUpTable(country_code_entry_t** table, int numEntries) {
    for (int i = numEntries-1; i >= 0; i--) {
        if (table[i] != NULL) {
            if ((*table)[i].country != NULL) {
                // Free the dynamically allocated 'country' string
                free((*table)[i].country);
            }
        }
    }
    // Free the table itself (this includes the structs)
    free(*table);
    *table = NULL;
}


/**
 * @brief Searchs the look up table for the user supplied and returns a pointer to the the entry if
 * it's found. Otherwise, returns NULL
 *
 * @param table A pointer to the look up table
 * @param numEntries The number of entryies in the table
 * @param country The user inputed country
 * 
 * @return `int`
 */
int searchLookupTable(country_code_entry_t* table[], int numEntries, char country[]) {
    int input_country_len = strlen(country);
    // Convert input to lower case for comparison
    for (int i = 0; i < input_country_len; i++) {
        // If newline is detected end string with null terminator
        country[i] = country[i] == '\n' ? '\0' : tolower(country[i]);
    }
    for (int i = 0; i < numEntries; i++) {
        // Copy country name
        char* lowerCaseCountry = malloc((strlen((*table)[i].country)+1) * sizeof(char)); // +1 for null terminator
        strcpy(lowerCaseCountry, (*table)[i].country);

        // Get length of country string
        int country_len = strlen(lowerCaseCountry);
        
        // Convert look up table country name to lower case to provide case insensitive matching
        for (int j = 0; j < country_len; j++) {
            lowerCaseCountry[j] = tolower(lowerCaseCountry[j]);
        }
        if (strcmp(country, lowerCaseCountry) == 0) {
            free(lowerCaseCountry);
            return i;
        }
        else free(lowerCaseCountry);
    }
    return -1;
}