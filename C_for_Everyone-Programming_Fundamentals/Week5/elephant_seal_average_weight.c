#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp;
    long int sum = 0;
    int count = 0;
    float average;
    int *buff = (int *)malloc(1000 * sizeof(int));

    fp = fopen("elephant_seal_data.txt", "r");
    //check if file can be read
    if(fp == NULL){
        printf("File not found.\n");
        return -1;
    }

    //reading from file
    while(fscanf(fp, "%d", buff) != EOF){
        count++;
        sum += *buff;
    }
    average = (float)sum / (float)count;
    printf("The average weight: %f\n", average);
    fclose(fp);
    return 0;
}