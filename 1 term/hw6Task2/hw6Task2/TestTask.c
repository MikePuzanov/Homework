#include "Countdown.h"

#include <stdio.h>
#include <stdbool.h>

bool testTask()
{
    if (countdown(8, 3) != 7)
    {
        return false;
    }
    if (countdown(6, 3) != 1)
    {
        return false;
    }
    if (countdown(4, 5) != 2)
    {
        return false;
    }
    if (countdown(1, 5) != 1)
    {
        return false;
    }
    if (countdown(0, 5) != -1)
    {
        return false;
    }
    return true;
}