#include "Utility.h"

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>


void nameSearchWithPhone(struct phoneBook person[], int* index, char phone[])
{
	for (int i = 0; i < *index; ++i)
	{
		if (strcmp(&person[i].phone, phone) == 0)
		{
			printf("Имя человека, которого вы искали - %s\n", person[i].name);
			return;
		}
	}
	printf("Имя контакта по данному телефону не найдено.\n");
}


void phoneSearchWithName(struct phoneBook person[], int* index, char name[])
{
	for (int i = 0; i < *index; ++i)
	{
		if (strcmp(&person[i].name, name) == 0)
		{
			printf("Номер человека, которого вы искали - %s\n", person[i].phone);
			return;
		}
	}
	printf("Телефон по данному имени не найден.\n");
}


bool searchPhone(struct phoneBook person[], int* index)
{
	int check = -1;
	for (int i = 0; i < *index; ++i)
	{
		if (!strcmp(person[i].phone, person[*index].phone))
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