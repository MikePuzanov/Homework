#include "Knuth–Morris–Pratt algorithm.h"
#include "Test.h"

#include <stdio.h>
#include <locale.h>
#include <stdbool.h>

int main()
{
    setlocale(LC_ALL, "Rus");
    if (!test())
    {
        printf("Тест не пройден!");
        return 5;
    }
    printf("Тест пройден!\n");
    char searchLine[100];
    scanf("%99[^\n]", &searchLine);
    int indexSymbol = 1;
    int indexString = 1;
    if (algorithmKMP("File.txt", searchLine, &indexSymbol, &indexString))
    {
        printf("Искомая строка первые встречается - %i предложение %i символ", indexString,indexSymbol);
    }
    else
    {
        printf("Искомая не встречается.");
    }
}