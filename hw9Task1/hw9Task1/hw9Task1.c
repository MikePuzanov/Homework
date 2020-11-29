#include "HashTable.h"

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define SIZE 256

int main()
{
	setlocale(LC_ALL, "Rus");
    Hash* hashTable = createHashTable();
	FILE* file = fopen("File.txt", "r");
	while (!feof(file))
	{
		char word[25];
		char symbol = fgetc(file);
		if (symbol == ' ' || symbol == '\n')
		{
			continue;
		}
		int i = 0;
		while (!feof(file) && symbol != '.' && symbol != '\n' && symbol != '-' && symbol != ',' && symbol != ':' && symbol != ';' && symbol != ' ')
		{
			word[i] = symbol;
			symbol = fgetc(file);
			++i;
		}
		word[i] = '\0';
		int index = hashFunction(&word);
		hashTable = insert(word, hashTable);
	}
	fclose(file);
	printFrequency(hashTable, "File.txt");
	printf("\nКоэфицент заполняемости - %f", fillFactor(hashTable));
	float mid = 0;
	int max = 0;
	listLenght(hashTable, &max, &mid);
	printf("\nМаксимальная длина - %i\nСредняя длина - %f", max, mid);
}