#include "HashTable.h"

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define SIZE 256

int main()
{
    Node** hashTable = malloc(SIZE * sizeof(Node*));
    if (hashTable == NULL)
    {
        return 1;
    }
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
		while (!feof(file) && symbol != '.' && symbol != '-' && symbol != ',' && symbol != ':' && symbol != ';' && symbol != ' ')
		{
			word[i] = symbol;
			symbol = fgetc(file);
			++i;
		}
		word[i] = '\0';
		int index = hashFunction(&word);
		hashTable[index] = insert(&word, &hashTable);
	}
	fclose(file);
	Node* node = hashTable[185];
}