#include <stdio.h>
#include <math.h>

 void PrintHexFromDec(int x);

int main()
{
    printf("Please input decimal = ");
    int number = 0;
    while(scanf("%i", &number));

    //Hex numbers : 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, A, B, C, D, E, F

    int x = 0;
    while(number <= pow(16,x))
    {
        x++;
    }

    for(int i = x; i > 0; i--)
    {
        int a = (number-(number % (int)pow(16,i))) / pow(16,i);
        PrintHexFromDec(a);
        number -= a * pow(16,i);
    }

}

void PrintHexFromDec(int x)
{
    char c = 0;
    switch (x)
    {
    case(0):
    c = '0';
        break;
    case(1):
    c = '1';
        break;
    case(2):
    c = '2';
        break;
    case(3):
    c = '3';
        break;
    case(4):
    c = '4';
        break;
    case(5):
    c = '5';
        break;
    case(6):
    c = '6';
        break;
    case(7):
    c = '7';
        break;
    case(8):
    c = '8';
        break;
    case(9):
    c = '9';
        break;
    case(10):
    c = 'A';
        break;
    case(11):
    c = 'B';
        break;
    case(12):
    c = 'C';
        break;
    case(13):
    c = 'D';
        break;
    case(14):
    c = 'E';
        break;
    case(15):
    c = 'F';
        break;
    default:
        break;
    }
    printf("%c",c);
}