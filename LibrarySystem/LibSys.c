#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void add_book();

int main()
{
    ////Main Loop
    ////while(1)
    ////{
        //Main menu
        printf("----------------------Main Menu----------------------\n");
        printf("1) -> Books\n");
        printf("2) -> Lend Book\n");
        printf("3) -> Add Book\n");
        printf("4) -> Delete Book\n");
        //Option selection
        int option = 0;
        do
        {
            printf("Please choice an option : ");
            scanf("%d", &option);
            while(getchar() != '\n'); 
        } while (option < 1 || option > 4);
        //Direction user accourding to "option"
        switch (option)
        {
        case (1):
            
        break;
        case (2):

        break;
        case (3):
            add_book();
        break;
        case (4):

        break;
        default:
            printf("Unexpected error! \n");
            return 2;
        break;
        }
        
    ////}
    

}

void add_book()
{
    //Giving information
    printf("****************************Add Book****************************\n");
    printf("Please, enter name of data set that you want to use (Just txt files)\n");
    //Getting file name
    char file_name[255];
    scanf(" %s",file_name);
    //open / create file
    FILE *input = fopen(file_name, "r");
    if (input == NULL)
    {
        printf("File cound not found!\n");
        return;
    }
    else
    {
        printf("Data set opened succesfuly!\n");
    }
    //Create temp for synchronize
    FILE *temp = fopen("tmp.txt", "w");
    //Write all datas to temp
    unsigned char buffer;
    while(fread(&buffer, sizeof(unsigned char), 1, input))
    {
        //printf("%i\n", buffer); //Debug
        fwrite(&buffer, sizeof(unsigned char), 1, temp);
    }
    //Get new data from user
    printf("* * * * * * * * * * * * * * * * * * * * * * * * * * \n");
    printf("                   Add book \n");
    printf("* * * * * * * * * * * * * * * * * * * * * * * * * * \n");

    char book_name[255];
    printf("Book name   : "); 
    scanf(" %s", book_name);

    printf("Book author : ");
    char book_author[255];
    scanf("%s", book_author);

    int book_date = 0;
    while (book_date < 1)
    {
        printf("Book date   : ");
        scanf("%d", &book_date);
        while(getchar() != '\n'); 
    }
    //Write data to data set
    // "/" for seperate datas 
    for (int i = 0; i < strlen(book_name); i++)
    {
        fwrite(&book_name[i], sizeof(char), 1, temp);
    }
    fwrite("/", sizeof(char), 1, temp);
    for (int i = 0; i < strlen(book_author); i++)
    {
        fwrite(&book_author[i], sizeof(char), 1, temp);
    }
    fwrite("/", sizeof(char), 1, temp);
    // int to string 
    char date[16];
    sprintf(date, "%d", book_date);
    for (int i = 0; i < strlen(date); i++)
    {
        fwrite(&date[i], sizeof(char), 1, temp);
    }   
    //For new line
    fwrite("\n", sizeof(char), 1, temp);
    //Close files for change format
    fclose(temp);
    fclose(input);
    //Write all datas temp to books
    FILE *temp_read = fopen("tmp.txt", "r");
    FILE *input_write = fopen(file_name, "w");
    unsigned char bbuffer;
    while(fread(&bbuffer, sizeof(unsigned char), 1, temp_read))
    {
        //printf("%i\n", buffer); //Debug
        fwrite(&bbuffer, sizeof(unsigned char), 1, input_write);
    }
    //Close files
    fclose(input_write);
    fclose(temp_read);
}