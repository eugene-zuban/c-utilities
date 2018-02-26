#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>

#define MIN_BASE 2
#define MAX_BASE 16
#define MAX_INT_BITS 32

char *decToBase(int32_t number, int32_t base) {
    if (base < MIN_BASE || base > MAX_BASE) {
        fprintf(stderr, "Unsupported base\n");
        exit(EXIT_FAILURE);
    }

    const char baseDigits[] = {"0123456789ABCDEF"};
    char *buffer = (char *) calloc(sizeof(char), MAX_INT_BITS + 1);
    if (buffer == NULL) {
        fprintf(stderr, "Memory allocation error\n");
        exit(EXIT_FAILURE);
    }

    int offset = MAX_INT_BITS - 1;
    do {
        buffer[offset--] = baseDigits[number % base];
        number /= base;
    } while (number != 0);

    return buffer + offset + 1;
}

int main(void) {
    int32_t number, base;
    bool isActive = true;
    char answer;

    while(isActive) {
        printf("Please enter number to convert: ");
        scanf("%i", &number);
        printf("Please enter base: ");
        scanf("%i", &base);

        printf("Result: %s\n", decToBase(number, base));
        printf("Do you want to convert another number [Y/N]?: ");
        scanf(" %c", &answer);
        isActive = (answer == 'Y');
    }

    return 0;
}

