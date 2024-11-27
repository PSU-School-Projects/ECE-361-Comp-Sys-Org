#include "helperFuncs.h"
#include <stdio.h>

/**
 * @brief Takes in a C string and removes all the spaces
 * taken from the example here: https://stackoverflow.com/questions/1726302/remove-spaces-from-a-string-in-c 
 *
 *
 * @param s a pointer to the string to be operated on
 */
void remove_spaces(char* s) {
    char* d = s;
    do {
        while (isspace(*d)) {
            ++d;
        }
    } while ((*s++ = *d++));
}

/**
 * @brief takes in a RPN expression and prints the result of the expression
 * to the console. Returns false if the expression is not in reverse polish notation
 *
 * @param expr the RPN expression
 * 
 * @return `bool`
 */
bool parseRPN(char expr[]) {
    llStackPtr_t stackPtr = createStack();
    remove_spaces(expr);

    bool parsing = true;
    int i = 0;
    int op1, op2;
    int result = 0;

    do {
        switch (expr[i]) {
            case '+':
                op2 = pop(stackPtr);
                op1 = pop(stackPtr);
                result = op1 + op2;
                push(stackPtr, result);
                break;
            case '-':
                op2 = pop(stackPtr);
                op1 = pop(stackPtr);
                if (op1 && op2) {
                    result = op1 - op2;
                    push(stackPtr, result);
                }
                else return false;
                break;
            case '*':
                op2 = pop(stackPtr);
                op1 = pop(stackPtr);
                result = op1 * op2;
                push(stackPtr, result);
                break;
            case '/':
                op2 = pop(stackPtr);
                op1 = pop(stackPtr);
                    if (op1 == 0 || op2 == 0) {
                        fprintf(stderr, "\nERROR[parseRPN]: Division by zero.");
                        return false;
                    }
                    result = op1 / op2;
                    push(stackPtr, result);
                break;
            case '%':
                op2 = pop(stackPtr);
                op1 = pop(stackPtr);
                if (op1 == 0 || op2 == 0) {
                    fprintf(stderr, "\nERROR[parseRPN]: Modulus by zero.");
                    return false;
                }
                result = op1 % op2;
                push(stackPtr, result);
                break;
            case '&':
                op2 = pop(stackPtr);
                op1 = pop(stackPtr);
                result = op1 & op2;
                push(stackPtr, result);
                break;
            case '|':
                op2 = pop(stackPtr);
                op1 = pop(stackPtr);
                result = op1 | op2;
                push(stackPtr, result);
                break;
            case '~':
                op1 = pop(stackPtr);
                result = op1 ^ 0xFFFFFFFF;
                push(stackPtr, result);
                break;
            case '=':
                result = pop(stackPtr);
                printf("Result: %s %d\n", expr, result);
                deleteStack(stackPtr);
                parsing = false;
                break;
            // if not an operand check if it's a different valid input, else stop parsing
            default:
                if (isdigit(expr[i])) {
                    push(stackPtr, expr[i]-'0');
                }
                else {
                    fprintf(stderr, "\nERROR[parseRPN]: Invalid character received in expression\nExiting...");
                    return false;
                }
        }
        i++;
    } while(parsing);
    return true;
}