#include "DFA.h"
#include "Test.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>

int main()
{
	setlocale(LC_ALL, "rus");
	if (!test())
	{
		printf("Тест не пройден!\n");
		return 5;
	}
	printf("Тест пройден!\n\n");
	FILE* file = fopen("File.txt", "r");
	if (file == NULL)
	{
		return 1;
	}
	while (!feof(file))
	{
		char string[1000] = "";
		fgets(string, 1000, file);
		char* answer = DFA(string);
		printf("%s\n", answer);
		free(answer);
	}
	fclose(file);
}