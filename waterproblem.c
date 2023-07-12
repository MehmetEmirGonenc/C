#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
    printf("Please enter an array size: ");
    int size = 0;
    scanf("%i",&size);
    //Allocating memory
    int *values = malloc(sizeof(int) * size);
    //Get values
    for(int i = 0; i < size; i++)
    {
        printf("%i. element >> ",i+1);
        scanf("%i",&values[i]);
    }

    int tmp0 = 0, tmp1 = 0, counter = 1, resault = 0;
    for (int i = 0; i < size; i++)
    {
        if (values[i] > values[i+1])
        {
            counter++;
        }
        else
        {
            for (int j = counter; j > 0; j--)
            {
                if (values[i+1] >= values[i+1-j])
                {
                    printf("%i^^\n",values[i]);
                    int blocks = 0;
                    for (int h = (i+1-j)+1; h < i+1; h++)
                    {
                        blocks += values[h];
                    }
                    resault += (values[i+1-j]*(counter-1))-blocks;
                    printf("%i    %i\n", resault,blocks);
                    break;
                }
            }
        }
    }
    printf("%i\n", resault);
    free(values);
    return 0;
}