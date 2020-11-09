#include "TestForTask.h"
#include"readParentheses.h"

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool testForTask()
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