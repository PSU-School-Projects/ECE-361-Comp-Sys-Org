 #include <stdio.h>

char* things = "Spiders";
int* stuff;
int stuff2;
// or char* things = "Spiders";

int main() {
    printf("Hello World");
    for (int i = 1; i <= 10; i++) {
        printf("%d little %s\n", i, things);
    }
    for(int j = 9; j > 0; j--) {
            printf("%d little %s\n", j, things);
        }
    char thing2[2] = {*(things + 1), *(things + 2* sizeof(char))};
    printf("%d", stuff[1]);
    return 0;
}

