#include <math.h>
#include <stdio.h>


int main() 
{
    printf("Please enter number of values : ");
    int number = 0;
    int is_int = scanf("%i",&number);
    //Ensure input is integer
    if (is_int == 0)
    {
        printf("Please enter a number!\n");
        return 1;
    }
    int values[number];
    for (int i = 0; i < number; i++)
    {
        //Checking integer
        printf ("Value %i : ", i+1);
        if (!scanf ("%i", &values[i]))
        {
            printf("Please enter just numbers!\n");
            return 2;
        }
    }
    //Sorting
    int x = round(log2(number));
    int y = round(number/(x-1));
    int parts[x][y][number];
    for (int i = 1; i <= x; i++)
    {
        int layer = pow(2,i);
        int counter = 0;
        for (int j = 0; j < number-layer; j+=layer)
        {
            if (counter == 2)
            {
                continue;
            }
            if (values[j] < values[j+(layer/2)])
            {
                int tmp = values[j];
                values[j] = values[j+(layer/2)];
                values[j+(layer/2)] = tmp;
            }
            printf("\n\n%i--%i--%i--%i--%i--%i--%i--%i (layer : %i) (counter : %i) (j : %i)\n\n\n",values[0]
            ,values[1],values[2],values[3],values[4],values[5],values[6],values[7],layer,counter,j);
            counter++;
        }
    }
    //Print to screen
    for (int i = 0; i < number; i++)
    {
        printf("\n%i -->%i\n",i+1,values[i]);
    }
    //Make : gcc -o MergeSorting MergeSorting.c -lm
}