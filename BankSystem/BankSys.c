//Coded by : Mehmet Gönenç
#include <stdio.h>
#include <string.h>
#include <ctype.h>

//Type definiations
typedef struct account
{
    long accountNo;
    int pin;
    long balance;
}account;


//Cryption functions
char * crypte (char *text);
char * cryptenum (char *text);
char * encrypte (char *text);
char * encryptenum (char *text);

//Functions
void Withdraw (int location, long amount);
void Deposit (int location, account modifiedacc);


//Generate a key for crypting
const char key[] = "OUXEYKIAGNCTDUMRPJWQBLHZFS";
const int keyna = 150; //key for not alpha

int main(int argc, char * argv[])
{
    if (argc ==2)
    {  
        if (strcmp(argv[1], "admin"));
        {
            printf("***********************************Adding new Account**********************************\n");
            account newAccount;
            printf("New Account No : ");
            scanf("%li", &newAccount.accountNo);
            printf("New Account pin : ");
            scanf("%i", &newAccount.pin);
            printf("New Account Balance : ");
            scanf("%li", &newAccount.balance);

            //Create temp for overwrite data set

            FILE *accountsnew = fopen("accounts.txt", "r");
            if (accountsnew == NULL)
            {
                printf("Unexpected error occurred!\n");
                return 1;
            }
            FILE *temp = fopen("temp.txt", "w");
            if (temp == NULL)
            {
                printf("Unexpected error occurred!\n");
                return 1;
            }

            //Write all old datas

            account buffer;
            while (fread(&buffer, sizeof(account), 1, accountsnew))
            {
                fwrite(&buffer, sizeof(account), 1, temp);
            }
            //Close files
            fclose(temp);
            fclose(accountsnew);

            accountsnew = fopen("accounts.txt", "w");
            temp = fopen("temp.txt", "r");

            while (fread(&buffer, sizeof(account), 1, temp))
            {
                fwrite(&buffer, sizeof(account), 1, accountsnew);
            }

            //Write new data
            fwrite(&newAccount, sizeof(account), 1, accountsnew);

            //Close files
            fclose(temp);
            fclose(accountsnew);
            remove(temp);
        }
    }
    printf("###################### Welcome to Bank System #################################\n");
    
    printf("Please enter an account number : ");
    long accNo = 0, balance = 0;
    int pin = 0, location; // location for account location on data set
    scanf("%li", &accNo);
    FILE *accounts = fopen("accounts.txt", "r");
    account account;
    while (fread(&account, sizeof(account), 1, accounts))
    {
        location = ftell(accounts);
        if (accNo == account.accountNo)
        {
            balance = account.balance;
            pin = account.pin;
            break;
        }
    }
    if (pin == 0)
    {
        printf("Account could not found!\n");
        return 2;
    }
    //Close file
    fclose(accounts);
    //Checking pin
    printf("Please enter your pin : ");
    int inpin = 0;
    scanf("%i", &inpin);
    if (inpin != pin)
    {
        printf("Pin is not correct!\n");
        return 3;
    }
    
    //Interface
    printf("---------------------------- Account Details -------------------------------------\n");
    printf("|Account No : %li                                Balance : %li           |\n", accNo, balance);
    printf("|  1) -> Deposit Money                                                           |\n");
    printf("|  2) -> Withdraw Money                                                          |\n");
    printf("|  3) -> Exit                                                                    |\n");
    printf("|  4) -> Delete Account                                                          |\n");
    printf("----------------------------------------------------------------------------------\n");
    int choice = 0;
    do
    {
        printf("Please enter your choice : ");
        scanf("%i", &choice);
        while(getchar() != '\n'); 
    } while (choice < 1 || choice > 5);

    switch (choice)
    {
    case (1):
        /* code */
    break;
    case (2):
        /* code */
    break;
    case (3):
        printf("System shutted down!\n");
        return 0;
    break;
    case (4):
        /* code */
    break;
    default:
        break;
    }
}
void Withdraw (int location, long amount)
{

}
void Deposit (int location, account modifiedacc)
{
    FILE *acc = fopen("accounts.txt", "r");
    FILE *temp = fopen("temp.txt", "w");
    account buffer;
    //Write temp file
    while (fread(&buffer, sizeof(account), 1, acc))
    {
        if(ftell(acc) == location- sizeof(account))
        {
            fwrite(&modifiedacc, sizeof(account), 1,temp);
            continue;
        }
        fwrite(&buffer, sizeof(account), 1, temp);
    }
    //write main file by using temp file
    while (fread(&buffer, sizeof(account), 1, temp))
    {
        fwrite(&buffer, sizeof(account), 1, acc);
    }
    fclose(temp);
    fclose(acc);
    remove(temp);
}
