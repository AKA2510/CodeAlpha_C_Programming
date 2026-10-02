#include <stdio.h>

int main() {
    int choice;
    double a, b, result;

    printf("=== Simple Calculator ===\n");
    printf("Enter first number: ");
    scanf("%lf", &a);

    printf("Enter second number: ");
    scanf("%lf", &b);

    printf("\nChoose an operation:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            result = a + b;
            printf("Result = %.2lf\n", result);
            break;

        case 2:
            result = a - b;
            printf("Result = %.2lf\n", result);
            break;

        case 3:
            result = a * b;
            printf("Result = %.2lf\n", result);
            break;

        case 4:
            if (b == 0) {
                printf("Division by zero is not possible.\n");
            } else {
                result = a / b;
                printf("Result = %.2lf\n", result);
            }
            break;

        default:
            printf("Invalid choice.\n");
    }

    return 0;
}
