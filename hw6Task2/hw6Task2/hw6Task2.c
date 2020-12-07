#include "CyclicList.h"
#include "Countdown.h"
#include "TestTask.h"
#include "CyclicListTest.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Rus");
    if (!testTask() || !testList())
    {
        printf("Тест не пройден!");
        return 5;
    }
    printf("Тест пройден!\n\n");
    int warriors = 0;
    int numberDeadWarrior = 0;
    printf("Введите число n (количество войнов) - ");
    scanf("%i", &warriors);
    printf("Введите число m (убивают каждого m-го) - ");
    scanf("%i", &numberDeadWarrior);
    int answer = countdown(warriors, numberDeadWarrior);
    if (answer == -1)
    {
        printf("\nВы ввели некорректные данные!");
        return 0;
    }
    printf("\nНомер война, если отсчет воиной идет от 0 - %i\n", answer);
    printf("Номер война, если отсчет воиной идет от 1 - %i\n", answer + 1);
}