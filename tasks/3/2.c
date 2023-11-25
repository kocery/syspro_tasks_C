#include <stdio.h>
#include <windows.h>

int main() {
    SetConsoleOutputCP(CP_UTF8);
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
