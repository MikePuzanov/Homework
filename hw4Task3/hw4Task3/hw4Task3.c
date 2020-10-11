#include "Utility.h"

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

int main()
{
    setlocale(LC_ALL, "Rus");
    if (!testForAddPerson())
    {
        printf("Тест для добавление записи не пройден!");
        return 1;
    }
    printf("Тест для добавление записи пройден!\n\n");
    if (!testForSearch())
    {
        printf("Тест для поиска не пройден!");
        return 1;
    }
    printf("Тест для поиска пройден!\n\n");
    if (!testWriteToFile())
    {
        printf("Тест для записи в файл не пройден!");
        return 1;
    }
    printf("Тест для записи в файл пройден!\n\n");
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
                phoneSearchWithName(person, index, name);
            break;
            case 4:
                printf("Введите телефон - ");
                scanf("%s", &phone);
                nameSearchWithPhone(person, index, phone);
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