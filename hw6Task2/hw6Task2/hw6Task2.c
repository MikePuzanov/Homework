#include "CyclicList.h"
#include "Countdown.h"
#include "TestTask.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Rus");
    if (!testTask())
    {
        printf("Тест не пройден!");
        return 5;
    }
    printf("Тест пройден!\n\n");
    int n = 0;
    int m = 0;
    printf("Введите число n (количество войнов) - ");
    scanf("%i", &n);
    printf("Введите число m (убивают каждого m-го) - ");
    scanf("%i", &m);
    List* head;
    init(head);
    for (int i = 0; i < n; ++i)
    {
        insert(head, 0, n - 1 - i);
    }
    int answer = countdown(n, m, head);
    if (answer == -1)
    {
        printf("\nВы ввели некорректные данные!");
        return 0;
    }
    printf("\nНомер война, если отсчет воиной идет от 0 - %i\n", answer);
    printf("Номер война, если отсчет воиной идет от 1 - %i\n", answer + 1);
}