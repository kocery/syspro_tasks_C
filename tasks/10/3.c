#include <stdio.h>
#include <string.h>
#include <malloc.h>

typedef struct {
    size_t len;
    size_t capacity;
    char **arr;
} dyn_arr;

void nullCheck(void *ptr) {
    if (ptr == NULL) {
        printf("Out of memory!");
        exit(0);
    }
}

char *trim(const char *string) {
    size_t left = 0;
    size_t right = strlen(string) - 1;

    while (string[left] == ' ' || string[right] == ' ') {
        if (left == right) {
            char *out = (char *) malloc(sizeof(char));
            nullCheck(out);
            *out = '\0';
            return out;
        }
        if (string[left] == ' ') {
            left++;
        } else {
            right--;
        }
    }

    char *out = (char *) malloc((right - left + 2) * sizeof(char));
    nullCheck(out);

    for (size_t i = left; i <= right; i++) out[i - left] = string[i];
    out[right - left + 1] = '\0';

    return out;
}

dyn_arr split(const char *string) {
    size_t len = strlen(string) - 1;
    dyn_arr arr;
    arr.capacity = 2;
    arr.len = 0;
    arr.arr = (char **) malloc(sizeof(char *));
    nullCheck(arr.arr);

    for (size_t i = 0; i < len; i++) {
        if (string[i] == ' ') {
            continue;
        }

        size_t w_len = 0;

        while (string[i + w_len] != ' ' && i + w_len < len) {
            w_len++;
        }

        char *word = (char *) malloc((w_len + 1) * sizeof(char));
        nullCheck(word);

        for (size_t j = 0; j <= w_len; j++) {
            word[j] = string[j + i];
        }

        word[w_len + 1] = '\0';
        arr.arr[arr.len] = word;
        arr.len += 1;

        if (arr.len == arr.capacity) {
            arr.capacity *= 2;
            arr.arr = (char **) realloc(arr.arr, arr.capacity * sizeof(char *));
            nullCheck(arr.arr);
        }
        i += w_len;
    }

    return arr;
}

int main() {
    char string[256];

    scanf("%[^\n]", string);
    char *out = trim(string);
    dyn_arr arr = split(out);

    for (size_t i = 0; i < arr.len; i++) {
        printf("%s\n", arr.arr[i]);
        free(arr.arr[i]);
    }

    free(arr.arr);
    return 0;
}