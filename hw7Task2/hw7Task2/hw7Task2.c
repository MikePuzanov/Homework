#include "Tree.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Rus");
    if (!test())
    {
        return 1;
    }
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
    int low = 0;
    Node* root = NULL;
    root = buildTree(line, &low, size);
    root = checkTree(root);
    char answerLine[30];
    size = 0;
    printTree(root, answerLine, &size);
    printf("Печать дерева: ");
    for (int index = 0; index < size; index++)
    {
        printf("%c", answerLine[index]);
    }
    bool correctExpression = true;
    int answer = countTree(root, &correctExpression);
    if (!correctExpression)
    {
        printf("\n\nНа ноль делить нельзя!");
        deleteTree(root);
         return 6;
    }
    printf("\nОтвет: %i.", answer);
    deleteTree(root);
    printf("hyrhrh");
}