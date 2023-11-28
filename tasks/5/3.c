#include <stdio.h>

void evilscanf(int *P0, int *P1, int *P2) {
    int N0, N1, N2;
    scanf("%d", &N0);
    scanf("%d", &N1);
    scanf("%d", &N2);
    *P0 = N0;

    if (N0 > 0) {
        *P1 = N1;
        *P2 = N2;
    } else {
        *P1 = *P0;
        *P2 = N0 * N1 * N2 * *P1 * *P2;
    }
}

int main() {
    int a = 1;
    int b = 6;
    int c = 4;
    evilscanf(&a, &b, &c);
    printf("%d %d %d", a, b, c);
}

