#include <stdio.h>
#include <stdbool.h>

// constants and defines
#define MAXSIZE 100 // size of stack array
#define MAXNAME 20 // size of name field
#define MAXCOLOR 10 // size of color field
// typedefs and structs
typedef struct {
char name[MAXNAME]; // name of clothing item
char color[MAXCOLOR]; // color of clothing item
bool canWashHot; // true if can wash in hot water
} clothes_t, *clothesPtr_t;

typedef struct {
    int top; // top of staff index
    int capacity; // maximum clothing items on stack
    clothesPtr_t stack; // will use malloc() to allocate stack
    space
} clothesStack_t, *clothesStackPtr_t;

clothesStackPtr_t createStack(void) {
    clothesStackPtr_t stack_t_ptr = malloc(sizeof(clothesStack_t));
    if (stack_t_ptr == NULL) {
        terminate("Not enough ram or what not");
        return NULL;
    }
        
    clothesPtr_t stack_ptr = malloc((sizeof(clothes_t) + sizeof(char) * MAXCOLOR * MAXNAME) * MAXSIZE);
    if (stack_t_ptr == NULL) {
        terminate("Not enough ram or what not");
        return NULL;
    }
    clothes_t temp_stack[MAXSIZE];
    stack_t_ptr->stack = &temp_stack;
    return stack_t_ptr;
}


void push(clothesStackPtr_t S, clothes_t item) { 
    if (!isFull()) {
        S->top++;
        S->stack[S->top] = item;
    }
    else terminate("Push failed! Stack is full :\\");
} 


void pop(clothesStackPtr_t S, clothes_t *item) { 
    if(isEmpty(S)) {
        terminate("Stack is empty!");
        return NULL;
    }
        
    *item = S->stack[S->top];
    S->top--;
}



int a[10] = {0, 15, 27, 1, -5, 1, 4, 7, 9, 2}; 
#include <stdlib.h> 
#include <stdio.h> 
#include <stdbool.h> 

#include <string.h>

int main() { 
    // ADD ANY OTHER VARIABLES YOU NEED HERE 
    clothesPtr_t item; //added variable

    clothesStackPtr_t ci_stack; 
    clothes_t ci; 

    ci_stack = createStack();
    
    if (ci_stack == NULL) {
        terminate("Could not create stack for ci_stack");
        return 1;
    }

    stcpy(ci.name, "T-Shirt");
    strcp(ci.color, "Black");
    ci.canWashHot = true;
    
    push(ci_stack, ci);

    pop(ci_stack, item);

    deleteStack(ci_stack);

    return 0; 
}

