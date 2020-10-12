#include "phoneNumberFunction.h"

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

bool test()
{
    struct PhoneBook tests[6] = { {"Eva", "258"}, {"Adam", "147"}, {"Jesus", "369"}, {"Adam", "369"} };
    if (!addPerson(8))
    {
        return false;
    }
    if (addPerson(100))
    {
        return false;
    }
    if (searchName(tests, 3))
    {
        return false;
    }
    if (searchPhone(tests, 3))
    {
        return false;
    }
    int indexHelp = 0;
    if (phoneSearchWithName(tests, 3, "Jesus", &indexHelp))
    {
        if (strcmp(&tests[indexHelp].phone, "369") != 0)
        {
            return false;
        }
    }
    else
    {
        return false;
    }
    if (nameSearchWithPhone(tests, 3, "369", &indexHelp))
    {
        if (strcmp(&tests[indexHelp].name, "Jesus") != 0)
        {
            return false;
        }
    }
    else
    {
        return false;
    }
    printInFile(tests, 3, "Test.txt");
    int check = 0;
    FILE* phoneBook1 = fopen("Test.txt", "r");
    char hyphen;
    for (int i = 3; i < 6; ++i)
    {
        fscanf(phoneBook1, "%s %c", &tests[i].name, &hyphen);
        fscanf(phoneBook1, "%s", &tests[i].phone);
        if (((strcmp(&tests[i - 3].name, &tests[i].name) != 0) || (strcmp(&tests[i - 3].phone, &tests[i].phone) != 0)))
        {
            check = 1;
        }
    }
    fclose(phoneBook1);
    if (check == 1)
    {
        return false;
    }
    return true;
}

int main()
{
    setlocale(LC_ALL, "Rus");
    if (!test())
    {
        printf("Тест не пройден!");
            return 1;
    }
    printf("Тест пройден!\n\n");
    printf("0 - выйти\n");
    printf("1 - добавить запись (имя и телефон)\n");
    printf("2 - распечатать все имеющиеся записи\n");
    printf("3 - найти телефон по имени\n");
    printf("4 - найти имя по телефону\n");
    printf("5 - сохранить текущие данные в файл\n");
    struct PhoneBook person[100];
    int index = 0;
    int indexHelp = -1;
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
                if (!addPerson(index))
                {
                    printf("\nТелефонная книжка переполнена!\n");
                    break;
                }
                printf("\nВведите имя нового контакта: ");
                scanf("%s", &person[index].name);
                if (!searchName(person, index))
                {
                    printf("\nКонтакт уже существует!");
                    break;
                }
                printf("\nВведите номер нового контакта - ");
                scanf("%s", &person[index].phone);
                if (!searchPhone(person, index))
                {
                    printf("\nКонтакт уже существует!");
                    break;
                }
                index++;
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
                if (phoneSearchWithName(person, index, name, &indexHelp))
                {
                    printf("Номер человека, которого вы искали - %s\n", person[indexHelp].phone);
                    break;
                }
                printf("Номер человека по данному имени найти не удалось!\n");
                break;
            case 4:
                printf("Введите телефон - ");
                scanf("%s", &phone);
                if (nameSearchWithPhone(person, index, phone, &indexHelp))
                {
                    printf("Имя человека, которого вы искали - %s\n", person[indexHelp].name);
                    break;
                }
                printf("Имя человека по данному номеру найти не удалось!\n");
                break;
            case 5:
                printInFile(person, index, "namePhone.txt");
                printf("Запись в файл произведена!\n");
                break;
        default:
            printf("Введите число от 0 до 5!!!\n");
            break;
        }
    }
}