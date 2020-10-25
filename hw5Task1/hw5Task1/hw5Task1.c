#include "../../hw5Stack/hw5Stack/Stack.h"
#include "../../hw5Stack/hw5Stack/TestStack.h"
#include "functionForTask.h"
#include "TestForTask.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <locale.h>

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
        int ascii = ("%c", element[i]);
        int low = i;
        while (ascii != 32 && i < strlen(element) - 1 )
        {
            ++i;
            ascii = ("%c", element[i]);
        }
        ascii = ("%c", element[low]);
        if ((ascii > 47 && ascii < 58) || ((i - low) > 1 && ascii == 45) || (ascii == 46))
        {
            head = push(head, transfer(element, low, i));
        }
        if ((i - low) <= 1 && ascii > 41 && ascii < 48 && ascii != 46)
        { 
            int second = pop(&head);
            int first = pop(&head);
            if (second < 1e-10 && ascii == 47)
            {
                printf("На ноль делить нельзя!");
                return 2;
            }
            head = push(head, calculator(element, low, first, second));
        }
    }
    printf("\nОтвет: %i.", pop(&head));
    deleteStack(&head);
    if (!isEmpty(head))
    {
        return 2;
    }
}