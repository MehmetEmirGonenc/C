#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(int argc, char* argv[])
{
    // Parameter e = capitalize every letter.
    // Parameter f = capitalize every first letter of words.

    if (argc != 3)
    {
        printf("True usage ./TextCapital <parameter(e , f)> first.txt\n");
        return 1;
    }

    if(strcmp(argv[1], "e") == 0)
    {
        unsigned char buffer;
        int counter = 0;
        FILE *input = fopen(argv[2], "r");
        FILE *output = fopen("output.txt", "w");
        
        while (fread(&buffer, sizeof(unsigned char), 1, input))
        {
            if (!isalpha(buffer))
            {
                fwrite(&buffer, sizeof(unsigned char), 1, output);
                continue;
            }
            if (islower(buffer))
            {    
                buffer = toupper(buffer); 
                fwrite(&buffer, sizeof(unsigned char), 1, output);
            }
        }
        fclose(input);
        fclose(output);
    }
    else if(strcmp(argv[1], "f") == 0)
    {
        unsigned char buffer;
        int counter = 0;
        FILE *input = fopen(argv[2], "r");
        FILE *output = fopen("output.txt", "w");
        
        fread(&buffer, sizeof(unsigned char), 1, input);
        buffer = toupper(buffer);
        fwrite(&buffer, sizeof(unsigned char), 1, output);

        while (fread(&buffer, sizeof(unsigned char), 1, input))
        {
            if (buffer == 32)
            {    
                fwrite(&buffer, sizeof(unsigned char), 1, output);
                fread(&buffer, sizeof(unsigned char), 1, input);
                buffer = toupper(buffer);
                fwrite(&buffer, sizeof(unsigned char), 1, output);
            }
            else
            {
                fwrite(&buffer, sizeof(unsigned char), 1, output);
            }
        }
        fclose(input);
        fclose(output);
    }
    else
    {
        printf("Wrong parameter, try 'e' or 'f'\n");
        return 2;
    }
}
