#include <stdio.h>

void B(int b) {
    printf("%p\n", &b);
}

void C() {
    int b = 5;
    printf("%p\n", &b);
    B(b);
}


int main() {
    int b = 5;
    B(b);
    C();
}

