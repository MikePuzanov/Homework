#include "FSM.h"
#include "Test.h"

#include <stdio.h>
#include <stdbool.h>
#include <locale.h>
#include <string.h>

int main()
{
	setlocale(LC_ALL, "Rus");
	if (!test())
	{
		printf("Тест не пройден!\n");
		return 5;
	}
	printf("Тест пройден!\n");
	char string[50];
	printf("\nРегулярное выражение: [A-Za-z] ([A-Za-z] | [0-9] | _ ) *\n\n");
	printf("Введите последовательность символов для проверки - ");
	scanf("%s", &string);
	printf(FSM(string) ? "\nПоследовательность символов является заданным регулярным выражением!" : "\nПоследовательность символов не является заданным регулярным выражением!");
}