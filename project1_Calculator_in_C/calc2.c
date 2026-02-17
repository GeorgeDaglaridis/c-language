#include <stdio.h>

int add(float a, float b);
int subtract(float a, float b);
int multiply(float a, float b);
int divide(float a, float b);

int add(float a, float b) {
    int success = 1;

    float ans = a + b;
    printf("%.2f + %.2f = %.2f\n", a, b, ans);

    return success;
}

int subtract(float a, float b) {
    int success = 1;

    float ans = a - b;
    printf("%.2f - %.2f = %.2f\n", a, b, ans);

    return success;
}

int multiply(float a, float b) {
    int success = 1;

    float ans = a * b;
    printf("%.2f * %.2f = %.2f\n", a, b, ans);

    return success;
}

int divide(float a, float b) {
    int success = 1;
    int div_by_zero_error = 0;

    float ans  = 0.0;
    if(b == 0.0) {
        div_by_zero_error = 1;
        printf("Error: Division by zero is not allowed!\n");
    } else {
        ans = a / b;
        printf("%.2f / %.2f = %.2f\n", a, b, ans);
    }
    
    // Not very nice coding ...
    if (div_by_zero_error == 1) {
        success = 0;
    }

    return success;
}

/*
void add(float a, float b);
void subtract(float a, float b);
void multiply(float a, float b);
void divide(float a, float b);
int check_op_validity(char math_op);

void add(float a, float b) {
    float ans = a + b;
    printf("%.2f + %.2f = %.2f\n", a, b, ans);
}

void subtract(float a, float b) {
    float ans = a - b;
    printf("%.2f - %.2f = %.2f\n", a, b, ans);
}

void multiply(float a, float b) {
    float ans = a * b;
    printf("%.2f * %.2f = %.2f\n", a, b, ans);
}

void divide(float a, float b) {
    float ans  = 0.0;
    if(b == 0.0) {
        printf("Error: Division by zero is not allowed!\n");
    } else {
        ans = a / b;
        printf("%.2f / %.2f = %.2f\n", a, b, ans);
    }    
}
*/

/*
int check_op_validity(char math_op) {
    int is_valid = 0;
    if(math_op == '+') {
        is_valid = 1;

    } else if(math_op == '-') {
        is_valid = 1;

    } else if(math_op == '*') {
        is_valid = 1;

    } else if(math_op == '/') {
        is_valid = 1;

    } else {
        printf("Operation is not valid!\n");
    }
    return is_valid;
}
// Alternative
int check_op_validity(char math_op) {
    int is_valid = 1;
    if( (math_op != '+') | (math_op != '-') | 
              (math_op != '*') | (math_op != '/') ) {
        is_valid = 0;
        printf("Operation is not valid!\n");

    }
    return is_valid;
}
*/

void main() {

    float fnum1 = 0.0, fnum2 = 0.0, ans = 0.0;
    char op = '!';
    char restart_calc = 'n';

    printf("Welcome to the Calculator Program\n");
    
    do {
        // Do not enter for a subsequent time unless prompted
        restart_calc = 'n';

         // Clear inputs
        fnum1 = 0.0;    
        fnum2 = 0.0;

        printf("Enter first f.p number: ");
        scanf("%f", &fnum1);
        printf("Enter second f.p number: ");
        scanf("%f", &fnum2);

        // 0: no valid op, 1: valid op 
        int is_op_valid = 1;
        int div_by_zero_error = 0;  
        do{
            // Clear inputs/outputs
            op = '!'; // assign sth not valid
            ans = 0.0;

            printf("Enter operation (+, -, *, /): ");
            scanf(" %c", &op);
        
            // Execute one of the valid operations
            is_op_valid = 1; 
            switch (op)
            {
                case '+':
                    is_op_valid = add(fnum1, fnum2);
                    break;

                case '-':
                    is_op_valid = subtract(fnum1, fnum2);
                    break;

                case '*':
                    is_op_valid = multiply(fnum1, fnum2);
                    break;

                case '/':
                    is_op_valid = divide(fnum1, fnum2);
                    // Not very nice coding ...
                    if (is_op_valid == 0) {
                        div_by_zero_error = 1;
                    }
                    break;
            
                default:
                    is_op_valid = 0;
                    printf("Operation is not valid!\n");
                    break;
            }
            
            // Not very nice coding ...
            if (div_by_zero_error == 1) {
                break;
            }

        } while (is_op_valid != 1);

        printf("Would you like to calculate again? (y/n) ");
        scanf(" %c", &restart_calc);
    
    } while (restart_calc == 'y');

    printf("Thank you for using the Calculator Program. Goodbye!\n");

    return;
}