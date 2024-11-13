#include "helperFuncs.h"

uint32_t* io_base = NULL;
iodata_t data[MAX_DATA_ITEMS];


 /**
  * populate_data_array() - "hardwires" switch and RGB duty cycle data
  *
  * This function populates the data array with switch and duty cycle values
  *
  */
int populate_data_array(void) {
	int num_items = 0;
	
	data[0].sw = 0x0000A5A5;
	data[0].rgb.red = 25; data[0].rgb.green = 102; data[0].rgb.blue = 128;
	++num_items;
	
	data[1].sw = 0x00005A5A;
	data[1].rgb.red = 128; data[1].rgb.green = 128; data[1].rgb.blue = 128;
	++num_items;
	
	data[2].sw = 0x0000FFFF;
	data[2].rgb.red = 255; data[2].rgb.green = 255; data[2].rgb.blue = 255;
	++num_items;
	
	data[3].sw = 0x00000000;
	data[3].rgb.red = 0; data[3].rgb.green = 0; data[3].rgb.blue = 0;
	++num_items;
	
	data[4].sw = 0x0000ECE3;
	data[4].rgb.red = 30; data[4].rgb.green = 60; data[4].rgb.blue = 90;
	++num_items;
	
	// ADD YOUR TEST CASES HERE

    

	return num_items; 	
}