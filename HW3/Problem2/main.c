/**
 *
 * @file:	main.c
 * @author:	<Jeremiah Vandagrift> (jcv3@pdx.edu)
 * @date:	09-Nov-2024
 *
 * Populates array with switch and RGB color data in the application.  Uses iom361
 * to copy switch data to the LEDs and to set the duty cycles of the RGB LED.
 * This problem does not use the AHT20 registers or the RESERVED registers.  
 *
 */
 
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <unistd.h>
#include <errno.h>

#include "helperFuncs.h"
#include "../libs/lineHelper.h"
#include "../libs/colors_api/colors.h"
#include "../libs/iom361_r2/iom361_r2.h"

extern uint32_t* io_base;
extern iodata_t data[];


int main() {
    int rtn_code;
	uint32_t reg_value;
	int num_items;
		 
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
    "Lets begin!\n\n");
    /*********END of Greeting**********/
	 
	// ADD YOUR CODE TO INITIALIZE iom361
	printf("Initializing the I/O registers\n");
    sleep(1);
	io_base = iom361_initialize(16, 16, &rtn_code);
	if (rtn_code != 0) {
		// initialization failed
		printf("Could not initialize I/O module\n");
		return 1;
	}
	printf("Successfully Initialized\n");
	
    printf("Checking preconfigured data...\n");
	// get the "hardwired" data
	num_items = populate_data_array();
    
	
	// display the contents of the data array
	for (int i = 0; i < num_items; i++){
        sleep(1);
		uint32_t sw;
		uint8_t dcr, dcg, dcb;
		
		// separate and display the data items
		sw =  data[i].sw;
		dcr = data[i].rgb.red;
		dcg = data[i].rgb.green;
		dcb = data[i].rgb.blue;
		printf("INFO[main()]:  Retrieved item[%d] sw=%08x, duty cycles= {%d, %d, %d}\n",
				i, sw, dcr, dcg, dcb);
	}
	printf("There are %d data items to send to I/O module\n", num_items);
    printf("\nPlease input up to %d more data items separated by a new line to send to I/O module\n", MAX_DATA_ITEMS-num_items);
    printf("Data should be formatted like the following\n"
    "\"{switch config uint32_t} {red duty cycle uint8_t} {green duty cycle uint8_t} {blue duty cycle uint8_t}\n"
    "Send a blank line to finish sending data.\n");


    bool gatherData = true;
    do {
        char userData[MAX_USER_DATA_LEN];
        printf("\nInput Data: ");
        getaLine(userData, MAX_USER_DATA_LEN);
        if (strlen(userData) == 0 || userData[0] == '\n' || userData[0] == EOF) {
            printf("No (more) data received.\nPushing data to registers...\n");
            gatherData = false; 
        }
        else {

            uint16_t sw;
            uint8_t red, blue, green;
            int numValsCollected = sscanf(userData, "%hx %hhu %hhu %hhu", &sw, &red, &green, &blue);

            if (numValsCollected != 4) {
                printf("Invald data entry, entry ignored.");
                continue;
            }
            else {
                // Convert 16 bit switch value to 32 bit value
                data[num_items].sw = sw;
                data[num_items].rgb = makeColor(red, green, blue);
                num_items++;
            }
            
        }

        if (num_items == MAX_DATA_ITEMS) {
            printf("Max number of data entries reached.\nPushing data to registers...\n\n");
            gatherData = false;
        }
    } while (gatherData);

    // sending the data to the iom361 peripheral registers
	for (int i = 0; i < num_items; i++) {
		// ADD YOUR CODE TO SEND DATA TO iom361 peripheral registers
        reg_value = data[i].sw;
        int RGB_rtn_code;

        printf("Setting switches to %8X\n", reg_value);
        sleep(1);
        _iom361_setSwitches(reg_value);
        printf("Writing to LED register...\n");
        sleep(1);
        reg_value = iom361_readReg(io_base, SWITCHES_REG, NULL);
	    iom361_writeReg(io_base, LEDS_REG, reg_value, NULL);

        printf("Writing to RGB LED to RGB LED register...\n");
        reg_value = makeRGBLedReg(data[i].rgb, true);
        printf("Reg. Val: %X, Blue: %2X, Green: %2X, Red: %2X, Enable: %s\n",
         reg_value, data[i].rgb.blue, data[i].rgb.green, data[i].rgb.red,
         (reg_value >> 31) & 0x1 ? "true" : "false");
        sleep(1);
        iom361_writeReg(io_base, RGB_LED_REG, reg_value, &RGB_rtn_code);
        if (RGB_rtn_code != 0) {
            printf("Could not write to RGB LED register\n");
        }
        printf("\n");
	}
    
	return 0;
 }
 
