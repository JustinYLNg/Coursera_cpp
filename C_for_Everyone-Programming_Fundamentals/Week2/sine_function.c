#include <stdio.h>
#include <math.h>

#define PI 3.14159

int main(void)
{
    float number, result;
    printf("Enter a number between 0 and 1 to calculate sine value: ");
    scanf("%f", &number);
    result = sin(number);
    printf("\nThe sine value of %f is: %f\n", number, result);

    return 0;
}