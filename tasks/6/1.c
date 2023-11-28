#include <stdio.h>

void printArr(int *arr, size_t len) {
    for (size_t i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void scanArr(int *arr, size_t len) {
    for (size_t i = 0; i < len; i++) {
        int num;
        scanf("%i", &num);
        arr[i] = num;
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
    size_t min;
    if (len1 > len2) {
        min = len2;
    } else {
        min = len1;
    }

    for (size_t i = 0; i < min; i++) {
        if (arr1[i] < arr2[i]) {
            return -1;
        }
        if (arr1[i] > arr2[i]) {
            return 1;
        }
    }

    if (len1 < len2) {
        return -1;
    }
    if (len1 > len2) {
        return 1;
    }

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
        printf("%i test\n", k);
        X %= k;
    }
}

int main() {
    int arr1[5];
    int arr2[] = {1, 2, 3, 4, -5};
    size_t len1 = sizeof(arr1) / sizeof(arr1[0]);
    size_t len2 = sizeof(arr2) / sizeof(arr2[0]);

    scanArr((int *) &arr1, len1);
    printArr((int *) &arr1, len1);
    printf("%i in arr\n", maxInArr((int *) &arr1, len1));

    if (findInArr((int *) &arr1, len1, 1) == -1) {
        printf("NULL: number not in arr\n");
    } else {
        printf("%i find in arr\n", findInArr((int *) &arr1, len1, 1));
    }

    printf("%i comp arr\n", compareArrays((int *) &arr1, len1, (int *) &arr2, len2));
    revertArr((int *) &arr1, len1);
    extractDigits((int *) &arr1, len1, 998);
    printArr((int *) &arr1, len1);
}

