#pragma once
#include "../../hw6Node/hw6Node/List.h"

#include <stdlib.h>

// Для создание циклического списка
void init(List* head);

// Функция удаление узла из циклического списка
void popFor(List** head);