#include <stdio.h>
#include <malloc.h>

void nullCheck(void *ptr) {
    if (ptr == NULL) {
        printf("Out of memory!");
        exit(0);
    }
}

void printArr(int *arr, size_t len) {
    printf("Your array: \n");
    for (size_t i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

size_t scanArr(int **out_arr, size_t *out_capacity) {
    int inp;
    size_t cap = 2;
    int *arr = (int *) malloc(cap * sizeof(int));
    nullCheck(arr);
    for (size_t i = 0;; i++) {
        scanf("%d", &inp);

        if (inp == 0) {
            *out_arr = arr;
            *out_capacity = cap;
            return i;
        }

        if (i == cap) {
            cap *= 2;
            arr = (int *) realloc(arr, cap * sizeof(int));
            nullCheck(arr);
        }

        arr[i] = inp;
    }
}


int main() {
    int *arr;
    size_t capacity;
    size_t len = scanArr(&arr, &capacity);

    printArr(arr, len);
    free(arr);

    return 0;
}
