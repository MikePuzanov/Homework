#include "HashTable.h"
#include "Test.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool test()
{
	Hash* hashTable = createHashTable();
	hashTable = readFromFile(hashTable, "Test.txt");
	if (getHashSize(hashTable) != 25)
	{
		return false;
	}
	if (frequency(hashTable, hashFunction("sun", 25), "sun") != 4)
	{
		return false;
	}
	if (frequency(hashTable, hashFunction("sunny", 25), "sunny") != 0)
	{
		return false;
	}
	if (fillFactor(hashTable) - 0.2 > 0.001)
	{
		return false;
	}
	float mid = 0;
	int max = 0;
	listLenght(hashTable, &max, &mid);
	if (max != 4)
	{
		return false;
	}
	if (mid - 1.6 > 0.0001)
	{
		return false;
	}
	return true;
}