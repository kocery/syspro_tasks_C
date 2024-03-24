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

void scanArr(int *arr, size_t len) {
    for (size_t i = 0; i < len; i++) {
        scanf("%i", &arr[i]);
    }
}

int *findSubArr(int *arr1, int *arr2, size_t len1, size_t len2) {
    for (size_t i = 0; i < len1 - len2 + 1; i++) {
        for (size_t j = 0; j < len2; j++) {
            if (arr1[i + j] != arr2[j]) break;
            if (j == len2 - 1) return &arr1[i];
        }
    }
    return NULL;
}

int removeSubArr(int **arr1, size_t len1, int *arr2, size_t len2) {
    int *sub_arr;
    sub_arr = findSubArr(*arr1, arr2, len1, len2);
    while (sub_arr != NULL) {
        len1 -= len2;
        for (size_t i = 0; i < len1; i++) {
            sub_arr[i] = sub_arr[i + len2];
        }
        sub_arr = findSubArr(*arr1, arr2, len1, len2);
    }
    *arr1 = (int *) realloc(*arr1, len1 * sizeof(int));
    nullCheck(*arr1);
    return len1;
}

int main() {
    size_t len1, len2;
    printf("enter your first array length: ");
    scanf("%zi", &len1);
    printf("enter your second array length: ");
    scanf("%zi", &len2);
    int *arr1 = (int *) malloc(len1 * sizeof(int));
    int *arr2 = (int *) malloc(len2 * sizeof(int));
    nullCheck(&arr1);
    nullCheck(&arr2);

    printf("enter your first array: ");
    scanArr(arr1, len1);
    printf("enter your second array: ");
    scanArr(arr2, len2);

    len1 = removeSubArr(&arr1, len1, arr2, len2);
    printArr(arr1, len1);

    free(arr1);
    free(arr2);
    return 0;
}
