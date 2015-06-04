#include<stdio.h>
#include<stdlib.h>
#include "ArrayList.h"

typedef struct Token
{
    char *word;
    int sym;
}Token;

char code [1000];
FILE *codeFile;
int takingInput();
int structIndex = 0;
Token *tokenArray;

void structPut(char *word, int num)
{
    if(!tokenArray)
    {
        printf("Token Array not properly initialized");
    }

    Token newToken;
    newToken.sym = num;
    newToken.word = word;
    tokenArray[structIndex] = newToken;
}

void initStructArray()
{
    tokenArray = malloc(sizeof(Token)*10000);
}

int main()
{

    initStructArray(tokenArray);
    structPut("read", 10);

    printf("%s\n\n\n\n", tokenArray[0]);

    ArrayList *stream;

    stream = createArrayList(10);

    put(stream, "read");



    takingInput();
    return 0;
}

int takingInput()
{
    int i = 0;
    int x, y;
    codeFile = fopen("input.txt", "r");
    if(!codeFile)
    {
        printf("Error in opening the file.");
        exit(0);

    }
    while ((x = fgetc(codeFile)) != EOF)
    {
        code[i] = x;
        code[i+1] = '\0';
        i ++;
    }
    printf("%s", code);
}
