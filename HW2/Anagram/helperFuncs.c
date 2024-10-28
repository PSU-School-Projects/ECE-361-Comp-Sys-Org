#include "helperFuncs.h"
#include <stdio.h>

/**
 * @brief Checks if the two strings are anograms
 *
 * returns true if the anograms and prints a message to console.
 *
 * @param str1 the first string to compare
 * @param str1 the second string to compare
 * 
 * @return bool
 */
bool checkAnagram(char str1[], char str2[]) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    bool noAlpha = true;

    for (int i = 0; i < len1; i++) {
        int charCount1 = 0;
        int charCount2 = 0;
        char c = tolower(str1[i]);
        // skip char if it's not an alphabetical character
        if (!isalpha(c)) continue;
        // set bool to indicate that the first string contains any alphabetical characters
        noAlpha = false;

        // find number of occurances of current character in first string
        for (int j = 0; j < len1; j++) {
            if (tolower(str1[j]) == c) charCount1++;
        }
        // find number of occurances of current character in second string
        for (int k = 0; k < len2; k++) {
            if (tolower(str2[k]) == c) charCount2++;
        }

        // if any alphabetical character doesn't occur the same amount of times 
        // in both strings than they're already not anagrams
        if (charCount1 != charCount2) {
            // not anagrams
            return false;
        }
    }
    // should only reach if if the words are anagrams 
    // or the first word contains no alphabetical characters
    return true && !noAlpha;
}


/**
 * @brief Checks if the string matches the exit input
 *
 *
 * @param str the string to check
 * 
 * @return bool
 */
bool checkExit(char str[]) {
    if (strlen(str) == 0 || str[0] == '\n' || str[0] == EOF) {
        printf("No (more) content received.\n\"Gracefully\" exiting...\n");
        return true;
    }
    return false;
}