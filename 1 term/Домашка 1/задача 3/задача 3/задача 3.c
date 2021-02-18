#include <stdio.h>
#include <string.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Rus");
    char string[1000];
    int answer = 0;
    int kontrol = 0;
    printf(" Введите строку: ");
    scanf("%s", &string);
    for (int i = 0; i < strlen(string); ++i)
    {
        if (string[i] == '(')
        {
            kontrol++;
        }
        if (string[i] == ')')
        {
            kontrol--;
        }
        if (kontrol < 0)
        {
            answer = -1;
        }
    }
    if (answer >= 0 && kontrol == 0)
    {
        printf(" Выполняется правило вложенности скобок");
    } 
    else
    {
        printf(" Не выполняется правило вложенности скобок");
    }
}
