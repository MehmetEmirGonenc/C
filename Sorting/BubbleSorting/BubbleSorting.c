#include <stdio.h>

int main ()
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
    //Sorting with bubble method
    for (int i = 0; i < number; i++)
    {
        for (int j = 0; j < number - 1; j++)
        {
            //Swapping (if first number is bigger than second, swap them)
            if (values[j] > values[j+1])
            {
                int tmp = values[j];
                values[j] = values[j+1];
                values[j+1] = tmp;
            }
        }
    }
    //Print sorted values 
    printf("\nSorted Values : \n");
    for (int i = 0; i < number; i++)
    {
        printf("Value %i --> %i\n", i, values[i]);
    }
    return 0;
}