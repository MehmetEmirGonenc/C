#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
    //Ensure inputs are true
    if (argc != 2)
    {
        printf("True usage ./fibonacci <how many terms to write>\n");
        return 1;
    }
    for (int i = 0; i < strlen(argv[1]); i++)
    {
        if (!argv[1][i] >= 48 && !argv[1][i] <= 57)
        {
            printf("Use just numbers\n");
            return 2;
        }
    }
    int term_number = atoi(argv[1]);
    long terms[term_number];

    //Calculate and write values
    for (int i = 0; i < term_number; i++)
    {
        if (i == 0)
        {
            terms[i] = 0;
            printf("Value %i --> %lu\n",i , terms[i]);
            continue;
        }
        if (i == 1)
        {
            terms[i] = 1;
            printf("Value %i --> %lu\n",i , terms[i]);
            continue;
        }
        terms[i] = terms[i-1] + terms[i-2];
        printf("Value %i --> %lu\n",i , terms[i]);
    }
}