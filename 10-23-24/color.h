#include <stdio.h>

typedef struct color {
    __uint8_t red;
    __uint8_t green;
    __uint8_t blue;
} COLOR_T, *COLOR_T_PT;

COLOR_T make_color(__uint8_t RED, __uint8_t BLUE, __uint8_t GREEN);

enum {
    RED,
    GREEN,
    BLUE
};

