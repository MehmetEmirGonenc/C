#include <stdio.h>

int main()
{
    printf("Please enter number of values : ");
    int number = 0;
    int x = scanf("%i", &number);
    int values[number];
    //Checking number
    if (x == 1)
    {
        for (int i = 0; i < number; i++)
        {
            //Checking intager
            while (1)
            {
                printf ("Value %i : ", i+1);
                int y = scanf ("%i", &values[i]);
                if (y == 1)
                {
                    break;
                }
            }
        }
    } 
    else
    {
        printf ("Please enter a number!\n");
        return 1; 
    }
    //Sorting
    for (int i = 0; i < number; i++)
    {
        //create temporary variables 
        int min = i, temp = 0;
        //check every element of array
        for (int j = i; j < number; j++)
        {
            if (values[min] > values[j])
            {
                min = j;
            }
        }
        //Change values
        temp = values[i];
        values[i] = values[min];
        values[min] = temp;
        //Print output
        if (i == 0)
        {
            printf("\nSorted numbers :\n");
        }
        printf("Value %i --> %i\n",i+1,values[i]);
    }
}