#include "phoneNumberFunction.h"

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

bool isPhonebookFull(int size)
{
	return size < 99;
}

bool nameSearchByPhone(struct PhoneBook person[], int size, char phone[], int* indexHelp)
{
	for (int i = 0; i < size; ++i)
	{
		if (strcmp(&person[i].phone, phone) == 0)
		{
			*indexHelp = i;
			return true;
		}
	}
	return false;
}

bool phoneSearchByName(struct PhoneBook person[], int size, char name[], int* indexHelp)
{
	for (int i = 0; i < size; ++i)
	{
		if (strcmp(&person[i].name, name) == 0)
		{
			*indexHelp = i;
			return true;
		}
	}
	return false;
}

bool doesNameExist(struct PhoneBook person[], char name[], int size)
{
	for (int i = 0; i < size; ++i)
	{
		if (!strcmp(&person[i].name, &name))
		{
			return false;
		}
	}
	return true;
}

bool doesPhoneExist(struct PhoneBook person[], char phone[], int size)
{
	for (int i = 0; i < size; ++i)
	{
		if (!strcmp(&person[i].phone, &phone))
		{
			return false;
		}
	}
	return true;
}

void printInFile(struct PhoneBook person[], int size, char* file)
{
	FILE* phoneBook = fopen(file, "w");
	for (int i = 0; i < size; ++i)
	{
		fprintf(phoneBook, "%s - %s\n", person[i].name, person[i].phone);
	}
	fclose(phoneBook);
}

void readFromFile(struct PhoneBook person[], int* index, char* file)
{
	FILE* phoneBook = fopen(file, "r");
	char hyphen = "-";
	while ((fscanf(phoneBook, "%s %c %s", &person[*index].name, &hyphen, &person[*index].phone)) != EOF)
	{
		++(*index);
	}
	fclose(phoneBook);
}