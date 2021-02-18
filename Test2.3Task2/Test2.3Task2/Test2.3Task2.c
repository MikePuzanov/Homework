#include "List.h"
#include "ListTest.h"

#include <stdio.h>
#include <locale.h>
#include <stdbool.h>
#include <stdlib.h>

int main()
{
    setlocale(LC_ALL, "Rus");
    if (!test())
    {
        printf("Тест не пройден!\n");
        return 5;
    }
    printf("Тест пройден!\n");
    List* list = createList();
    list = readFromFile(list, "File.txt");
    printf("Список ");
    printList(list);
    printf(checkSymmetry(list) ? "симметричен!" : "не симметричен!");
    deleteList(&list);
}