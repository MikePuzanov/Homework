#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <stdbool.h>

int fibonacciRecirsive(int n) 
{
	if (n < 0)
	{
		return -1;
	}
	if (n <= 1)	
	{
		return 1;
	} 
	else
	{
		return fibonacciRecirsive(n - 1) + fibonacciRecirsive(n - 2);
	}
}

int fibonacci(int n) 
{
	int f0 = 1;
	int f1 = 1;
	int sum = 0; 
	if (n < 0)
	{
		f1 = -1;
	}
	for (int i = 0; i < n - 1; ++i)
	{
		sum = f0 + f1;
		f0 = f1;
		f1 = sum;
	}
	return f1;
}

bool test() 
{
	if ((fibonacci(5) != 8) || (fibonacciRecirsive(5) != 8))
	{
		return false;
	}
	if ((fibonacci(0) != 1) || (fibonacciRecirsive(0) != 1))
	{
		return false;
	}
	if ((fibonacci(-5) != -1) || (fibonacciRecirsive(-5) != -1))
	{
		return false;
	}
	return true;
}

int main()
{
	setlocale(LC_ALL, "Rus");
	if (!test())
	{
		printf(" Тест не пройден");
		return 1;
	}
	int n = 0;
	printf(" Здраствуйте, введите номер числа Фибоначчи - ");
	scanf("%i", &n);
	if (n < 0) 
	{
		printf(" Ввод некорректных данных!");
		return 1;
	}
	fibonacci( n);
	printf("Ответ: %i \n", fibonacci(n));
	fibonacciRecirsive(n);
	printf("Ответ: %i \n", fibonacciRecirsive(n));
	printf(" Рекурсивный ход решения начинает проигрывать при поиске чисел больших чем F[30].");
}