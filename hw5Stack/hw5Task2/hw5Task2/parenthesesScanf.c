#include "parenthesesScanf.h"
#include "..\..\hw5Stack\hw5Stack\Stack.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool checkParentheses(struct StackElement* head, char line[])
{
    for (int i = 0; i < strlen(line); i++)
    {
        int ascii = ("%c", line[i]);
        if (ascii == 123 || ascii == 91 || ascii == 40)
        {
            head = push(head, ascii);
        }
        if (ascii == 41 || ascii == 93 || ascii == 125)
        {
            int asciiInStack = pop(&head);
            switch (asciiInStack)
            {
            case 123:
                asciiInStack = 125;
                break;
            case 91:
                asciiInStack = 93;
                break;
            case 40:
                asciiInStack = 41;
                break;
            }
            if (asciiInStack != ascii)
            {
                return false;
            }
        }
    }
    if (!isEmpty(head))
    {
        return false;
    }
    return true;
}

bool test()
{
    struct StackElement* head = NULL;
    if (!checkParentheses(head, "(())"))
    {
        return false;
    }
    if (!checkParentheses(head, "({[]})"))
    {
        return false;
    }
    if (checkParentheses(head, "}{"))
    {
        return false;
    }
    if (checkParentheses(head, "({)}"))
    {
        return false;
    }
    if (checkParentheses(head, "]["))
    {
        return false;
    }
    return true;
}