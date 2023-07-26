// Code by : Mehmet Gönenç
//
//This project seach file for wanter word by using linked lists and bucked method

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Define type
typedef struct node
{
    char index[50];
    struct node *next;
}node;

//Creating hash table
const int TN = 26;//Table number


int main(int argc, char * argv[])
{
    //Ensuring inputs
    if (argc != 3)
    {
        printf("True usage : ./Search text word\n");
        return 1;
    }
    if (!isalpha(argv[2]))
    {
        printf("Please enter just input alphabetical\n");
        return 2;
    }
    

    
}