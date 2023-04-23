//Option 1
#include <stdio.h>

double get_average(int d[], int size)
{
    int i;
    double avg = 0.0;
    
    for(i=0; i<size; i++)
    {
        avg += d[i];
    }
    return (avg / size);
}

int get_max(int d[], int size)
{
    int max = d[0];
    int i;
    for(i=1; i<size; i++)
    {
        if(max < d[i]) 
            max = d[i];
    }
    return max;
}

int main()
{
    FILE *ifp, *ofp;
    int i, max;
    int size = 0;
    double average;

    ifp = fopen("/home/coder/project/Week 4/numbers.txt", "r");
    ofp = fopen("answer-hw3.txt", "w");

    if(!ifp)
    {
        printf("File cannot be opened.\n");
        return -1;
    }
    rewind(ifp);
    fscanf(ifp, "%d", &size);
    int data[size];

    for(i=0; i<size; i++)
    {
        fscanf(ifp, "%d", &data[i]);
    }
    average = get_average(data, size);
    printf("Average: %f\n", average);
    fprintf(ofp, "Average: %f\n", average);

    max = get_max(data, size);
    printf("Max: %d\n", max);
    fprintf(ofp, "Max: %d\n", max);

    fclose(ifp);
    fclose(ofp);
    return 0;
}