#include <stdio.h>


int main() {
    int array[4][4];
    int i, j;

    printf("Введите элементы массива 4x4:\n");
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            scanf("%d", &array[i][j]);
        }
    }

    for (i = 0; i < 4; i++) {
        for (j = i; j < 4; j++) {
            if (i != j) {
                array[i][j] = array[i][j] + array[j][i];
                array[j][i] = array[i][j] - array[j][i];
                array[i][j] = array[i][j] - array[j][i];
            }
        }
        printf("\n");
    }


    printf("\nВы ввели следующий массив:\n");
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }

    return 0;
}
