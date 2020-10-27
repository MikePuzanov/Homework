#include "TranslateToPolishReverse.h"
#include "../../hw5Stack/hw5Stack/Stack.h"

#include <stdio.h>
#include <ctype.h>
#include <string.h>

int priorityOperator(char symbol)
{
    switch (symbol)
    {
    case '(':
        return 0;
    case ')':
        return 1;
    case '+':
        return 2;
    case '-':
        return 3;
    case '*':
        return 4;
    case '/':
        return 4;
    default:
        return 5;
    }
}

int idOperator(char symbol)
{
    switch (symbol)
    {
    case '(':
        return 40;
    case ')':
        return 41;
    case '+':
        return 43;
    case '-':
        return 45;
    case '*':
        return 42;
    case '/':
        return 47;
    default:
        return;
    }
}

char fromIdToOpertor(int idSymbol)
{
    switch (idSymbol)
    {
    case 40:
        return '(';
    case 41:
        return ')';
    case 43:
        return '+';
    case 45:
        return '-';
    case 42:
        return '*';
    case 47:
        return '/';
    default:
        return;
    }
}

void translateToPolishReverse(struct StackElement* head, char line[], char expression[], int* index)
{
    for (int i = 0; i < strlen(line); ++i)
    {
        int ascii = idOperator(line[i]);
        if (priorityOperator(line[i]) == 5 && i < strlen(line) - 1 && !isdigit(line[i]))
        {
            continue;
        }
        if (isdigit(line[i]))
        {
            while (isdigit(line[i]))
            {
                expression[*index] = line[i];
                (*index)++;
                ++i;
                if (i == strlen(line))
                {
                    break;
                }
            }
            expression[*index] = ' ';
            (*index)++;
            --i;
        }
        int operator = priorityOperator(line[i]);
        if (operator >= 0 && operator < 5)
        {
            if (line[i] == '(')
            {
                head = push(head, idOperator(line[i]));
            }
            else if (line[i] == ')')
            {
                operator = pop(&head);
                while (operator != 40)
                {
                    expression[*index] = fromIdToOpertor(operator);
                    (*index)++;
                    expression[*index] = ' ';
                    (*index)++;
                    operator = pop(&head);
                }
            }
            else
            {
                if (!isEmpty(head))
                {
                    int lastOperator = pop(&head);
                    head = push(head, lastOperator);
                    if (priorityOperator(line[i]) < priorityOperator(lastOperator))
                    {
                        expression[*index] = fromIdToOpertor(pop(&head));
                        (*index)++;
                        expression[*index] = ' ';
                        (*index)++;
                    }
                    else
                    {
                        head = push(head, idOperator(line[i]));
                    }
                }
                else
                {
                    head = push(head, idOperator(line[i]));
                }
            }
        }
    }
    while (!isEmpty(head))
    {
        expression[*index] = fromIdToOpertor(pop(&head));
        (*index)++;
        expression[*index] = ' ';
        (*index)++;
    }
    (*index)--;
}