#include "TestForTask.h"
#include"ReadParentheses.h"

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool testForTask()
{
    if (!checkParentheses("(())"))
    {
        return false;
    }
    if (!checkParentheses("({[]})"))
    {
        return false;
    }
    if (checkParentheses("}{"))
    {
        return false;
    }
    if (checkParentheses("({)}"))
    {
        return false;
    }
    if (checkParentheses("]["))
    {
        return false;
    }
    return true;
}