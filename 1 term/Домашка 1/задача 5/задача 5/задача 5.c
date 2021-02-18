#include <stdio.h>
#include <string.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Rus");
    char stringFirst[1000];
    char stringSecond[1000];
    int same = 0;
    printf(" Введите S: ");
    scanf("%s", &stringFirst);
    printf(" Введите S1: ");
    scanf("%s", &stringSecond);
    for (int i = 0; i <= (strlen(stringFirst) - strlen(stringSecond)); ++i)
    {
        int j = 0;
        while ((stringFirst[i + j] == stringSecond[j])  &&  (j < strlen(stringSecond)))
        {
            j++;
        }
        if (j == strlen(stringSecond))
        {              
            ++same;
        }
    }
    printf(" Ответ: %i", same);
}