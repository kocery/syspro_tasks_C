#include <stdio.h>
#include <windows.h>

int main() {
    SetConsoleOutputCP(CP_UTF8);
    unsigned long N;

    unsigned long Nc = 0;

    printf("Введите начение N типа unsigned long:");
    scanf("%lu", &N);

    for (unsigned long i = 1; i < N; i++) {
        for (unsigned long num = 0; num < i; num++) {
            printf("%lu ", Nc++);
        }
        printf("\n");
    }


    return 0;
}
