#include "Utility.h"

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

/*
Написать программу — телефонный справочник. Она должна уметь хранить имена и номера телефонов,
в интерактивном режиме осуществлять следующие операции:
    0 - выйти
    1 - добавить запись (имя и телефон)
    2 - распечатать все имеющиеся записи
    3 - найти телефон по имени
    4 - найти имя по телефону
    5 - сохранить текущие данные в файл
    При запуске программа должна читать данные из файла (того самого, в который сохраняет данные),
    если файла нет — начинать с пустой базы номеров. Размер базы ограничен сотней записей.
*/


int main()
{
    setlocale(LC_ALL, "Rus");
    printf("0 - выйти\n");
    printf("1 - добавить запись (имя и телефон)\n");
    printf("2 - распечатать все имеющиеся записи\n");
    printf("3 - найти телефон по имени\n");
    printf("4 - найти имя по телефону\n");
    printf("5 - сохранить текущие данные в файл\n");
    struct phoneBook person[100];
    int index = 0;
    int decide = 0;
    char name[30];
    char phone[20];
    while (decide != -1)
    {
        printf("\nВведите цифру от 0 до 5 - ");
        scanf("%i", &decide);
        switch (decide)
        {
            case 0:
                return 0;
            break;
            case 1:
                addPerson(person, &index);
            break;
            case 2:
                for (int i = 0; i < index; ++i)
                {
                    printf("%s - %s\n", person[i].name, person[i].phone);
                }
            break;
            case 3:
                printf("Введите имя - ");
                scanf("%s", &name);
                phoneSearchWithName(person, &index, name);
            break;
            case 4:
                printf("Введите телефон - ");
                scanf("%s", &phone);
                nameSearchWithPhone(person, &index, phone);
            break;
            case 5:
                printInFile(person, index);
                printf("Запись в файл произведена!\n");
            break;
        default:
            printf("Введите число от 0 до 5!!!\n");
            break;
        }
    }
}