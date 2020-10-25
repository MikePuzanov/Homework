#include "..\..\hw5Stack\hw5Stack\Stack.h"
#include "..\..\hw5Stack\hw5Stack\testStack.h"
#include "parenthesesScanf.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>
#include <string.h>

int main()
{
    setlocale(LC_ALL, "Rus");
    if (!test())
    {
        printf("Тест не пройден!\n");
    }
    printf("Тест пройден!\n");
    char line[100];
    printf("\nВведите вашу строку скобок: ");
    scanf("%s", &line);
    struct StackElement* head = NULL;
    if (!checkParentheses(head, line))
    {
        printf("\nСтрока введена некорректно!\n");
        return 1;
    }
    printf("\nВерно!\n");
}