#include <stdio.h>

void swap(int *pa, int *pb) {
    int c = *pa;
    *pa = *pb;
    *pb = c;
}

int main() {
    int x = 5, y = 7;
    swap(&x, &y);
    printf("%d, %d", x, y);
}

