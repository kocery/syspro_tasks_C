#include <stdio.h>
#include <windows.h>



unsigned int gcd (unsigned int N, unsigned int M) {
    while (M != 0) {
        unsigned int t = M;
        M = N % M;
        N = t;
        // 7 14 14
        // 14 7 14
        // 7 0 7
    }
    return N;
}


int main() {
    SetConsoleOutputCP(CP_UTF8);

    unsigned int N;
    unsigned int M;

    printf("Введите значение N типа unsigned int:");
    scanf("%iu", &N);

    printf("Введите значение M типа unsigned int:");
    scanf("%iu", &M);

    if (N == 0 || M == 0) {
        printf("Ошибка, числа должны быть больше 1");
        return 0;
    }

    unsigned int gcd_res = gcd(N, M);
    printf("НОД чисел %i и %i = %i", N, M, gcd_res);

    return 0;
}
