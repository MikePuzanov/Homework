#include "ReversePolishCalculator.h"
#include "TestForTask.h"

#include <stdio.h>
#include <stdbool.h>

bool testForTask()
{
    if (translateToInt("12", 0, 2) != 12)
    {
        return false;
    }
    if (translateToInt("31", 0, 2) != 31)
    {
        return false;
    }
    if (translateToInt("0", 0, 1) != 0)
    {
        return false;
    }
    if (translateToInt("-5", 0, 2) != -5)
    {
        return false;
    }
    if (calculator('+', 5, 10) != 15)
    {
        return false;
    }
    if (calculator('-', 10, 5) != 5)
    {
        return false;
    }
    if (calculator('*', 5, 10) != 50)
    {
        return false;
    }
    if (calculator('/', 10, 5) != 2)
    {
        return false;
    }
    if (calculator('-', 5, 10) != -5)
    {
        return false;
    }
    return true;
}