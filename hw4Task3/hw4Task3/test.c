#include "test.h"

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

bool testForAddPerson()
{
	struct testPhoneBook tests[3] = { {"Eva", "258"}, {"Adam", "147"}, {"Jesus", "369"} };
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
	struct testPhoneBook tests[3] = { {"Eva", "258"}, {"Adam", "147"}, {"Jesus", "369"} };
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
	struct testPhoneBook tests[6] = { {"Eva", "258"}, {"Adam", "147"}, {"Jesus", "369"} };
	FILE* phoneBook = fopen("Test.txt", "w");
	for (int i = 0; i < 3; ++i)
	{
		fprintf(phoneBook, "%s %s\n", tests[i].name, tests[i].phone);
	}
	fclose(phoneBook);
	int check = 0;
	FILE* phoneBook1 = fopen("Test.txt", "r");
	for (int i = 3; i < 6; ++i)
	{
		fscanf(phoneBook1, "%s", &tests[i].name);
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