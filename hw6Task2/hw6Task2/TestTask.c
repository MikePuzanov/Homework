#include "Countdown.h"

#include <stdio.h>
#include <stdbool.h>

bool testTask()
{
    if (countdown(8, 3) != 6)
    {
        return false;
    }
    if (countdown(6, 3) != 0)
    {
        return false;
    }
    if (countdown(4, 5) != 1)
    {
        return false;
    }
    if (countdown(1, 5) != 0)
    {
        return false;
    }
    if (countdown(0, 5) != -1)
    {
        return false;
    }
    return true;
}