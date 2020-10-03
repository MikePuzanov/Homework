#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

int bubble(int array[], int size)
{
    if (size < 1)
    {
        return 1;
    }
    for (int i = 0; i < size; ++i)
    {
        for (int j = size - 1; j > i; j--)
        {
            if (array[j - 1] > array[j])
            {
                array[j - 1] = array[j - 1] + array[j];
                array[j] = array[j - 1] - array[j];
                array[j - 1] = array[j - 1] - array[j];
            }
        }
    }
    return 0;
}

int withArray(int array[], int size)
{
    if (size < 1)
    {
        return 1;
    }
    int maximum = array[0];
    int minimum = array[0];
    for (int i = 0; i < size; ++i)
    {
        if (maximum < array[i])
        {
            maximum = array[i];
        }
        if (minimum > array[i])
        {
            minimum = array[i];
        }
    }
    int const sizeAdd = maximum - minimum + 1;
    int *arrayAdd = (int*) calloc(sizeAdd, sizeof(int));
    for (int i = 0; i < size; ++i)
    {
        arrayAdd[array[i] - minimum]++;
    }
    int iForArray = 0;
    for (int i = 0; i < sizeAdd; ++i)
    {
        while (arrayAdd[i] != 0)
        {
            array[iForArray] = i + minimum;
            arrayAdd[i]--;
            iForArray++;
        }
    }
    free(arrayAdd);
    return 0;
}

void arrayPlus(int arrayForBubble[], int arrayForWithArray[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        arrayForBubble[i] = (rand() % 100);
        arrayForWithArray[i] = arrayForBubble[i];
    }
}

void arrayMinus(int arrayForBubble[], int arrayForWithArray[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        arrayForBubble[i] = (100 - rand() % 100);
        arrayForWithArray[i] = arrayForBubble[i];
    }
}

void arrayPlusAndMinus(int arrayForBubble[], int arrayForWithArray[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        arrayForBubble[i] = 50 - (rand() % 100);
        arrayForWithArray[i] = arrayForBubble[i];
    }
}

int compare(int arrayForBubble[], int arrayForWithArray[])
{
    for (int i = 0; i < 9; ++i)
    {
        if ((arrayForBubble[i] > arrayForBubble[i + 1]) || (arrayForWithArray[i] > arrayForWithArray[i + 1]))
        {
            return 0;
        }
    }
    return 1;
}

bool test()
{   
    int arrayForBubble[100] = {0};
    int arrayForWithArray[100] = {0};
    bubble(arrayForBubble, 0);
    withArray(arrayForWithArray, 0);
    if ((bubble(arrayForBubble, 0) != 1) || (withArray(arrayForWithArray, 0) != 1))
    {
        return false;
    }
    arrayPlus(arrayForBubble, arrayForWithArray, 10);
    bubble(arrayForBubble, 10);
    withArray(arrayForWithArray, 10);
    if (compare(arrayForBubble, arrayForWithArray) == 0)
    {
        return false;
    }
    arrayMinus(arrayForBubble, arrayForWithArray, 10);
    bubble(arrayForBubble, 10);
    withArray(arrayForWithArray, 10);
    if (compare(arrayForBubble, arrayForWithArray) == 0)
    {
        return false;
    }
    arrayPlusAndMinus(arrayForBubble, arrayForWithArray, 10);
    bubble(arrayForBubble, 10);
    withArray(arrayForWithArray, 10);
    if (compare(arrayForBubble, arrayForWithArray) == 0)
    {
        return false;
    }
    return true;
}

int main()
{
    setlocale(LC_ALL, "Rus");
    if (!test())
    {
        printf("Тест провален!\n");
        return 1;
    }
    else
    {
        printf("Тест пройден!\n");
    }
    int arrayForBubble[100000] = {0};
    int arrayForWithArray[100000] = {0};
    int size = 1;
    printf(" Введите количество цифр в массиве: ");
    scanf("%i", &size);
    if (size < 1)
    {
        printf("Ввод некорректных данных!");
        return 1;
    }
    for (int i = 0; i < size; ++i)
    {
        arrayForBubble[i] = (-50 + rand() % 100);
        arrayForWithArray[i] = arrayForBubble[i];
    }
    bubble(arrayForBubble, size);
    printf("Ответ с помощью пузырька: ");
    for (int i = 0; i < size; ++i)
    {
        printf("%i ", arrayForBubble[i]);
    }
    withArray(arrayForWithArray, size);
    printf("\nОтвет с помощью динамического массива: ");
    for (int i = 0; i < size; ++i)
    {
        printf("%i ", arrayForWithArray[i]);
    }
    for (int i = 0; i < 100000; ++i)
    {
        arrayForBubble[i] = (-75 + rand() % 150);
        arrayForWithArray[i] = arrayForBubble[i];
    }
    int const startTimeForBubble = clock();
    bubble(arrayForBubble, 100000);
    int const endTimeForBubble = clock();
    int const timeBubble = endTimeForBubble - startTimeForBubble;
    int const startTimeForWithArray = clock();
    withArray(arrayForWithArray, 100000);
    int const endTimeForWithArray = clock();
    int const timeWithArray = endTimeForWithArray - startTimeForWithArray;
    if (timeBubble > timeWithArray)
    {
        printf("\nBubble быстрее!");
    }
    else
    {
        printf("\nBubbe медленее!");
    }
}