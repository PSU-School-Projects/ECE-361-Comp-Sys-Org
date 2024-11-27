#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <unistd.h>
#include <errno.h>

#include "helperFuncs.h"
#include "../libs/lineHelper.h"
#include "../libs/colors_api/colors.h"
#include "../libs/iom361_r2/iom361_r2.h"


#define TEMP_RANGE_LOW	32.2
#define TEMP_RANGE_HI	65.5
#define HUMID_RANGE_LOW	72.2
#define HUMID_RANGE_HI	88.8
#define NUM_READINGS 8

uint32_t* io_base;


int main() {
    int rtn_code;
	float sortedTemps[NUM_READINGS] = {0};
    float sortedHumids[NUM_READINGS] = {0};
    int count = 0;
	float temp, humid;
		 
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
    "If you're looking for problem of HW4 you've come to the right place.\n"
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
	
    //printf("Checking preconfigured data...\n");
	// get the "hardwired" data
	//num_items = populate_data_array();

	uint32_t tempVal, humidVal;
	
	printf("\nSetting sensors to random values and sampling data\n");	 
	 while (count < NUM_READINGS) {
        // Set sensors to random values and read data
        _iom361_setSensor1_rndm(TEMP_RANGE_LOW, TEMP_RANGE_HI, HUMID_RANGE_LOW,
                                HUMID_RANGE_HI);

        tempVal = iom361_readReg(io_base, TEMP_REG, NULL);
        temp = (tempVal / powf(2, 20)) * 200.0 - 50;
        humidVal = iom361_readReg(io_base, HUMID_REG, NULL);
        humid = (humidVal / powf(2, 20)) * 100;

        // Sort reading data
        sortedInsert(temp, sortedTemps, count);
        sortedInsert(humid, sortedHumids, count);

        printf("Temperature: %3.1fC(%08X), Relative Humidity: %3.1f%%(%08X)\n",
               temp, tempVal, humid, humidVal);

        count++;

        // Sleep "3 hours" (24/8)
        sleep(1);
    }

    float avgTemp = calculateAverage(sortedTemps, NUM_READINGS);
    float avgHumid = calculateAverage(sortedHumids, NUM_READINGS);

    printf("\nTemperature Table:\n");
    printf("-----------------------\n");
    printf("Index | Temperature (F)\n");
    for (int i = 0; i < NUM_READINGS; i++) {
        printf("%5d | %.2f\n", i + 1, sortedTemps[i]);
    }
    printf("--------------------\n");
    printf("Average Temperature: %.2fF\n", avgTemp);

    printf("\nHumidity Table:\n");
    printf("--------------------\n");
    printf("Index | Humidity (%%)\n");
    for (int i = 0; i < NUM_READINGS; i++) {
        printf("%5d | %.2f\n", i + 1, sortedHumids[i]);
    }
    printf("--------------------\n");
    printf("Average Humidity: %.2f%%\n", avgHumid);

    return 0;
}
 
