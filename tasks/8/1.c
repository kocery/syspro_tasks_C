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

size_t findInArr(int *arr, size_t len, int x) {
    for (size_t i = 0; i < len; i++) {
        if (arr[i] == x) {
            return i;
        }
    }

    return -1;
}

int maxInArr(int *arr, size_t len) {
    int max;
    for (size_t i = 0; i < len; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    return max;
}

void revertArr(int *arr, size_t len) {
    for (size_t i = 0; i < len / 2; i++) {
        int swap = arr[i];
        arr[i] = arr[len - 1 - i];
        arr[len - 1 - i] = swap;
    }
}

int compareArrays(int *arr1, size_t len1, int *arr2, size_t len2) {
    size_t min = (len1 < len2) ? len1 : len2;

    for (size_t i = 0; i < min; i++) {
        if (arr1[i] < arr2[i]) return -1;
        if (arr1[i] > arr2[i]) return 1;
    }

    if (len1 < len2) return -1;
    if (len1 > len2) return 1;

    return 0;
}

void extractDigits(int *arr, size_t len, int X) {
    int numDigits = 0;
    int temp = X;

    while (temp > 0) {
        numDigits++;
        temp /= 10;
    }

    for (size_t i = 0; i < numDigits; i++) {
        int k = 1;

        for (int j = 0; j < numDigits - 1 - i; j++) {
            k *= 10;
        }

        arr[len - 1 - i] = X / k;
        X %= k;
    }
}

int main() {
    size_t len1;
    size_t len2;
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
    scanArr(arr2, len1);
    printArr(arr1, len1);
    printArr(arr2, len2);
    printf("%i in arr\n", maxInArr(arr1, len1));

    if (findInArr(arr1, len1, 1) == -1) {
        printf("NULL: number not in arr\n");
    } else {
        printf("%zu find in arr\n", findInArr(arr1, len1, 1));
    }

    printf("%i comp arr\n", compareArrays(arr1, len1, arr2, len2));
    revertArr(arr1, len1);
    extractDigits(arr1, len1, 998);
    printArr(arr1, len1);

    free(arr1);
    free(arr2);
}
