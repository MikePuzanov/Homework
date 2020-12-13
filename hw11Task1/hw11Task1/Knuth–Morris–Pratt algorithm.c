#include "Knuth–Morris–Pratt algorithm.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void prefixFunction(char* string, int* pi, int size)
{
    pi[0] = 0;
    int j = 0;
    int i = 1;
    while (i < size)
    {
        if (string[i] == string[j])
        {
            pi[i] = j + 1;
            i++;
            j++;
        }
        else if (j == 0)
        {
            pi[i] = 0;
            i++;
        }
        else
        {
            j = pi[j - 1];
        }
    }
}



bool findString(char* string, int* pi, const char* fileName, int* indexSymbol, int* indexStringLine)
{
    FILE* file = fopen(fileName, "r");
    int sizeString = strlen(string);
    char symbol = fgetc(file);
    int index = 0;
    while (!feof(file))
    {
        if (symbol == string[index])
        {
            symbol = fgetc(file);
            if (symbol == '\n')
            {
                if (!feof(file))
                {
                    symbol = fgetc(file);
                }
                else
                {
                    free(pi);
                    fclose(file);
                    return false;
                }
                *indexSymbol = 1;
                (*indexStringLine)++;
            }
            else
            {
                (*indexSymbol)++;
            }
            index++;
            if (index == sizeString)
            {
                fclose(file);
                free(pi);
                *indexSymbol -= strlen(string);
                return true;
            }
        }
        else if (index == 0)
        {
            symbol = fgetc(file);
            if (symbol == '\n')
            {
                if (!feof(file))
                {
                    symbol = fgetc(file);
                }
                else
                {
                    free(pi);
                    fclose(file);
                    return false;
                }
                *indexSymbol = 1;
                (*indexStringLine)++;
            }
            else
            {
                (*indexSymbol)++;
            }
        }
        else
        {
            index = pi[index - 1];
        }
    }
    fclose(file);
    free(pi);
    return false;
}

bool  algorithmKMP(const char* fileName, const char* searchLine, int* indexSymbol, int* indexStringLine)
{
    FILE* file = fopen(fileName, "r");
    if (feof(file))
    {
        fclose(file);
        return false;
    }
    fclose(file);
    int* pi = calloc(strlen(searchLine), sizeof(int));
    prefixFunction(searchLine, pi, strlen(searchLine));
    return findString(searchLine, pi, fileName, indexSymbol, indexStringLine);
}