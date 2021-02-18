#include "HashTable.h"
#include "Test.h"
#include "ListTest.h"

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
	setlocale(LC_ALL, "Rus");
	if (!test() || !testList())
	{
		printf("Тест не пройден!\n");
		return 1;
	}
	printf("Тест пройден!\n");
	Hash* hashTable = createHashTable();
	FILE* file = fopen("File.txt", "r");
	while (!feof(file))
	{
		char word[50];
		char symbol = fgetc(file);
		if (symbol == ' ' || symbol == '\n')
		{
			continue;
		}
		int i = 0;
		while (!feof(file) && symbol != '.' && i < 50 && symbol != '\n' && symbol != '-' && symbol != ',' && symbol != ':' && symbol != ';' && symbol != ' ')
		{
			word[i] = symbol;
			symbol = fgetc(file);
			++i;
		}
		word[i] = '\0';
		add(hashTable, word);
	}
	fclose(file);
	printFrequency(hashTable);
	printf("\nКоэффициент заполняемости - %f", fillFactor(hashTable));
	float mid = 0;
	int max = 0;
	listLength(hashTable, &max, &mid);
	printf("\nМаксимальная длина - %i\nСредняя длина - %f", max, mid);
	deleteHashTable(&hashTable);
}