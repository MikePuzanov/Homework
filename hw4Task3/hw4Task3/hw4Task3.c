#include "phoneNumberFunction.h"

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

bool test()
{
<<<<<<< HEAD
<<<<<<< HEAD
    struct PhoneBook tests[6] = { {"Eva", "258"}, {"Adam", "147"}, {"Jesus", "369"}, {"Adam", "369"} };
    char name[30];
    char phone[30];
    if (!checkNumberOfPerson(8))
    {
        return false;
    }
    if (checkNumberOfPerson(100))
    {
        return false;
    }
    if (!checkName(tests, "Adam", 3))
    {
        return false;
    }
    if (!checkPhone(tests, "369", 3))
    {
        return false;
    }
    int indexHelp = 0;
=======
=======
>>>>>>> 842dbac9b8c196227204ee25f50bcd4f2e90a675
    struct PhoneBook test[3];
    FILE* phoneBook = fopen("Test.txt", "w");
    fprintf(phoneBook, "Eva - 258\n");
    fprintf(phoneBook, "Adam - 147\n");
    fclose(phoneBook);
    int indexHelp = 0;
    readFromFile(test, &indexHelp, "Test.txt");
    char hyphen = "-";
    fscanf(phoneBook, "%s %c", &test[0].name, &hyphen);
    fscanf(phoneBook, "%s", &test[0].phone);
    fscanf(phoneBook, "%s %c", &test[1].name, &hyphen);
    fscanf(phoneBook, "%s", &test[1].phone);
    if (((strcmp(&test[0].name, "Eva") != 0) || (strcmp(&test[0].phone, "258") != 0)) && (((strcmp(&test[1].name, "Adam") != 0) || (strcmp(&test[1].phone, "147") != 0))))
    {
        return false;
    }
    struct PhoneBook tests[6] = { {"Eva", "258"}, {"Adam", "147"}, {"Jesus", "369"}, {"Adam", "369"} };
    char name[30];
    char phone[20];
    if (!isPhonebookFull(8))
    {
        return false;
    }
    if (isPhonebookFull(100))
    {
        return false;
    }
    if (!doesNameExist(tests, "Adam", 3))
    {
        return false;
    }
    if (!doesPhoneExist(tests, "369", 3))
    {
        return false;
    }
    indexHelp = 0;
<<<<<<< HEAD
>>>>>>> 842dbac9b8c196227204ee25f50bcd4f2e90a675
=======
>>>>>>> 842dbac9b8c196227204ee25f50bcd4f2e90a675
    if (phoneSearchByName(tests, 3, "Jesus", &indexHelp))
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
    if (nameSearchByPhone(tests, 3, "369", &indexHelp))
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
    bool check = true;
    FILE* phoneBook1 = fopen("Test.txt", "r");
<<<<<<< HEAD
<<<<<<< HEAD
    char hyphen = "-";
=======
>>>>>>> 842dbac9b8c196227204ee25f50bcd4f2e90a675
=======
>>>>>>> 842dbac9b8c196227204ee25f50bcd4f2e90a675
    for (int i = 3; i < 6; ++i)
    {
        fscanf(phoneBook1, "%s %c", &tests[i].name, &hyphen);
        fscanf(phoneBook1, "%s", &tests[i].phone);
        if (((strcmp(&tests[i - 3].name, &tests[i].name) != 0) || (strcmp(&tests[i - 3].phone, &tests[i].phone) != 0)))
        {
            check = false;
        }
    }
    fclose(phoneBook1);
    return check;
}

int main()
{
    setlocale(LC_ALL, "Rus");
    if (!test())
    {
        printf("Тест не пройден!");
        return 1;
    }
<<<<<<< HEAD
<<<<<<< HEAD
    printf("Тест пройден!\n\n");
=======
    printf("Тест пройден!\n\n");  
>>>>>>> 842dbac9b8c196227204ee25f50bcd4f2e90a675
=======
    printf("Тест пройден!\n\n");  
>>>>>>> 842dbac9b8c196227204ee25f50bcd4f2e90a675
    printf("0 - выйти\n");
    printf("1 - добавить запись (имя и телефон)\n");
    printf("2 - распечатать все имеющиеся записи\n");
    printf("3 - найти телефон по имени\n");
    printf("4 - найти имя по телефону\n");
    printf("5 - сохранить текущие данные в файл\n");
<<<<<<< HEAD
<<<<<<< HEAD
    struct PhoneBook person[100];
    int index = 0;
=======
    int index = 0;
    struct PhoneBook person[100];
    readFromFile(person, &index, "namePhone.txt");
>>>>>>> 842dbac9b8c196227204ee25f50bcd4f2e90a675
=======
    int index = 0;
    struct PhoneBook person[100];
    readFromFile(person, &index, "namePhone.txt");
>>>>>>> 842dbac9b8c196227204ee25f50bcd4f2e90a675
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
            case 1:
<<<<<<< HEAD
<<<<<<< HEAD
                if (!checkNumberOfPerson(index))
=======
                if (!isPhonebookFull(index))
>>>>>>> 842dbac9b8c196227204ee25f50bcd4f2e90a675
=======
                if (!isPhonebookFull(index))
>>>>>>> 842dbac9b8c196227204ee25f50bcd4f2e90a675
                {
                    printf("\nТелефонная книжка переполнена!\n");
                    break;
                }
                printf("\nВведите имя нового контакта: ");
                scanf("%s", &name);
<<<<<<< HEAD
<<<<<<< HEAD
                if (!checkName(person, name, index))
=======
                if (!doesNameExist(person, name, index))
>>>>>>> 842dbac9b8c196227204ee25f50bcd4f2e90a675
=======
                if (!doesNameExist(person, name, index))
>>>>>>> 842dbac9b8c196227204ee25f50bcd4f2e90a675
                {
                    printf("\nКонтакт уже существует!");
                    break;
                }
                strcpy(person[index].name, name);
                printf("\nВведите номер нового контакта - ");
                scanf("%s", &phone);
<<<<<<< HEAD
<<<<<<< HEAD
                if (!checkPhone(person, phone, index))
=======
                if (!doesPhoneExist(person, phone, index))
>>>>>>> 842dbac9b8c196227204ee25f50bcd4f2e90a675
=======
                if (!doesPhoneExist(person, phone, index))
>>>>>>> 842dbac9b8c196227204ee25f50bcd4f2e90a675
                {
                    printf("\nКонтакт уже существует!");
                    break;
                }
                strcpy(person[index].phone, phone);
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
                if (phoneSearchByName(person, index, name, &indexHelp))
                {
                    printf("Номер человека, которого вы искали - %s\n", person[indexHelp].phone);
                    break;
                }
                printf("Номер человека по данному имени найти не удалось!\n");
                break;
            case 4:
                printf("Введите телефон - ");
                scanf("%s", &phone);
                if (nameSearchByPhone(person, index, phone, &indexHelp))
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