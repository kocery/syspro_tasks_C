#include <stdio.h>
#include <windows.h>
#include <stdbool.h>

bool is_prime(unsigned long long n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;

    for (unsigned long long i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }

    return true;
}


int main() {
    SetConsoleOutputCP(CP_UTF8);
    unsigned long long N;

    printf("Введите значение N типа unsigned long long:");
    scanf("%llu", &N);

    if (N < 2) {
        printf("Ошибка, число меньше 2");
    } else {
        for (unsigned long long i = 0; i < N; i ++) {
            if (is_prime(i)) {
                printf("%llu ", i);
            }
        }

    }


    return 0;
}
