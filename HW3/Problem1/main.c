/**
 *
 * lookup_dialcode.c() - looks up a dialing country code for a country
 *
 * @author     Jeremiah Vandagrift (jcv3@pdx.edu)
 * @date       08-Nov-2024
 *
 *  @brief
 *	Uses an array of struct as a simple database to lookup a country code when given a text string
 *  containing a country.  Displays the country and its dialing country code if the country is
 *  in the table.  Prints an error message if it is not.
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

// ADD YOUR #INCLUDES (IF ANY) HERE
#include <stdbool.h>
#include "helperFuncs.h"
#include "../libs/lineHelper.h"

/***** enums, constants, and typedefs *****/

// MOVED TO helperFuncs.h
// typedef struct {
//     char* country;
//     int code;
// } country_code_entry_t, *cc_entry_ptr;

// ADD YOUR ENUMS, CONSTANTS, AND TYPEDEFS (IF ANY) HERE
//#define DEBUG
#define MAX_LENGTH 50

/***** country codes - used to initialize lookup table *****/
const country_code_entry_t country_codes[] =
    {{"Argentina",              54},    {"Bangladesh",              880},
     {"Brazil",                 55},    {"Myanmar",       			95},
     {"China",                  86},    {"Columbia",                57},
     {"Congo",    				243},   {"Egypt",                   20},
     {"Ethiopia",               251},   {"France",                  33},
     {"Germany",                49},    {"India",                   91},
     {"Indonesia",              62},    {"Iran",                    98},
     {"Italy",                  39},    {"Japan",                   81},
     {"Mexico",                 52},    {"Nigeria",                 234},
     {"Pakistan",               92},    {"Phillipines",             63},
     {"Poland",                 48},    {"Russia",                  7},
     {"South Africa",           27},    {"South Korea",             83},
     {"Spain",                  34},    {"Sudan",                   249},
     {"Thailand",               66},    {"Turkey",                  90},
     {"Ukraine",                380},   {"United Kingdom",          44},
     {"United States",          1},     {"Vietnam",                 84}};
     
  /***** Global variables *****/   
// ADD YOUR GLOBAL VARIABLES HERE
int CC_LEN = *(&country_codes + 1) - country_codes;
/***** Function prototypes *****/
// ADD YOUR FUNCTION PROTOYPES (IF ANY) HERE

/***** main() *****/
int main() { 
    // ADD YOUR LOCAL VARIABLES HERE
	
	// the lookup table of pointers to country codes
	country_code_entry_t* lookupTable = NULL;
    allocateLookUpTable(&lookupTable, CC_LEN, country_codes);

    
 
    // greet the user and display the working directory for the application
    // this code should be included in all of the applications you submit for ECE 361
    errno = 0;
    char *buf = getcwd(NULL, 0);    // allocates a buffer large enough to hold the path
    
    if (buf == NULL) {
        printf("ERROR (main): Could not display the path\n");
    }
    else {
        printf("\nCurrent working directory: %s\n", buf);
        free(buf);
    }

    printf("\nGreatings traveler. . .\n"
    "If you're looking to run the country dialcode looker-upper from HW3 you've come to the right place.\n"
    "Lets begin!\n");
    /*********END of Greeting**********/

    bool exit = false;
    do {
        char input_country[MAX_LENGTH];
        printf("\nInput Country Name: ");
        getaLine(input_country, MAX_LENGTH);
        if (strlen(input_country) == 0 || input_country[0] == '\n' || input_country[0] == EOF) {
            printf("No (more) content received.\n\"Gracefully\" exiting...\n");
            exit = true; 
        }
        else {
            int entryMatchIndex = searchLookupTable(&lookupTable, CC_LEN, input_country);
            if (entryMatchIndex == -1) {
                printf("\nCould not find a dialing code for %s\n", input_country);
            }
            else {
                printf("\nDialing code for %s: %d\n", lookupTable[entryMatchIndex].country, lookupTable[entryMatchIndex].code);
            }
        }
    } while (!exit);
    freeLookUpTable(&lookupTable, CC_LEN);
    if (lookupTable == NULL) printf("Successfully deallocated table.\n");
    return 0;
    // ADD YOUR CODE HERE
 }
 