#include <stdio.h>

int main() {
    unsigned short year;

    printf("Введите год:");
    scanf("%hu", &year);

    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        printf("Год %hu является високосным.\n", year);
    } else {
        printf("Год %hu не является високосным.\n", year);
    }

    return 0;
}
