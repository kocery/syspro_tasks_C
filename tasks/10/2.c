#include <stdio.h>
#include <string.h>

void nullCheck(void *ptr) {
    if (ptr == NULL) {
        printf("Out of memory!");
        exit(0);
    }
}

char *trim(const char *line) {
    size_t left = 0;
    size_t right = strlen(line) - 1;

    while (line[left] == ' ' || line[right] == ' ') {
        if (left == right) {
            char *out = (char *) malloc(sizeof(char));
            nullCheck(out);
            *out = '\0';
            return out;
        }
        if (line[left] == ' ') {
            left++;
        } else {
            right--;
        }

    }

    char *out = (char *) malloc((right - left + 2) * sizeof(char));
    nullCheck(out);

    for (size_t i = left; i <= right; i++) out[i - left] = line[i];
    out[right - left + 1] = '\0';

    return out;
}

int main() {
    char string[128];

    scanf("%[^\n]", string);
    printf("%s", trim(string));
    return 0;
}