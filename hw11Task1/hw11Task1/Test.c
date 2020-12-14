#include "Knuth–Morris–Pratt algorithm.h"
#include "Test.h"

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool test()
{
	char string[100] = "В своём стремлении улучшить";
    int indexSymbol = 1;
    int indexString = 1;
    if (!algorithmKMP("Test.txt", string, &indexSymbol, &indexString))
    {
        return false;
    }
    if (indexSymbol != 1 || indexString != 3)
    {
        return false;
    }
    indexSymbol = 1;
    indexString = 1;
    strcpy(string, "В своём стремлении ывап");
    if (algorithmKMP("Test.txt", string, &indexSymbol, &indexString))
    {
        return false;
    }
    return true;
}