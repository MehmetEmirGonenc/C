#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        printf("True usage: ./TextStatues <filename>\n");
        return 1;
    }
    int characters[26];
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("File could not open.\n");
        return 2;
    }
    uint8_t buffer[5];
    fread(&buffer, sizeof(uint8_t)*5, 1,input);
    printf("%i  %i  %i  %i  %i",buffer[0],buffer[1],buffer[2],buffer[3],buffer[4]);
    //Read header of file
    uint8_t h_buffer[3];
    fread(&h_buffer, sizeof(uint8_t) * 3,1 ,input);
    if((h_buffer[1] == 253 || h_buffer[1] == 254 || h_buffer[1] == 255) && h_buffer[2] == 127)
    {      
    }
    else
    {
        printf("Unsupported file type!\n");
        fclose(input);
        return 3;
    }
    char bbuffer;
    while(fread(&bbuffer, sizeof(char), 1, input))
    {
        
    } 
}