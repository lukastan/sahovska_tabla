#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>

void greska()
{
    fprintf(stderr, "-1\n");
    exit(EXIT_FAILURE);
}

void tabla(char x1, int y)
{
    for(int i=9; i>=0; i--)
    {
        for(int j=0; j<=9; j++)
        {
            if(i == 0 || i == 9 || j == 0 || j == 9) printf("#");
            else if(i == y && j == x1) printf("@");
            else printf(" ");
        }
        printf("\n");
    }
    printf("\n");
}

void pesak(int x1, int y)
{
    for(int i=9; i>=0; i--)
    {
        for(int j=0; j<=9; j++)
        {
            if(i == 0 || i == 9 || j == 0 || j == 9) printf("#");
            else if(i == y && j == x1) printf("@");
            else if((i == y + 1 && j == x1) || (i == 4 && y == 2 && j == x1)) printf("+");
            else printf(" ");
        }
        printf("\n");
    }
    printf("\n");
}

void konj(int x1, int y)
{
    for(int i=9; i>=0; i--)
    {
        for(int j=0; j<=9; j++)
        {
            if(i == 0 || i == 9 || j == 0 || j == 9) printf("#");
            else if(i == y && j == x1) printf("@");
            else if(((i == y + 1 || i == y - 1) && (j == x1 + 2 || j == x1 - 2)) || ((i == y + 2 || i == y - 2) && (j == x1 + 1 || j == x1 - 1))) printf("+");
            else printf(" ");
        }
        printf("\n");
    }
    printf("\n");
}

void lovac(int x1, int y)
{
    for(int i=9; i>=0; i--)
    {
        for(int j=0; j<=9; j++)
        {
            
            if(i == 0 || i == 9 || j == 0 || j == 9) printf("#");
            else if(i == y && j == x1) printf("@");
            else if(y + j == x1 + i || i - x1 == y - j) printf("+");
            else printf(" ");
        }
        printf("\n");
    }
    printf("\n");
}

void top(int x1, int y)
{
    for(int i=9; i>=0; i--)
    {
        for(int j=0; j<=9; j++)
        {
            if(i == 0 || i == 9 || j == 0 || j == 9) printf("#");
            else if(i == y && j == x1) printf("@");
            else if(i == y || j == x1) printf("+");
            else printf(" ");
        }
        printf("\n");
    }
    printf("\n");
}

void kraljica(int x1, int y)
{
    for(int i=9; i>=0; i--)
    {
        for(int j=0; j<=9; j++)
        {
            if(i == 0 || i == 9 || j == 0 || j == 9) printf("#");
            else if(i == y && j == x1) printf("@");
            else if(i == y || j == x1) printf("+");
            else if(y + j == x1 + i || i - x1 == y - j) printf("+");
            else printf(" ");
        }
        printf("\n");
    }
    printf("\n");
}

void kralj(int x1, int y)
{
    for(int i=9; i>=0; i--)
    {
        for(int j=0; j<=9; j++)
        {
            if(i == 0 || i == 9 || j == 0 || j == 9) printf("#");
            else if(i == y && j == x1) printf("@");
            else if((i == y - 1 || i == y || i == y + 1) && (j == x1 - 1 || j == x1 || j == x1 + 1)) printf("+");
            else printf(" ");
        }
        printf("\n");
    }
    printf("\n");
}

int main()
{
    char x, z;
    int y;
    printf("Enter the position of the figure(a-z for x, 1-8 for y)\n");
    scanf("%c%d", &x, &y);

    x = tolower(x);
    if(x < 'a' || x > 'h') greska();
    if(y < 1 || y > 8) greska();
    int x1 = x - 'a' + 1;

    tabla(x1, y);

    printf("Which figure do you want use?(Type the letter of the figure you want and press Enter)\n");
    printf("a)Pawn\n");
    printf("b)Knight\n");
    printf("c)Bishop\n");
    printf("d)Rook\n");
    printf("e)Queen\n");
    printf("f)King\n");

    scanf("\n%c", &z);

    if(z == 'a') pesak(x1, y);
    else if(z == 'b') konj(x1, y);
    else if(z == 'c') lovac(x1, y);
    else if(z == 'd') top(x1, y);
    else if(z == 'e') kraljica(x1, y);
    else if(z == 'f') kralj(x1, y);
    else greska();

    return 0;
}