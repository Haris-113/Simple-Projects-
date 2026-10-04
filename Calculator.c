#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

/* Global variable — visible in ELF symbol table */
const char *program_name = "ELF Calculator";
int operation_count = 0;

double add(double a, double b)      { return a + b; }
double subtract(double a, double b) { return a - b; }
double multiply(double a, double b) { return a * b; }
double divide(double a, double b) {
    if (b == 0.0) {
        fprintf(stderr, "Error: division by zero\n");
        return 0.0;
    }
    return a / b;
}

void print_result(const char *op, double result) {
    operation_count++;
    printf("%s = %.2f (op #%d)\n", op, result, operation_count);
}

int main(void) {
    double a = 9.0, b = 3.0;

    printf("Program: %s\n", program_name);
    printf("----------------------------\n");

    char buf[64];
    snprintf(buf, sizeof(buf), "%.1f + %.1f", a, b);
    print_result(buf, add(a, b));

    snprintf(buf, sizeof(buf), "%.1f - %.1f", a, b);
    print_result(buf, subtract(a, b));

    snprintf(buf, sizeof(buf), "%.1f * %.1f", a, b);
    print_result(buf, multiply(a, b));

    snprintf(buf, sizeof(buf), "%.1f / %.1f", a, b);
    print_result(buf, divide(a, b));

    printf("sqrt(%.1f) = %.4f\n", a, sqrt(a));
    printf("Total operations: %d\n", operation_count);
    return 0;
}
