#pragma once
#include "../../hw6Node/hw6Node/Node.h"

#include <stdlib.h>

// Для создание циклического списка
void init(Node* head);

// Функция удаление узла из циклического списка
void popFor(Node** head);