#include <stdio.h>
#include <windows.h>

int main() {
    SetConsoleOutputCP(CP_UTF8);
    unsigned long n;

    // Чтение значения года
    printf("Введите начение N типа unsigned long:");
    scanf("%lu", &n);

    for (unsigned long i = 0; i <= n; i++) {
        if (i % 3 == 0 && i % 5 == 0)
            printf("fizz buzz ");
        else if (i % 3 == 0)
            printf("fizz ");
        else if (i % 5 == 0)
            printf("buzz ");
        else
            printf("%lu ", i);
    }


    return 0;
}
