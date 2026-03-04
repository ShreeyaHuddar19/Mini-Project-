#include <stdio.h>

int main()
{
    int math, eng, chem, phy, comp, total;
    float percentage;

    printf("Enter marks of five courses:\n");
    printf("Enter marks of Mathematics:\n");
    scanf("%d",&math);
    printf("Enter marks of English:\n");
    scanf("%d",&eng);
    printf("Enter marks of Chemistry:\n");
    scanf("%d",&chem);
    printf("Enter marks of Physics:\n");
    scanf("%d",&phy);
    printf("Enter marks of Computer:\n");
    scanf("%d",&comp);

    if (math <= 40 || eng <= 40 || chem <= 40 || phy <= 40 || comp <= 40)
    printf("Fail");
    else
    {
    
        total = math + eng + chem + phy + comp;
        percentage = total / 5;
        printf("Total marks: %d",total);
        printf("\nResult: PASS");
        printf("\nAggregate Percentage = %.2f",percentage);
        
        if (percentage >= 75)
            printf("\nGrade: Distinction");
        else if (percentage >= 60)
            printf("\nGrade: First Division");
        else if (percentage >= 50)
            printf("\nGrade: Second Division");
        else
            printf("\nGrade: Third Division");
    }
 
   
    return 0;
    
}