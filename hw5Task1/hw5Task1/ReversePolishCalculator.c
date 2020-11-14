#include "ReversePolishCalculator.h"
#include "../../hw5Stack/hw5Stack/Stack.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int calculator(char element, int first, int second)
{
    switch (element)
    {
    case '+':
        return first + second;
    case '-':
        return first - second;
    case '/':
        return first / second;
    case '*':
        return first * second;
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

int reversePolish(char element[], struct StackElement* head, bool* isCorrect)
{
    int countNumberInStack = 0;
    for (int i = 0; i < strlen(element); ++i)
    {
        if (element[i] == ' ')
        {
            continue;
        }
        int low = i;
        if (!isdigit(element[i]) && isdigit(element[i + 1]) && i < strlen(element) - 3)
        {
            ++i;
            while (isdigit(element[i]))
            {
                ++i;
            }
            head = push(head, translateToInt(element, low, i));
            countNumberInStack++;
        }
        else if (isdigit(element[i]))
        {
            while (isdigit(element[i]))
            {
                ++i;
            }
            head = push(head, translateToInt(element, low, i));
            countNumberInStack++;
        }
        else
        {
            if (countNumberInStack < 2)
            {
                *isCorrect = false;
                return 0;
            }
            int second = pop(&head);
            int first = pop(&head);
            countNumberInStack -= 2;
            if (second == 0 && element[i] == '/')
            {
                *isCorrect = false;
                return 0;
            }
            head = push(head, calculator(element[i], first, second));
            countNumberInStack++;
        }
    }
    return pop(&head);
}