#include "ReadParentheses.h"
#include "../../hw5Stack/hw5Stack/Stack.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool checkParentheses(char line[])
{
    struct StackElement* head = NULL;
    for (int i = 0; i < strlen(line); i++)
    {
        if (line[i] == '(' || line[i] == '[' || line[i] == '{')
        {
            head = push(head, (int)line[i]);
        }
        if (line[i] == ')' || line[i] == ']' || line[i] == '}')
        {
            int idInStack = pop(&head);
            switch (idInStack)
            {
            case '(':
                idInStack = ')';
                break;
            case '[':
                idInStack = ']';
                break;
            case '{':
                idInStack = '}';
                break;
            }
            if (idInStack != (int)line[i])
            {
                return false;
            }
        }
    }
    if (!isEmpty(head))
    {
        deleteStack(&head);
        return false;
    }
    return true;
}