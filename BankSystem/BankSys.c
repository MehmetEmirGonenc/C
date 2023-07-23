//Coded by : Mehmet Gönenç
#include <stdio.h>
#include <string.h>
#include <ctype.h>

//This program has an interface and keep information crypted on txt files.

//Type definiations
typedef struct account
{
    long accountNo;
    int pin;
}account;


//Cryption functions
char * crypte (char *text);
char * cryptenum (char *text);
char * encrypte (char *text);
char * encryptenum (char *text);

//Find Account


//Generate a key for crypting
const char key[] = "OUXEYKIAGNCTDUMRPJWQBLHZFS";
const int keyna = 150; //key for not alpha

int main()
{
    printf("###################### Welcome to Bank System #################################\n");
    
    //printf("Please enter an account number : ");
    char text[255] = "5643";
    cryptenum(text);
    printf("%s\n", text);
    encryptenum(text);
    printf("%s\n", text);
    

}

char * cryptenum (char *text)
{
    //Crypting for numbers
    for (int i = 0; i < strlen(text); i++)
    {
        text[i] += 17;
        text[i] = key[text[i] - 65];
    }
    
}

char * crypte (char text[])
{
    for (int i = 0; i < strlen(text); i++)
    {
        if (isdigit(text[i]))
        {
            text[i] = keynum[text[i] - 48];
            continue;
        }
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

char * encryptenum (char *text)
{
    for (int i = 0; i < strlen(text); i++)
    {
        for (int j = 0; j < 26; j++)
        {
            if (key[j] == text[i])
            {
                text[i] = 65 + j;
                break;
            }
        }
        text[i] -= 17;
    }
}

char * encrypte (char text[])
{
    for (int i = 0; i < strlen(text); i++)
    {
        int keyforpass = 0;
        for (int j = 0; j < 10; j++)
            {
                if (keynum[j] == text[i])
                {
                    text[i] = 48 + j;
                    keyforpass = 1;
                    break;
                }
            }
        if (keyforpass = 1)
        {
            continue;
        }
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
                    break;
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
                    break;
                }
                
            }
        }
    }
}