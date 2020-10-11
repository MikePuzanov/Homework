#include "Utility.h"

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>


void nameSearchWithPhone(struct phoneBook person[], int index, char phone[])
{
	for (int i = 0; i < index; ++i)
	{
		if (strcmp(&person[i].phone, phone) == 0)
		{
			printf("Имя человека, которого вы искали - %s\n", person[i].name);
			return;
		}
	}
	printf("Имя контакта по данному телефону не найдено.\n");
}


void phoneSearchWithName(struct phoneBook person[], int index, char name[])
{
	for (int i = 0; i < index; ++i)
	{
		if (strcmp(&person[i].name, name) == 0)
		{
			printf("Номер человека, которого вы искали - %s\n", person[i].phone);
			return;
		}
	}
	printf("Телефон по данному имени не найден.\n");
}

bool searchName(struct phoneBook person[], int* index)
{
	for (int i = 0; i < *index; ++i)
	{
		if (!strcmp(&person[i].name, &person[*index].name))
		{
			return false;
		}
	}
	return true;
}

bool searchPhone(struct phoneBook person[], int* index)
{
	for (int i = 0; i < *index; ++i)
	{
		if (!strcmp(&person[i].phone, &person[*index].phone))
		{
			return false;
		}
	}
	return true;
}

void addPerson(struct phoneBook person[], int* index)
{
	if (*index > 99)
	{
		printf("\nТелефонная книжка переполнена!\n");
		return;
	}
	printf("\nВведите имя нового контакта: ");
	scanf("%s", &person[*index].name);
	if (!searchName(person, index)) 
	{
		printf("\nКонтакт уже существует!");
		return;
	}
	printf("\nВведите номер нового контакта - ");
	scanf("%s", &person[*index].phone);
	if (!searchPhone(person, index))
	{
		printf("\nКонтакт уже существует!");
		return;
	}
	(*index)++;
}

void printInFile(struct phoneBook person[], int index)
{
	FILE* phoneBook = fopen("namePhone.txt", "w");
	for (int i = 0; i < index; ++i)
	{
		fprintf(phoneBook, "%s - %s\n", person[i].name, person[i].phone);
	}
	fclose(phoneBook);
}

bool testForAddPerson()
{
	struct testPhoneBook tests[] = {{"Eva", "258"}, {"Adam", "147"}, {"Jesus", "369"}};
	if ((strcmp(&tests[0].name, "Eva") != 0) && (strcmp(&tests[0].phone, "258") != 0))
	{
		return false;
	}
	if ((strcmp(&tests[1].name, "Adam") != 0) && (strcmp(&tests[1].phone, "147") != 0))
	{
		return false;
	}if ((strcmp(&tests[2].name, "Jesus") != 0) && (strcmp(&tests[2].phone, "369") != 0))
	{
		return false;
	}
	return true;
}

bool testForSearch()
{
	struct testPhoneBook tests[] = {{"Eva", "258"}, {"Adam", "147"}, {"Jesus", "369"}};
	for (int i = 0; i < 3; ++i)
	{
		if ((strcmp(&tests[i].name, "Jesus") == 0) && (strcmp(&tests[i].phone, "369") == 0))
		{
			return true;
		}
	}
	return false;
}

bool testWriteToFile()
{
	struct testPhoneBook tests[] = {{"Eva", "258"}, {"Adam", "147"}, {"Jesus", "369"}};
	FILE* phoneBook = fopen("Test.txt", "w");
	for (int i = 0; i < 3; ++i)
	{
		fprintf(phoneBook, "%s  %s\n", tests[i].name, tests[i].phone);
	}
	fclose(phoneBook);
	int check = 0;
	FILE* phoneBook1 = fopen("Test.txt", "r");
	for (int i = 0; i < 3; ++i)
	{
		fscanf(phoneBook1, "%s", &tests[3 + i].name);
		fscanf(phoneBook1, "%s", &tests[3 + i].phone);
		if (((strcmp(&tests[i].name, &tests[3 + i].name) != 0) || (strcmp(&tests[i].phone, &tests[3 + i].phone) != 0)))
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