#include <stdio.h>
#include <limits.h>

int main() {
    int g1, g2;
    printf("Введите первое число:");
    scanf("%d", &g1);

    printf("Введите второе число:");
    scanf("%d", &g2);

    printf("Результаты арифметических операций:\n");
    printf("%d + %d = %d\n", g1, g2, g1 + g2);
    printf("%d - %d = %d\n", g1, g2, g1 - g2);
    printf("%d * %d = %d\n", g1, g2, g1 * g2);

    if (g2 != 0) {
        printf("%d / %d = %d\n", g1, g2, g1 / g2);
    }

    if (g2 != 0) {
        printf("%d %% %d = %d\n", g1, g2, g1 % g2);
    }

    printf("Результаты сравнительных операций:\n");
    printf("%d == %d: %d\n", g1, g2, g1 == g2);
    printf("%d != %d: %d\n", g1, g2, g1 != g2);
    printf("%d > %d: %d\n", g1, g2, g1 > g2);
    printf("%d < %d: %d\n", g1, g2, g1 < g2);
    printf("%d >= %d: %d\n", g1, g2, g1 >= g2);
    printf("%d <= %d: %d\n", g1, g2, g1 <= g2);

    printf("Результаты логических операций:\n");
    printf("%d && %d: %d\n", g1, g2, g1 && g2);
    printf("%d || %d: %d\n", g1, g2, g1 || g2);
    printf("!%d: %d\n", g1, !g1);
    printf("!%d: %d\n", g2, !g2);

    printf("Результаты побитовых операций:\n");
    printf("%d & %d: %d\n", g1, g2, g1 & g2);
    printf("%d | %d: %d\n", g1, g2, g1 | g2);
    printf("%d ^ %d: %d\n", g1, g2, g1 ^ g2);
    printf("~%d: %d\n", g1, ~g1);
    printf("~%d: %d\n", g2, ~g2);

    // Наличие числа -(2^31) в диапазоне int
    printf("Наличие числа -(2^31) в диапазоне int: %d\n", INT_MIN == -((long long) 1 << 31));
}