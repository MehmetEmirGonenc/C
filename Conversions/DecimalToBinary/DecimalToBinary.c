//Coded by : Mehmet Gönenç
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char* argv[])
{
    //Check inputs
    if (argc != 2)
    {
        printf("True usage ./DecimalToBinary <number>\n");
        return 1;
    }
    int number = atoi(argv[1]);
    int x = 0;
    while (pow(2,x) <= number)
    {
        x++;
    }

    for (int i = x-1; i >= 0;i--)
    {
        if (pow(2,i) <= number)
        {
            printf("1");
            number -= pow(2,i);
        }
        else
        {
            printf("0");
        }
    }
    printf("\n");
    // Make Command : : gcc -o DecimalToBinary DecimalToBinary.c -lm
}