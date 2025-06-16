#include <stdio.h>
#include <stdlib.h>

// safely reads and validates integer input using fgets + sscanf
// fgets() is safer than scanf() as it avoids buffer overflow by respecting size limit
int get_valid_int(const char *prompt) {
    // create char array (string buffer) to store user input from fgets()
    char buffer[100];  

    // stores int entered by user, after parsing from input buffer
    int value;
    
    while (1) {  // 1 is always true in C, creating endless loop
        printf("%s", prompt);

        // read full line of input from user into buffer; returns NULL if input fails
        if (fgets(buffer, sizeof(buffer), stdin)) {  
            // attempt to parse int from input; check that exactly 1 valid int was read
            if (sscanf(buffer, "%d", &value) == 1) {  
                return value;
            } else {
                printf("Invalid input. Please enter a valid integer.\n");
            }
        }
    }
}

int main() {
    int choice;
    int num1, num2;
    int result;

    while (1) {  
        // calculator menu
        printf("\n- Simple Calculator -\n");
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Division\n");
        printf("5. Modulus\n");
        printf("6. Exit\n");

        // use validated input for menu selection
        choice = get_valid_int("Enter your choice (1-6): ");

        if (choice == 6) {
            printf("Exiting calculator.\n");
            break;
        }

        if (choice < 1 || choice > 6) {
            printf("Invalid choice. Please try again.\n");
            continue;
        }

        num1 = get_valid_int("Enter the first integer of the operation: ");
        num2 = get_valid_int("Enter the second integer of the operation: ");

        switch (choice) {
            case 1:
                // addition 
                result = num1 + num2;
                printf("Result: %d + %d = %d\n", num1, num2, result);
                break;
            case 2:
                // subtraction 
                result = num1 - num2;
                printf("Result: %d - %d = %d\n", num1, num2, result);
                break;
            case 3:
                // multiplication 
                result = num1 * num2;
                printf("Result: %d * %d = %d\n", num1, num2, result);
                break;
            case 4:
                // division
                if (num2 == 0) {
                    printf("Error: Division by zero is not allowed in C.\n");
                } else {
                    result = num1 / num2;
                    printf("Result: %d / %d = %d\n", num1, num2, result);
                }
                break;
            case 5:
                // modulus
                if (num2 == 0) {
                    printf("Error: Modulus by zero is not allowed.\n");
                } else {
                    result = num1 % num2;
                    printf("Result: %d %% %d = %d\n", num1, num2, result);
                }
                break;
        }
    }

    return 0;
}
