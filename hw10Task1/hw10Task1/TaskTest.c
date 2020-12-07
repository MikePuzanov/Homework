#include "BuildCounties.h"
#include "List.h"

#include <stdbool.h>
#include <stdlib.h>

bool taskTest()
{
	int countOfCountries = 0;
	List** countries = countriesDesigner("Test.txt", &countOfCountries);
	List* capital = getLast(countries[0]);
	if (getCity(getLast(countries[0])) + 1 != 3 || getCity(getLast(countries[1])) + 1 != 4)
	{
		deleteList(&countries[0]);
		deleteList(&countries[1]);
		free(countries);
		return false;
	}
	if (getCity(countries[0]) + 1 != 2 || getCity(countries[1]) + 1 != 1)
	{
		deleteList(&countries[0]);
		deleteList(&countries[1]);
		free(countries);
		return false;
	}
	pop(&countries[1]);
	pop(&countries[0]);
	if (getCity(countries[0]) + 1 != 3 || getCity(countries[1]) + 1 != 4)
	{
		deleteList(&countries[0]);
		deleteList(&countries[1]);
		free(countries);
		return false;
	}
	deleteList(&countries[0]);
	deleteList(&countries[1]);
	free(countries);
	return true;
}