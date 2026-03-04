#include <stdio.h>

int main() 
{
     int choice;
    int a,b;
    printf("Enter to numbers to be operated on: ");
    scanf("%d""%d",&a,&b);
    
    printf("Menu:\n1.Addition\n2.Subtraction\n3.Multiplication\n4.Division\n");
    
    printf("Enter choice for operation: ");
    scanf("%d",&choice);
    
    switch(choice)
    {
        case 1:
            printf("%d+%d=%d",a,b,a+b );
            break;
        case 2:
            printf("%d-%d=%d",a,b,a-b);
            break;
        case 3:
            printf("%d*%d=%d",a,b,a*b);
            break;
        case 4:
            if (b != 0) 
            {
                printf("%d/%d=%d",a,b,a/b);
            } 
            else 
            {
                printf("Error: Division by zero is not allowed.\\n");
            }
            break;
        default:
            printf("Invalid operator"); 
            
    }

    return 0;
}