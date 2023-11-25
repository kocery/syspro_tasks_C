#include <stdio.h>
#include <windows.h>

int sum_of_digits(int num) {
    int sum = 0;
    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}


int main() {
    SetConsoleOutputCP(CP_UTF8);
    unsigned long L, R;

    printf("Введите значение N типа unsigned long long:");
    scanf("%lu %lu", &L, &R);

    if (L > R) {
        printf("Ошибка, L больше R\n");
    } else {
        for (unsigned long ticket = L; ticket <= R; ++ticket) {
            int first_half = ticket / 1000;
            int second_half = ticket % 1000;

            if (ticket >= 100000 && sum_of_digits(first_half) == sum_of_digits(second_half)) {
                printf("%lu ", ticket);
            }
        }
    }


    return 0;
}
