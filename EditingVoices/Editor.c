#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(int argc, char* argv[])
{
    FILE *input = fopen(argv[1], "r");

    uint8_t buffer[35];
    fread(&buffer, sizeof(uint8_t) * 35, 1, input);
    
    for (int i = 0; i < 35; i++)
    {
        printf("%i -->%u\n",i, buffer[i]);
    }
    fclose(input);
}