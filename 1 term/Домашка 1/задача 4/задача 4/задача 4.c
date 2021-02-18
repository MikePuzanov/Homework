#include <stdio.h>
#include <math.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Rus");
    int primeNumber = 2;
    int number = 0;
    printf(" Введите число: ");
    scanf("%i", &number);
    printf(" Простые числа:");
    while (primeNumber < number)
    {
        int primeDivider = 0;
        for (int divider = 2; divider <= sqrt(primeNumber); ++divider)
        {
            if (primeNumber % divider == 0)
            {
                primeDivider++;
                break;
            }
        }
        if (primeDivider == 0)
        {
            printf(" %i ", primeNumber);
        }
        primeNumber++;
    }
}