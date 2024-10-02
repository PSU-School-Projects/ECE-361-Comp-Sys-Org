 #include <stdio.h>

char* things = "Spiders";
int* stuff;
int stuff2;
// or char* things = "Spiders";

void func() {
    static int test = 10;
}

int main() {
    func();
    printf("%d", test);
    return 0;
}

