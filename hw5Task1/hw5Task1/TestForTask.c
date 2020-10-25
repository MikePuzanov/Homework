#include "functionForTask.h"
#include "TestForTask.h"

#include <stdio.h>
#include <stdbool.h>

bool testForTask()
{
    if (transfer("12", 0, 2) - 12 > 1)
    {
        return false;
    }
    if (transfer("31", 0, 2) - 31 > 1)
    {
        return false;
    }
    if (transfer("0", 0, 1) - 0 > 1)
    {
        return false;
    }
    if (transfer("-5", 0, 2) - -5 > 1)
    {
        return false;
    }
    if (calculator("+", 0, 5, 10) - 15 > 1)
    {
        return false;
    }
    if (calculator("-", 0, 10, 5) - 5 > 1)
    {
        return false;
    }
    if (calculator("*", 0, 5, 10) - 50 > 1)
    {
        return false;
    }
    if (calculator("/", 0, 10, 5) - 2 > 1)
    {
        return false;
    }
    if (calculator("-", 0, 5, 10) != -5)
    {
        return false;
    }
    return true;
}