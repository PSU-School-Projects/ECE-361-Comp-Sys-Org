#ifndef _HELPER_FUNCS_H
#define _HELPER_FUNCS_H

#include <ctype.h>
#include <stdbool.h>
#include <string.h>

/**
 * @brief Decrypts a BIFF speak string.
 *
 * Takes in a BIFF speak string and inserts the translation into translation string argument
 *
 * @param original[] the encrypted? string
 * @param trans_str[] translated string
 * 
 * @return void
 */
void BIFF_translate(char original[], char trans_str[]);

#endif