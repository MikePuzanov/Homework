#pragma once

#include <stdbool.h>

// Возваращает id скобки
int idParentheses(char symbol);

// Проверяет правильно расстановки скобок
bool checkParentheses(struct StackElement* head, char line[]);