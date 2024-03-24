#include <stdio.h>

unsigned int N;


void printField(char field[][N]) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            printf("%c ", field[i][j]);
        }
        printf("\n");
    }
}

int main() {
    printf("Введите значение N типа unsigned int:");
    scanf("%iu", &N);

    if (N < 2) {
        printf("Ошибка, число меньше 2");
    }

    char field[N][N];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            field[i][j] = '#';
        }
    }

    field[0][0] = '^';
    field[N - 1][N - 1] = '%';

    int pacmanX = 0;
    int pacmanY = 0;
    unsigned int steps = 0;
    int command;

    while (pacmanX != N - 1 || pacmanY != N - 1) {
        printField(field);
        printf("Введите комманду (4 - влево, 8 - верх, 6 - вправо, 5 - вниз):");
        scanf("%d", &command);

        field[pacmanY][pacmanX] = '#';

        switch (command) {
            case 4:
                if (pacmanX > 0) pacmanX--;
                break;
            case 8:
                if (pacmanY > 0) pacmanY--;
                break;
            case 6:
                if (pacmanX < N - 1) pacmanX++;
                break;
            case 5:
                if (pacmanY < N - 1) pacmanY++;
                break;
            default:
                printf("Ошибка, неверная команда.\n");
                break;
        }

        field[pacmanY][pacmanX] = '^';
        steps++;
    }

    printf("Поздравляю! вы выйграли за : %d шагов", steps);


    return 0;
}
