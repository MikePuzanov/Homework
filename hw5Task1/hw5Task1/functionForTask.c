#include "functionForTask.h"

#include <stdbool.h>

int calculator(char element[], int index, int first, int second)
{
    int ascii = ("%c", element[index]);
    int timeAnswer = 0;
    switch (ascii)
    {
    case 43:// +
        timeAnswer = first + second;
        break;
    case 45:// -
        timeAnswer = first - second;
        break;
    case 47:// /
        timeAnswer = first / second;
        break;
    case 42:// *
        timeAnswer = first * second;
        break;
    }
    return timeAnswer;
}

int transfer(char element[], int low, int high)
{
    int power = 1;
    int number = 0;
    bool minus = false;
    bool dot = false;
    for (int i = low; i < high; ++i)
    {
        int ascii = ("%c", element[i]);
        int addNumber = 0;
        switch (ascii)
        {
        case 45:
            minus = true;
            break;
        case 48:
            addNumber = 0;
            number = number * power + addNumber;
            power *= 10;
            break;
        case 49:
            addNumber = 1;
            number = number * power + addNumber;
            power *= 10;
            break;
        case 50:
            addNumber = 2;
            number = number * power + addNumber;
            power *= 10;
            break;
        case 51:
            addNumber = 3;
            number = number * power + addNumber;
            power *= 10;
            break;
        case 52:
            addNumber = 4;
            number = number * power + addNumber;
            power *= 10;
            break;
        case 53:
            addNumber = 5;
            number = number * power + addNumber;
            power *= 10;
            break;
        case 54:
            addNumber = 6;
            number = number * power + addNumber;
            power *= 10;
            break;
        case 55:
            addNumber = 7;
            number = number * power + addNumber;
            power *= 10;
            break;
        case 56:
            addNumber = 8;
            number = number * power + addNumber;
            power *= 10;
            break;
        case 57:
            addNumber = 9;
            number = number * power + addNumber;
            power *= 10;
            break;
        default:
            break;
        }
    }
    if (minus)
    {
        number *= -1;
    }
    return number;
}