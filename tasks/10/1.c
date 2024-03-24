#include <stdio.h>
#include <string.h>

int ispalindrom(const char *line) {
    size_t right = strlen(line) - 1;

    for (size_t left = 0; left <= right / 2; left++) {
        if (line[left] == ' ')
            right++;
        else if (line[right] == ' ')
            left--;
        else if (line[left] != line[right])
            return 0;
        right--;
    }
    return 1;
}

int main() {
    char string[128];

    scanf("%[^\n]", string);
    printf("%s", ispalindrom(string) ? "Yes!" : "No :(");
    return 0;
}