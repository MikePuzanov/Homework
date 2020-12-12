#include "HashTable.h"
#include "Test.h"

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
	setlocale(LC_ALL, "Rus");
	if (!test())
	{
		printf("Тест не пройден!\n");
		return 1;
	}
	printf("Тест пройден!\n");
	Hash* hashTable = createHashTable();
	hashTable = readFromFile(hashTable, "File.txt");
	printFrequency(hashTable);
	printf("\nКоэффициент заполняемости - %f", fillFactor(hashTable));
	float mid = 0;
	int max = 0;
	listLength(hashTable, &max, &mid);
	printf("\nМаксимальная длина - %i\nСредняя длина - %f", max, mid);
	deleteHashTable(&hashTable);
}