#include "../../hw5Stack/hw5Stack/Stack.h"
#include "../../hw5Stack/hw5Stack/TestStack.h"
#include "ReversePolishCalculator.h"
#include "TestForTask.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>

int main()
{
    setlocale(LC_ALL, "Rus");
    if (!testForTask() || !testStack())
    {
        printf("Тест не пройден!\n");
        return 1;
    }
    printf("Тест пройден!\n");
    struct StackElement* head = NULL;
    char element[100];
    printf("\nВведите ваш пример в постфиксной форме: ");
    scanf("%99[^\n]", element);
    for (int i = 0; i < strlen(element); ++i)
    {
        if (element[i] == ' ')
        {
            continue;
        }
        int low = i;
        if (!isdigit(element[i]) && isdigit(element[i + 1]) && i < strlen(element) -3)
        {
            ++i;
            while (isdigit(element[i]))
            {
                ++i;
            }
            head = push(head, translateToInt(element, low, i));
        }
        else if (isdigit(element[i]))
        {
            while (isdigit(element[i]))
            {
                ++i;
            }
            head = push(head, translateToInt(element, low, i));
        }
        else
        {
            int second = pop(&head);
            int first = pop(&head);
            if (second == 0 && element[i] == '/')
            {
                printf("На ноль делить нельзя!");
                return 2;
            }
            head = push(head, calculator(element[i], first, second));
        }
    }
    printf("\nОтвет: %i.", pop(&head));
    deleteStack(&head);
    if (!isEmpty(head))
    {
        return 2;
    }
}