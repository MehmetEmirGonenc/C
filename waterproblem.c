#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    printf("Please enter an array(divide every number with [,]): ");
    char* input;
    scanf("%s",input);
    //Allocating memory for dynamic array
    int *values = malloc(sizeof(int) * (strlen(input)/2));
    for (int i = 0; i < strlen(input); i++)
    {
        //Detecting every elements and pass commas and spaces
        if(input[i] == "," || input[i] == " ")
        {
            continue;
        }
        //Control the input is number by using ASCII codes
        else if(input[i] <= 57 && input[i] >=48)
        {
            values[i] = atio(input[i]);
        }
        else
        {
            printf("ERROR, you have to input just numbers and comma and space!");
            return 1;
        }
    }
    
}