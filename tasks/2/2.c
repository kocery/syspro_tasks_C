#include <stdio.h>
#include <windows.h>

int main() {
    SetConsoleOutputCP(CP_UTF8);
    unsigned short year;

    // Чтение значения года
    printf("Введите год:");
    scanf("%hu", &year);

    // Проверка на високосный год
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        printf("Год %hu является високосным.\n", year);
    } else {
        printf("Год %hu не является високосным.\n", year);
    }

    return 0;
}
