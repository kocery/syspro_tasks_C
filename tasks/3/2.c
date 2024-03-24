#include <stdio.h>

int main() {
    unsigned long N;

    printf("Введите начение N типа unsigned long:");
    scanf("%lu", &N);

    for (unsigned long i = 0; i < N * N; i++) {
        printf("%lu ", i);
        if ((i + 1) % N == 0)
            printf("\n");
    }


    return 0;
}
