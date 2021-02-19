#include "IsRealNumber.h"
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
	char number[30];
	printf("Введите последовательность символов для проверки - ");
	scanf("%s", &number);
	printf(isRealNumber(number) ? "\nПоследовательность символов является числом!" : "\nПоследовательность символов не является числом!");
}