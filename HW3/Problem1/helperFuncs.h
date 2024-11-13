#ifndef _HELPER_FUNCS_H
#define _HELPER_FUNCS_H

#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include <errno.h>

typedef struct {
    char* country;
    int code;
} country_code_entry_t, *cc_entry_ptr;



/**
 * @brief Allocates memory for the country code lookup table
 *
 * @param table A pointer to an array of pointers to country code entry structs.
 * @param country_codes A poitner to an array containing a predefined set of countries and their country codes
 * @param numEntries The number of entryies in the in *tablePtr
 * 
 * @return void
 */
void allocateLookUpTable(country_code_entry_t** table, int numEntries, const country_code_entry_t* country_codes);

/**
 * @brief Frees the memory for the country code lookup table
 *
 * @param table A pointer to an array of pointers to country code entry structs (the look up table).
 * @param numEntries The number of entryies in the in table
 * 
 * @return void
 */
void freeLookUpTable(country_code_entry_t** table, int numEntries);


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
int searchLookupTable(country_code_entry_t* table[], int numEntries, char country[]);

#endif