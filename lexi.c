#include<stdio.h>
#include<stdlib.h>
#include "ArrayList.h"
char code [1000];
FILE *codeFile;
int takingInput();
int main()
{
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
