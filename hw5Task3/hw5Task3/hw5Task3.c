#include "../../hw5Stack/hw5Stack/Stack.h"
#include "../../hw5Stack/hw5Stack/TestStack.h"
#include "TranslateToPolishReverse.h"
#include "TestToTranslatePolishReverse.h"

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

int main()
{
    setlocale(LC_ALL, "Rus");
    if (!test())
    {
        printf("Тесты не пройдены!");
        return 1;
    }
    printf("Тесты пройдены!\n\n");
    struct StackElement* head = NULL;
    char line[30];
    char expression[30];
    printf("Введите ваш пример в обычной форме: ");
    scanf("%29[^\n]", &line);
    int size = 0;
    translateToPolishReverse(head, line, expression, &size);
    printf("\nВаш пример в постфиксной форме: ");
    for (int i = 0; i < size; ++i)
    {
        printf("%c", expression[i]);
    }
}