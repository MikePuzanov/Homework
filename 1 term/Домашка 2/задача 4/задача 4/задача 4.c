#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>

int sortMiddleElement(int array[], int size)
{
    if (size < 1)
    {
        return 1;
    }
    int middle = 1;
    int startElement = array[0];
    for (int i = 1; i < size; ++i)
    {   
        if ((array[i] < startElement) && (i == middle))
        {
            middle++;
        }
        else
        {
            if (array[i] < startElement)
            {
                array[i] = array[middle] + array[i];
                array[middle] = array[i] - array[middle];
                array[i] = array[i] - array[middle];
                middle++;
            }
        }
    }
    if (middle == 1)
    {
        return 0;
    }
    array[0] = array[middle - 1] + array[0];
    array[middle - 1] = array[0] - array[middle - 1];
    array[0] = array[0] - array[middle - 1];
    return 0;
}

void arrayPlus(int array[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        array[i] = rand() % 100;
    }
}

void arrayMinus(int array[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        array[i] = (-100 + rand() % 100);
    }
}

void arrayMinusPlus(int array[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        array[i] = (-50 + rand() % 100);
    }
}

void arraySameElement(int array[], int size)
{
    int element = (-50 + rand() % 100);
    for (int i = 0; i < size; ++i)
    {
        array[i] = element;
    }
}

bool compare(int array[], int size, int number)
{
    int numberArray = 0;
    while ((array[numberArray] <= number) && (numberArray < size))
    {
        numberArray++;
    }
    while ((array[numberArray] > number) && (numberArray < size))
    {
        numberArray++;
    }
    return (size != numberArray) ? false : true;
}

bool test()
{
    int array[100] = {0};
    arrayMinusPlus(array, 10);
    int number = array[0];
    sortMiddleElement(array, 10);
    if (!compare(array, 10, number))
    {
        return false;
    }
    arrayMinus(array, 10);
    number = array[0];
    sortMiddleElement(array, 10);
    if (!compare(array, 10, number))
    {
        return false;
    }
    arrayPlus(array, 10);
    number = array[0];
    sortMiddleElement(array, 10);
    if (!compare(array, 10, number))
    {
        return false;
    }
    arraySameElement(array, 10);
    number = array[0];
    sortMiddleElement(array, 10); 
    if (!compare(array, 10, number))
    {
        return false;
    }
    if (sortMiddleElement(array, 0) != 1)
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
        printf("Тест провален!");
        return 1;
    }
    printf("Тест пройден!\n");
    int array[100];
    int size = 0;
    printf("Введите размер массива: ");
    scanf("%i", &size);
    if (size < 1)
    {
        printf("Ввод некорретных данных!");
        return 1;
    }
    printf("Массив: ");
    for (int i = 0; i < size; ++i)
    {
        array[i] = (-50 + rand() % 100);
        printf("%i ", array[i]);
    }
    sortMiddleElement(array, size);
    printf("\nОтвет: ");
    for (int i = 0; i < size; ++i)
    {
        printf("%i ", array[i]);
    }
    return 0;
}