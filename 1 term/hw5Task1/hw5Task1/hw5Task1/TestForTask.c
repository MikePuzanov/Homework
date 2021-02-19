#include "ReversePolishCalculator.h"
#include "TestForTask.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool testForTask()
{
    struct StackElement* head = NULL;
    bool isCorrect = true;
    int answer = reversePolish("1 1 +", &isCorrect);
    if (!isCorrect || answer != 2)
    {
        return false;
    }
    answer = reversePolish("2 1 + 4 1 - *", &isCorrect);
    if (!isCorrect || answer != 9)
    {
        return false;
    }
    answer = reversePolish("5 3 * 3 - 3 /", &isCorrect);
    if (!isCorrect || answer != 4)
    {
        return false;
    }
    answer = reversePolish("1 -", &isCorrect);
    return !isCorrect;
}