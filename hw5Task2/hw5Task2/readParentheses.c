#include "readParentheses.h"
#include "../../hw5Stack/hw5Stack/Stack.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool checkParentheses(struct StackElement* head, char line[])
{
    for (int i = 0; i < strlen(line); i++)
    {
        if (line[i] == '(' || line[i] == '[' || line[i] == '{')
        {
            head = push(head, (int)line[i]);
        }
        if (line[i] == ')' || line[i] ==']' || line[i] == '}')
        {
            int idInStack = pop(&head);
            switch (idInStack)
            {
            case 40:
                idInStack = 41;
                break;
            case 91:
                idInStack = 93;
                break;
            case 123:
                idInStack = 125;
                break;
            }
            if (idInStack != (int)line[i])
            {
                return false;
            }
        }
    }
    return head == NULL;
}