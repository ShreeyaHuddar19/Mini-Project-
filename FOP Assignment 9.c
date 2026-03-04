#include <stdio.h>
#include <math.h>
int main()
{
    int num, digit = 0, remainder, n;
    int sum = 0, temp;

    printf("Enter a number: ");
    scanf("%d", &num);

    n = num;
    temp = num;

    while (temp > 0)
    {
        digit++;
        temp = temp / 10;
    }

    while (num > 0)
    {
        remainder = num % 10;
        sum = sum + pow(remainder, digit);
        num = num / 10;
    }

    if (sum == n)
        printf("%d is an Armstrong number.", n);
    else
        printf("%d is not an Armstrong number.", n);

    return 0;
    
}