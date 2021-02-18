#include "ListSort.h"
#include "Test.h"

#include <stdbool.h>
#include <stdio.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Rus");
    if (!test())
    {
        printf("Тест не пройден!\n");
        return 5;
    }
    printf("Тест пройден!\n");
    int number = 0;
    List** head = NULL;
    printf("Введите последовательность чисел для сортировки и вывода повторений.\n");
    scanf("%i", &number);
    while (number != 0)
    {
        pushtoList(&head, number);
        scanf("%i", &number);
    }
    printList(head);
    deleteList(&head);
}