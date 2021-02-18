#include <stdio.h>
#include <math.h>
#include <locale.h>


int division() 
{
    int dividend = 0;
    int divider = 0;
    printf("Введите числа: ");
    scanf("%i %i", &dividend, &divider);
    int quotient = 0;
    if (divider == 0)
    {
        printf("На 0 делить нельзя!!!!");
        return 0;
    }
    if (dividend == 0)
    {
        quotient = 0;
    }
    int dividendUse = abs(dividend);
    int dividerUse = abs(divider);
    while (dividendUse >= dividerUse)
    {
        dividendUse = dividendUse - dividerUse;
        quotient++;
    }
    if ( dividend > 0 && divider < 0)
    {
        quotient = -quotient;
    }
    if (dividend < 0 && divider > 0)
    {
        quotient = -quotient - 1;
    }
    if (dividend < 0 && divider < 0)
    {
        quotient = quotient + 1;
    }
    printf("Ответ: %i\n", quotient);
    return 0;
}



int main()
{
    setlocale(LC_ALL, "Rus");
    division();
}