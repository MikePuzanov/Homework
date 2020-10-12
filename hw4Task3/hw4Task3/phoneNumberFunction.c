#include "phoneNumberFunction.h"

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

bool addPerson(int index)
{
	if (index >= 99)
	{
		return false;
	}
	return true;
}

bool nameSearchWithPhone(struct PhoneBook person[], int index, char phone[], int* indexHelp)
{
	for (int i = 0; i < index; ++i)
	{
		if (strcmp(&person[i].phone, phone) == 0)
		{
			*indexHelp = i;
			return true;
		}
	}
	return false;
}

bool phoneSearchWithName(struct PhoneBook person[], int index, char name[], int* indexHelp)
{
	for (int i = 0; i < index; ++i)
	{
		if (strcmp(&person[i].name, name) == 0)
		{
			*indexHelp = i;
			return true;
		}
	}
	return false;
}

bool searchName(struct PhoneBook person[], int index)
{
	for (int i = 0; i < index; ++i)
	{
		if (!strcmp(&person[i].name, &person[index].name))
		{
			return false;
		}
	}
	return true;
}

bool searchPhone(struct PhoneBook person[], int index)
{
	for (int i = 0; i < index; ++i)
	{
		if (!strcmp(&person[i].phone, &person[index].phone))
		{
			return false;
		}
	}
	return true;
}

void printInFile(struct PhoneBook person[], int index, char* file)
{
	FILE* phoneBook = fopen(file, "w");
	for (int i = 0; i < index; ++i)
	{
		fprintf(phoneBook, "%s - %s\n", person[i].name, person[i].phone);
	}
	fclose(phoneBook);
}