#include <stdio.h>
#include <windows.h>



unsigned int countDivisors(unsigned int N) {
    unsigned int c = 0;

    for (unsigned int i = 1; i <= (N / 2) + 1; i++) {
        if (N % i == 0) {
            c++;
        }
    }
    return c;
}


int main() {
    SetConsoleOutputCP(CP_UTF8);

    unsigned int N;

    printf("Введите значение N типа unsigned int:");
    scanf("%iu", &N);

    if (N == 0) {
        printf("Ошибка, число дольно быть больше 1");
        return 0;
    }

    unsigned int divisorsCount = countDivisors(N);
    printf("Число делителей числа (кроме самого числа) %u это: %u\n", N, divisorsCount);

    return 0;
}
