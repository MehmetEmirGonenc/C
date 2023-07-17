#include <stdio.h>
#include <stdlib.h>

void calc_characters(int array[], char character);

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        printf("True usage: ./TextStatues <filename>\n");
        return 1;
    }
    //Create Array for each characters
    int characters[28]; //First 26 element for each character on alphabet, after these 1 element for words and after that 1 element for senteces.
    //Set values as 0
    for(int i = 0; i < 28; i++)
    {
        characters[i] = 0;
    }

    //Open File
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("File could not open.\n");
        return 2;
    }
    
    //Read characters
    char buffer;
    while(fread(&buffer, sizeof(char), 1, input))
    {
        calc_characters(characters, buffer);
    } 

    //Print characters
    for(int i = 0; i < 26; i++)
    {
        printf("Number of %c : %i\n", 65 + i, characters[i]);
    }
    printf("Number of word : %i\n", characters[26]);
    printf("Number of sentences : %i\n", characters[27]);

    //Close file
    fclose(input);
}
void calc_characters(int array[], char character)
{
    if (array[26] == 0)
    {
        array[26]++;
    }
    //Count words by counting spaces
    if (character == 32)
    {
        array[26]++;
    }
    //Count sentences by counting (.),(!),(?),(:),(;).
    if (character == 33 || character == 46 || character == 58 || character == 59 || character == 63)
    {
        array[27]++;
    }
    //Count every characters
    for (int i = 0; i < 26; i++)
    {
        if (character == 65 + i || character == 97 + i) //Accourding ASCII codes
        {
            array[i]++;
        }
    }
}