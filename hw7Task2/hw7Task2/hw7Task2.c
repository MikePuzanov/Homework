#include "Tree.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>
#include <string.h>

int main()
{
    char line[30];
    int size = 0;
    char symbol = ' ';
    FILE* expression = fopen("Expression.txt", "r");
    while ((fscanf(expression, "%c", &symbol)) != EOF)
    {
        line[size] = symbol;
        ++size;
    }
    fclose(expression);
    int high = size;
    int* low = 0;
    Node* root = NULL;
    root = expressionMath(line, &low, size);
    root = root->left;
}