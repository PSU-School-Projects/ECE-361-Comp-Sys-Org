#include <time.h>
#include <stdint.h>

typedef struct temp_humid_data {
time_t timestamp;
uint32_t temp;
uint32_t humid;
} temp_humid_data;

struct node {
   temp_humid_data data; 
   struct node *left;
   struct node *right;
};

void insert(int data);

struct node* search(int data);

