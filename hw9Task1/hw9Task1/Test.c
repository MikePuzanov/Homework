#include "HashTable.h"
#include "Test.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool test()
{
	Hash* hashTable = createHashTable();
	hashTable = readFromFile(hashTable, "Test.txt");
	if (getHashSize(hashTable) != 10)
	{
		return false;
	}
	if (frequency(hashTable, "sun") != 4)
	{
		return false;
	}
	if (frequency(hashTable, "sunny") != 0)
	{
		return false;
	}
	if (fillFactor(hashTable) - 0.5 > 0.001)
	{
		return false;
	}
	float mid = 0;
	int max = 0;
	listLength(hashTable, &max, &mid);
	if (max != 2)
	{
		return false;
	}
	if (mid - 0.5 > 0.1)
	{
		return false;
	}
	return true;
}