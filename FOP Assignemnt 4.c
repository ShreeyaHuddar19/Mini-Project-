#include <stdio.h>

int main() {
   float basic, hra, ta, gross, tax, net;

    printf("Enter basic salary: ");
    scanf("%f", &basic);
    hra = (10 * basic)/100;  
    ta  = (5 *basic)/100;   

    gross = basic + hra + ta;

    tax = 0.02 * gross;

    net = gross - tax;
    
    printf("\nNet Salary Payable: %.2f\n", net);

    return 0;
}