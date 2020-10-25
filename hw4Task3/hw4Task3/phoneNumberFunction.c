#include "phoneNumberFunction.h"

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

<<<<<<< HEAD
<<<<<<< HEAD
bool checkNumberOfPerson(int size)
=======
bool isPhonebookFull(int size)
>>>>>>> 842dbac9b8c196227204ee25f50bcd4f2e90a675
=======
bool isPhonebookFull(int size)
>>>>>>> 842dbac9b8c196227204ee25f50bcd4f2e90a675
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

<<<<<<< HEAD
<<<<<<< HEAD
bool checkName(struct PhoneBook person[], char name[], int size)
=======
bool doesNameExist(struct PhoneBook person[], char name[], int size)
>>>>>>> 842dbac9b8c196227204ee25f50bcd4f2e90a675
=======
bool doesNameExist(struct PhoneBook person[], char name[], int size)
>>>>>>> 842dbac9b8c196227204ee25f50bcd4f2e90a675
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

<<<<<<< HEAD
<<<<<<< HEAD
bool checkPhone(struct PhoneBook person[], char phone[], int size)
=======
bool doesPhoneExist(struct PhoneBook person[], char phone[], int size)
>>>>>>> 842dbac9b8c196227204ee25f50bcd4f2e90a675
=======
bool doesPhoneExist(struct PhoneBook person[], char phone[], int size)
>>>>>>> 842dbac9b8c196227204ee25f50bcd4f2e90a675
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
<<<<<<< HEAD
<<<<<<< HEAD
=======
=======
>>>>>>> 842dbac9b8c196227204ee25f50bcd4f2e90a675
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
<<<<<<< HEAD
>>>>>>> 842dbac9b8c196227204ee25f50bcd4f2e90a675
=======
>>>>>>> 842dbac9b8c196227204ee25f50bcd4f2e90a675
}