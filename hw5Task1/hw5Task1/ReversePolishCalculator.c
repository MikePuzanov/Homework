#include "ReversePolishCalculator.h"

#include <stdbool.h>

int calculator(char element, int first, int second)
{
    switch (element)
    {
    case '+':
        return first + second;
    break;
    case '-':
        return first - second;
    break;
    case '/':
        return first / second;
    break;
    case '*':
        return first * second;
    break;
    }
}

int translateToInt(char element[], int low, int high)
{
    int number = 0;
    int power = 1;
    int index = low;
    if (element[low] == '-')
    {
        index++;
    }
    for (index; index < high; ++index)
    {
        int addNumber = element[index] - '0';
        number = number * power + addNumber;
        power *= 10;
    }
    if (element[low] == '-')
    {
        number *= -1;
    }
    return number;
}