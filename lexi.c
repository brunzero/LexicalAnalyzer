#include<stdio.h>
#include<stdlib.h>
#include "ArrayList.h"

typedef struct Token
{
    char *word;
    int sym;
}Token;

FILE *codeFile;
void load();
int structIndex = 0;
Token *tokenArray;
ArrayList *codeArray;

void structPut(char *word, int num)
{
    if(!tokenArray)
    {
        printf("Token Array not properly initialized");
    }
    tokenArray[structIndex].word = word;
    tokenArray[structIndex].sym = num;
}

void initArrays()
{
    tokenArray = malloc(sizeof(Token)*10000);
    codeArray = createArrayList(10);
}

void erase(char *buffer)
{
    int j;
    for(j=0; j<256; j++)
    {
        buffer[j] = NULL;
    }
}

void load()
{
    char buffer[256];
    char symbolBuffer[2];
    int i = 0;
    int z, x, codeIndex;
    for(z = 0; z<256; z++)
    {
        buffer[z] = NULL;
    }
    codeFile = fopen("input.txt", "r");
    if(!codeFile)
    {
        printf("Error in opening the file.");
        exit(0);

    }
    while ((x = fgetc(codeFile)) != EOF)
    {

        if(isSymbol(x))
        {
            if(*buffer=='\n')
                printf("hello");
            if(*buffer!=0)
                put(codeArray, buffer);

            erase(buffer);


            symbolBuffer[0] = x;
            //symbolBuffer[1] = '\0';

            put(codeArray, symbolBuffer);
            erase(symbolBuffer);
            i = 0;
        }
        else
        {
            buffer[i] = x;
            buffer[i+1] = '\0';
            i++;
        }
    }
}

void iradicateComments(ArrayList *arrayList)
{
    int i;
    for(i = 0; i<arrayList->size; i++)
    {
        if(*get(arrayList, i)=='/')
        {
            if(*get(arrayList, i+1)=='*')
            {
                while(*get(arrayList, i+1)!='/')
                {
                    removeElement(arrayList, i);
                }
                    removeElement(arrayList, i);
                    removeElement(arrayList, i);
            }
        }
    }
}


void cleanInput(ArrayList *arrayList)
{
    int i;
    iradicateComments(arrayList);
    for(i=0; i<arrayList->size; i++)
    {
        if(*get(arrayList, i)==' ')
        {
            removeElement(arrayList, i);
        }
        /*else if(*get(arrayList, i)=='\n')
        {
            removeElement(arrayList, i);
        }*/
    }
}

int isSymbol(int x)
{
    if((x>=32 && x<=47) || (x>=58 && x<=64) || (x>= 91 && x<=96) || (x>=123 && x<=126))
    {
        return 1;
    }
    return 0;
}

void tokenize(Token *tokenArray)
{


}

int main()
{
    initArrays();
    load();
    iradicateComments(codeArray);
    printArrayList(codeArray);
    cleanInput(codeArray);
    printf("\n\n\n");
    printArrayList(codeArray);

    return 0;
}
