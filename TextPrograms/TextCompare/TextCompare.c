#include <stdio.h>

int main(int argc, char* argv[])
{
    if ( argc != 3)
    {
        printf("True usage ./TextCompare First.txt Second.txt\n");
        return 1;
    }
    
    FILE *first = fopen(argv[1], "r");
    FILE *second = fopen(argv[2], "r");

    unsigned char buffer1 ;
    unsigned char buffer2 ;
    
    int counter = 0;
    while (fread(&buffer1, sizeof(unsigned char), 1, first))
    {
        counter++;
        fread(&buffer2, sizeof(unsigned char), 1, second);
        if (buffer1 != buffer2)
        {
            printf("character %i is different (%c --> %c)\n", counter, buffer1, buffer2);
        }
        
    }

    fclose(first);
    fclose(second);
}