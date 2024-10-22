/** k&r2_1_13.c - Solution to K&R2: 1.6 Arrays, exercise 1-13
 *
 * 
 * @author: Jeremiah Vandagrift (j.c.vandagrift@gmail.com)
 * @date:   The 8th of October, 2024
 *
 *	@brief
 *  write a program to print a histogram of the lengths of words
 *  in input. it is easy to draw the histogram with horizontal bars
 *
 *	@note	Extra credit opportunity for HW #1:  Write code to display vertical Histogram (up to 2 pts).
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <stdbool.h> 

#define MAXLENGTH 11

//************ ADDED ***************/
#include <wchar.h>
#include <locale.h>
#define PRINTVERT true

void printVertHisto(int wordlen[], int maxOccurrences);
//**********************************/

int main()
{
    int c = 0;              // current character
    int nchar = 0;          // number of characters in a word 
  
    int wordlen[MAXLENGTH]; // array containing counts of number of words of a
                            // particular length we have seen
                            
    char buff[200];         // buffer to hold all characters in input stream
    int bufinx = 0;         // index into buffer array
	
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
    "If you're looking to make some histograms you've come to the right place.\n");
    printf("\nPlease input your data.\n"
    "Once you've done so press ctrl+d\n"
    "or, if you're using the exicutable version, ctrl+z followed by enter.\n\n");

    // initialize the word length array counts
    for(int i = 0; i < MAXLENGTH; ++i)
        wordlen[i] = 0;

    // process the input stream
    nchar = 0;
    while((c = getchar()) != EOF) {
        // add character to buffer
        buff[bufinx++] = c;
        
        // process the character stream
        if (c == ' ' || c == '\n' || c == '\t') {
            // end of word.  add instanace of a word of nchar length to the wordlen array
            if (nchar < MAXLENGTH)
                ++wordlen[nchar];
            nchar = 0;
        }            
        else {
            ++nchar;
        }
    }

    // dump the buffer to the console
    printf("\nInput stream:\n");
    for (int i = 0; i < bufinx; i++)
        putchar(buff[i]);
    
    if (PRINTVERT) {
        //print vertical histogram

        //get the max number of occurrences
        int maxOccurrences = wordlen[0];
        for (int i = 1; i < MAXLENGTH; i++) {
            if (wordlen[i] > maxOccurrences) {
                maxOccurrences = wordlen[i];  // Update max if a larger value is found
            }
        }
        printVertHisto(wordlen, maxOccurrences);
    }
    
    // print the horizontal histogram
    printf("\nHorizontal word length histogram:\n");
    for(int i = 1; i < MAXLENGTH; ++i) {
        printf("%2d| ", i);
        for(int j = 0; j < wordlen[i]; ++j)
            putchar('*');
        putchar('\n');
    }
    
    return 0;
}


/****** Data set for exercise 1.13 ****
A good dog is fun to play fetch with
Let's experiment with a string of numbers
01234567    987654321
0123456789ABCDEF
********/

void fillCol(wchar_t barChart[][MAXLENGTH+1], int occurrences, int col, wchar_t filler) {
    //fill all the col up to the num occurrences
    //don't fill bottom row as it contains the border
    for (int i = 1; i < occurrences+1; i++) {
        barChart[i][col] = filler;
    }
}

void printVertHisto(int wordlen[], int maxOccurrences) {
    //set minimum graph height
    if (maxOccurrences < 3) maxOccurrences = 3;
    //required for special wchar_t characters
    setlocale(LC_ALL, "");
    //use wide char for better fill character options
    wchar_t barChart[maxOccurrences+2][MAXLENGTH+1];
    //initialize array elements (otherwise they're random values based on memory)
    for (int i = 0; i < maxOccurrences+2; i++) {
        for (int j = 0; j < MAXLENGTH+1; j++) {
            //set each element to be a blank space
            barChart[i][j] = L' ';
        }
        //add null terminator so that we can print entire rows at a time
        barChart[i][MAXLENGTH] = L'\0';
    }
    fillCol(barChart, maxOccurrences+1, 0, '|');
    for(int i = 0; i < MAXLENGTH; i++) {
        barChart[0][i] = L'—';
    }
    //start at 1 because left most col is a border
    for(int i = 1; i < MAXLENGTH; i++) {
        int occurences = wordlen[i];
        fillCol(barChart, occurences, i, L'█');
    }

    printf("\nVertical word length histogram:\n");
    for (int i = maxOccurrences+2; i >= 0; --i) {
        wchar_t* temp = barChart[i];
        printf("%ls\n", temp);
        // for (int j = 0; j < MAXLENGTH+1; j++) {
            
        // }
    } 
    printf(" ");
    for (int i = 1; i < MAXLENGTH; i++) {
        printf("%d", i%10);
    }
    printf("\n");
}

