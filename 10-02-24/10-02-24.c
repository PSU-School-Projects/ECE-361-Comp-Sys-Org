 #include <stdio.h>


int main() {
    
    unsigned char test = 0b00001110;
    printf("Binary: ");
    for (int i = 7; i >= 0; i--) {  // Print each bit from MSB to LSB
        printf("%d", (test >> i) & 1);
    }
    printf("\n");

    test ^= 0xFF;
    printf("flip bits: ");
    for (int i = 7; i >= 0; i--) {  // Print each bit from MSB to LSB
        printf("%d", (test >> i) & 1);
    }
    test ^= 0xFF;
    printf("flip bits: ");
    for (int i = 7; i >= 0; i--) {  // Print each bit from MSB to LSB
        printf("%d", (test >> i) & 1);
    }
    return 0;
}

