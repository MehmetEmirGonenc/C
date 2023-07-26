// Code by : Mehmet Gönenç
//
//This project seach file for wanter word by using linked lists and bucked method

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <strings.h>
#include <stdbool.h>

//Define type
typedef struct node
{
    char index[50];
    struct node *next;
}node;

//Creating hash table
const unsigned int TN = 26; //Table number

node *tables[TN];

//Functions
int hash (char * word);
bool load(char * fileName);
bool search(char * word);
bool unload(void);

int main(int argc, char * argv[])
{
    //Ensuring inputs
    if (argc != 2)
    {
        printf("True usage : ./Search <text file>\n");
        return 1;
    }
    //Load Text to hash tables
    if (!load(argv[1]))
    {
        return 2;
    }
    //Get string for searching (just alphabetic)
    char t_word[50];
    do
    {
        printf("Please enter a word : ");
        if (search(t_word))
        {
            printf("Founded!\n");
        }
    } while (scanf("%s", t_word));
    
    
    
    
}

bool search(char * word)
{
    int number = hash(word);
    node *temp = malloc(sizeof(node));
    if (temp == NULL)
    {
        return false;
    }
    temp = tables[number];
    while (temp != NULL)
    {
        if (strcasecmp(temp->index, word)== 0)
        {
            free(temp);
            return true;
        }
        else
        {
            temp = temp->next;
        }
    }
    free(temp);
    return false;
}

int hash (char * word)
{
    return (toupper(word[0]) - 65);
}


bool load(char * fileName)
{
    FILE *textFile = fopen(fileName, "r");
    if (textFile == NULL)
    {
        printf("Could not loaded! (Error: File opening)\n");
        return false;
    }
    char buffer[50];
    while (fscanf(textFile, "%s", buffer) != EOF)
    {
        int number = hash(buffer);
        node *tmp = malloc(sizeof(node));
        strcpy(tmp->index, buffer);
        tmp ->next = tables[number];
        tables[number] = tmp;
    }
    fclose(textFile);
    return true;
    
}
bool unload(void)
{
    for (int i = 0; i < TN; i++)
    {
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            return false;
        }
        n = tables[i];
        while (n != NULL)
        {
            node *temp = n;
            temp = n;
            n = n->next;
            free(temp);
        }
        free(n);
    }
    return true;
}