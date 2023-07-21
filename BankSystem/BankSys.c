//Coded by : Mehmet Gönenç
#include <stdio.h>
#include <string.h>
#include <ctype.h>

//This program has an interface and keep information crypted on txt files.

//Functions
char * crypte (char *text);
char * encrypte (char *text);

//Generate a key for crypting
const char key[] = "OUXEYKIAGNCTDUMRPJWQBLHZFS";
const int keyna = 150; //key for not alpha

int main()
{
    char text[255] = "Hello World!";
    crypte(text);
    printf("%s\n", text);
    encrypte(text);
    printf("%s\n", text);

}

char * crypte (char text[])
{
    for (int i = 0; i < strlen(text); i++)
    {
        if (!isalpha(text[i]))
        {
            if(text[i] + 150 >255)
            {
                text[i] = text[i];
                continue;
            }
            text[i] = text[i] + 150;
            continue;
        }
        if (isupper(text[i]))
        {
            text[i] = key[text[i] - 65];
        }
        else if (islower(text[i]))
        {
            text[i] = key[text[i] -32 - 65] + 32;
        }
    }
}

char * encrypte (char text[])
{
    for (int i = 0; i < strlen(text); i++)
    {
        if (!isalpha(text[i]))
        {
            if(text[i] + 150 >255)
            {
                text[i] = text[i];
                continue;
            }
            text[i] = text[i] - 150;
            continue;
        }
        if (isupper(text[i]))
        {
            for (int j = 0; j < 26; j++)
            {
                if (key[j] == text[i])
                {
                    text[i] = 65 + j;
                }
                
            }
        }
        else if (islower(text[i]))
        {
            for (int j = 0; j < 26; j++)
            {
                if (key[j] == text[i] - 32)
                {
                    text[i] = 97 + j;
                }
                
            }
        }
    }
}