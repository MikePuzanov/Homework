#include "readParentheses.h"
#include "../../hw5Stack/hw5Stack/Stack.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int idParentheses(char symbol)
{
    switch (symbol)
    {
        case '(':
            return 0;
        break;
        case ')':
            return 1;
        break;
        case '[':
            return 2;
        break;
        case ']':
            return 3;
        break;
        case '{':
            return 4;
        break;
        case '}':
            return 5;
        break;
    }
}

bool checkParentheses(struct StackElement* head, char line[])
{
    for (int i = 0; i < strlen(line); i++)
    {
        int id = idParentheses(line[i]);
        if (id == 0 || id == 2 || id == 4)
        {
            head = push(head, id);
        }
        if (id == 1 || id == 3 || id == 5)
        {
            int idInStack = pop(&head);
            switch (idInStack)
            {
            case 0:
                idInStack = 1;
                break;
            case 2:
                idInStack = 3;
                break;
            case 4:
                idInStack = 5;
                break;
            }
            if (idInStack != id)
            {
                return false;
            }
        }
    }
    if (head != NULL)
    {
        return false;
    }
    return true;
}