#pragma once

#include <stdbool.h>

// алгоритм Кнута-Моррисса-Пратта
bool  algorithmKMP(const char* fileName, const char* searchLine, int* indexSymbol, int* indexStringLine);