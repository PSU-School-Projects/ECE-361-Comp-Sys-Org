#include "helperFuncs.h"
#include <stdio.h>

/**
 * @brief Decrypts a BIFF speak string.
 *
 * Takes in a BIFF speak string and inserts the translation into translation string argument
 *
 * @param original[] the encrypted? string
 * @param trans_str[] translated string
 * 
 * @return Void
 */
void BIFF_translate(char original[], char trans_str[]) {
    size_t len = strlen(original);
    bool capitalize = false;
    int offset = 0;
    for (int i = 0; i < len; i++) {
        char c = tolower(original[i]);
        bool cap_next = false;
        switch (c) {
            case '4':
                trans_str[i-offset] = 'a';
                break;
            case '8':
                trans_str[i-offset] = 'b';
                break;
            case '3':
                trans_str[i-offset] = 'e';
                break;
            case '1':
                trans_str[i-offset] = 'l';
                break;
            case '0':
                trans_str[i-offset] = 'o';
                break;
            case '5':
                trans_str[i-offset] = 's';
                break;
            case '9':
                cap_next = true;
                offset++;
                break;
            default:
                trans_str[i-offset] = c;
                break;
        }

        if (capitalize && !cap_next) trans_str[i-offset] = toupper(trans_str[i-offset]);
        capitalize = cap_next;
    }
    if (trans_str[len-offset] != '\0') trans_str[len - offset] = '\0';
}