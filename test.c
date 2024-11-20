#include <stdio.h>

int check_one_1(unsigned char binaryVal) {
    if (binaryVal != 0 && (binaryVal & (binaryVal - 1)) == 0) {
        /* Only one bit is set to 1
        return the 1-base index
        the index in 1-based index
        subtract one after to get 0 based index.
        returns 0 if no 0s are found
        */
        return ffs(binaryVal);
    }
}

int main() {
    unsigned char bv = 0b00000001;
    printf("%d", check_one_1(bv));
    return 0;
}