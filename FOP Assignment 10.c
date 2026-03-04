#include <stdio.h>
#include <math.h>
int main()
{
int choice;
double x, y;


        printf("\nSIMPLE CALCULATOR\n");
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Division\n");
        printf("5. Power (x^y)\n");
        printf("6. Factorial (x!)\n");
        
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter two numbers: ");
                scanf("%lf %lf", &x, &y);
                printf("Result = %.2lf", x + y);
                break;

            case 2:
                printf("Enter two numbers: ");
                scanf("%lf %lf", &x, &y);
                printf("Result = %.2lf", x - y);
                break;

            case 3:
                printf("Enter two numbers: ");
                scanf("%lf %lf", &x, &y);
                printf("Result = %.2lf", x * y);
                break;

            case 4:
                printf("Enter two numbers: ");
                scanf("%lf %lf", &x, &y);
                if (y != 0)
                    printf("Result = %.2lf", x / y);
                else
                    printf("Error: Division by zero!");
                break;

            case 5:
                printf("Enter base and exponent: ");
                scanf("%lf %lf", &x, &y);
                printf("Result = %.2lf", pow(x, y));
                break;

            case 6:
            {
                int n;
                float fact=1;
                printf("Enter a number: ");
                scanf("%d", &n);
                if (n < 0)
                printf("Factorial not defined for negative numbers!");
                else
                {
                 for (int i = 1; i <= n; i++)
                 {
                     fact = fact* i;
                 }
                    printf("Result = %.2f", fact);
                break;
            }

            default:
                printf("Invalid choice! Try again.");
        }


    return 0;
 }
}