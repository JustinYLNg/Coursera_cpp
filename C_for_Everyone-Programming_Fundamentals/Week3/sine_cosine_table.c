#include <stdio.h>
#include <math.h>

int main(void)
{
    //Print a table of values for sine and cosine between (0,1)
    float sinValue, cosValue, interval;
    for (int i = 0; i < 10; i++)
    {
        interval = i / 10.0;
        sinValue = sin(interval);
        cosValue = cos(interval);
        printf("sin(%f) is: %f, cos(%f) is: %f\n", interval, sinValue, interval, cosValue);
    }
    return 0;
}