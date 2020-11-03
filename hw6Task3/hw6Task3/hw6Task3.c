#include "FunctionForList.h"
#include "Sort.h"

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Rus");
    List* head = NULL;
    scanfFromFile("Phonebook.txt", &head);
    bool key = true;
    printf("Меню:");
    printf("\n0 - Выход.");
    printf("\n1 - Сортировать записи по номеру телефона.");
    printf("\n2 - Сортировать записис по имени.");
    printf("\n3 - Вывести записи на экраню.\n");
    while (key)
    {
        int decision = 0;
        printf("\nВыбирете действие - ");
        scanf("%i", &decision);
        switch (decision)
        {
        case 0:
            key = false;
            printf("\nВыход.\n");
            break;
        case 1:
            mergeSortPhone(&head);
            break;
        case 2:
            mergeSortName(&head);
            break;
        case 3:
            printPhonebook(head);
            break;
        default:
            printf("\nВы ввели цифру, которой нет в меню!\n");
            printf("Попробуйте еще раз:)\n");
            break;
        }
    }
}