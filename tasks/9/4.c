#include <stdio.h>
#include <malloc.h>

void nullCheck(void *ptr) {
    if (ptr == NULL) {
        printf("Out of memory!");
        exit(0);
    }
}

void print_tri(size_t len, int **arr) {
    for (size_t i = 0; i < len; i++) {
        for (size_t j = 0; j <= i; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

int create_tri(size_t len, int ***out) {
    int **arr = (int **) malloc(len * sizeof(int *));
    nullCheck(arr);
    for (size_t i = 0; i < len; i++) {
        arr[i] = (int *) malloc((i + 1) * sizeof(int));
        nullCheck(arr);
    }
    *out = arr;
    return len;
}

void fill_tri(size_t len, int **arr) {
    arr[0][0] = 1;
    for (size_t i = 1; i < len; i++) {
        arr[i][0] = 1;
        arr[i][i] = 1;
        for (size_t j = 1; j < i; j++) {
            arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
        }
    }
}


int main() {
    size_t len;
    scanf("%lld", &len);
    int **arr;
    create_tri(len, &arr);
    fill_tri(len, arr);
    print_tri(len, arr);

    for (size_t i = 0; i < len; i++) {
        free(arr[i]);
    }
    free(arr);

    return 0;
}
