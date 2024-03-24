#include <stdio.h>

int is_prime(unsigned long long n) {
    if (n <= 1) return 0;
    if (n <= 3) return 1;
    if (n % 2 == 0 || n % 3 == 0) return 0;

    for (unsigned long long i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0)
            return 0;
    }

    return 1;
}


int main() {
    unsigned long long N;

    printf("Введите значение N типа unsigned long long:");
    scanf("%llu", &N);

    if (N < 2) {
        printf("Ошибка, число меньше 2");
    } else {
        if (is_prime(N)) {
            printf("Число N является простым");
        } else {
            printf("Число N не является простым");
        }
    }


    return 0;
}
