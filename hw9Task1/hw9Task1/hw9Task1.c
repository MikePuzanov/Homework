#include "HashTable.h"

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define SIZE 256

int main()
{
	setlocale(LC_ALL, "Rus");
    Hash* hashTable = createHashTable();
	hashTable = readFromFile(hashTable, "File.txt");
	printFrequency(hashTable, "File.txt");
	printf("\nКоэфицент заполняемости - %f", fillFactor(hashTable));
	float mid = 0;
	int max = 0;
	listLenght(hashTable, &max, &mid);
	printf("\nМаксимальная длина - %i\nСредняя длина - %f", max, mid);
}