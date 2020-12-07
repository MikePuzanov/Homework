#include "../../hw5Stack/hw5Stack/Stack.h"
#include "../../hw5Stack/hw5Stack/TestStack.h"
#include "ReadParentheses.h"
#include "TestForTask.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>
#include <string.h>

int main()
{
    setlocale(LC_ALL, "Rus");
    if (!testForTask() || !testStack())
    {
        printf("Тест не пройден!\n");
        return 1;
    }
    printf("Тест пройден!\n");
    char line[100];
    printf("\nВведите вашу строку скобок: ");
    scanf("%s", &line);
    if (!checkParentheses(line))
    {
        printf("\nСтрока введена некорректно!\n");
        return 1;
    }
    printf("\nВерно!\n");
}