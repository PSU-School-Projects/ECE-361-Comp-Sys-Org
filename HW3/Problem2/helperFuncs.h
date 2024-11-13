#ifndef _HELPER_FUNCS_H
#define _HELPER_FUNCS_H

#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include <errno.h>
#include "../libs/colors_api/colors.h"


// constants, enums and typedef
#define MAX_DATA_ITEMS	10
#define NUM_LEDS		16
#define NUM_SWITCHES	16

#define MAX_USER_DATA_LEN 50

typedef struct {	// data structure that combines sw and RGB LED data
	uint32_t sw;
	color_t rgb;
} iodata_t;
  
// global variables
extern uint32_t* io_base;	// base address of iom361
extern iodata_t data[];	// array to hold switch and duty cycle data

// helper function prototypes
int populate_data_array(void);

#endif