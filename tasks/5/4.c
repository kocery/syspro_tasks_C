#include <stdio.h>

typedef struct {
    int aa;
    double bb;
    char cc[100];
} ExampleStruct;

void AutoStorage() {
    ExampleStruct es;

    int a;
    float b;
    char c[10];

    size_t size_a = sizeof(a);
    size_t size_b = sizeof(b);
    size_t size_c = sizeof(c);
    size_t size_es = sizeof(es);

    // Общий размер переменных в функции
    size_t total_size_of_variables = size_a + size_b + size_c + size_es;

    // Добавляем размер служебной информации ДЛЯ 64 БИТНОЙ СИСТЕМЫ 8 БАЙТ ДЛЯ 32 БИТНОЙ 4 БАЙТА
    size_t size_of_return_address = sizeof(void *);
    size_t size_of_frame_pointer = sizeof(void *);

    // Оценка служебной информации стека
    size_t total_overhead = size_of_return_address + size_of_frame_pointer;

    // Общий размер, который будет использован в стеке
    size_t total_stack_usage = total_size_of_variables + total_overhead;

    printf("Total size of local variables: %zu bytes\n", total_size_of_variables);
    printf("Total overhead for return address and frame pointer: %zu bytes\n", total_overhead);
    printf("Total estimated stack usage: %zu bytes\n", total_stack_usage);
}

int main() {
    AutoStorage();
    return 0;
}
