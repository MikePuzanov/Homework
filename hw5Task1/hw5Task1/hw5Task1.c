#include "../../hw5Stack/hw5Stack/Stack.h"
#include "../../hw5Stack/hw5Stack/TestStack.h"
#include "ReversePolishCalculator.h"
#include "TestForTask.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
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
    bool isCorrect = true;
    int answer = reversePolish(element, head, &isCorrect);
    if (!isCorrect)
    {
        printf("Пример записан некорректно! ");
        return 3;
    }
    printf("\nОтвет: %i.", answer);
    deleteStack(&head);
    if (!isEmpty(head))
    {
        return 2;
    }
 }