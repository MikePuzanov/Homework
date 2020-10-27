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
    struct StackElement* head = NULL;
    char line[30];
    char expression[30];
    printf("Введите ваш пример в обычной форме: ");
    scanf("%29[^\n]", &line);
    int index = 0;
    translateToPolishReverse(head, line, expression, &index);
    for (int i = 0; i < index; ++i)
    {
        printf("%c", expression[i]);
    }
}