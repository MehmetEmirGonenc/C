#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    int characters[26];
    FILE *input = fopen(argv[1], "r");
    char buffer;
    while(fread(buffer, sizeof(char), 1, input))
    {
        
    } 
}