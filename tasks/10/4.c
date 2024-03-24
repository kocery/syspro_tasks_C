#include <setjmp.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>

void exception(jmp_buf buf, int code, const char *info) {
    if (buf != NULL) {
        longjmp(buf, code);
    } else {
        printf("%s", info);
        exit(0);
    }
}

unsigned int custom_pow(unsigned int a, unsigned int b, unsigned int limit, jmp_buf buf) {
    unsigned int out = 1;
    for (int i = 0; i < b; i++) {
        if (out * a >= limit) {
            exception(buf, 1, "overflow");
        }
        out *= a;
    }
    return out;
}

int s2i(const char *string, int base, jmp_buf buf) {
    int len = strlen(string);
    const char alphabet[17] = "0123456789ABCDEF";
    const char alphabet2[17] = "0123456789abcdef";

    int sign = 1;
    if (string[0] == '-') {
        sign = -1;
        len--;
    }

    unsigned int limit = INT_MAX;

    unsigned int n = 0;
    for (int i = sign > 0 ? 0 : 1; i < len; i++) {
        for (int j = 0; j <= base; j++) {
            if (base == j) {
                exception(buf, 2, "wrong input");
            }

            if (string[i] == alphabet[j] || string[i] == alphabet2[j]) {
                unsigned int k = custom_pow(base, len - i - 1, limit, buf) * j;
                n += k;
                if (n >= limit) {
                    exception(buf, 1, "overflow");
                }
                break;
            }
        }
    }
    return n * sign;
}

int main() {
    printf("Enter your string: ");
    char string[128];
    scanf("%s", string);

    printf("Enter your base: ");
    int base;
    scanf("%d", &base);

    jmp_buf buf;
    int code = setjmp(buf);
    if (code != 0) {
        printf("%s", code == 1 ? "overflow" : "wrong input");
        exit(0);
    }

    printf("%d", s2i(string, base, buf));
    return 0;
}