#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <stdbool.h>

 //Реализовать возведение в степень — в лоб (за линейное время) и за О(log n).

float powerPerLine(float number, int power)
{
    float const basis = number;
    int plusMinus = 1;
    if (power < 0) 
    {
        plusMinus = 0;
    }
    power = abs(power);
    if (power == 0) 
    {
        number = 1;
    }
    for (int i = 0; i < power - 1; ++i)
    {
        number *= basis;
    }
    if (plusMinus == 0)
    {
        return 1 / number;
    } 
    return number;
}

float powerPerLogn(float number, int power)
{
    float timeAnswer = 1;
    float basis = number;
    number = 1;
    int plusMinus = 1;
    if (power < 0) {
        plusMinus = 0;
    }
    if (power == 1 || power == -1)
    {
        number = basis;
    }
    power = abs(power);
    float square = 1;
    while (power > 1)
    {
        square = basis;
        if ((power % 2) == 1)
        {
            timeAnswer = timeAnswer * basis;
            power--;
        }
        while (power % 2 == 0)
        {
            square = square * square;
            power = power / 2;
        }
        number = square;
        basis = number;
    }
    number *= timeAnswer;
    if (plusMinus == 0)
    {
        return 1 / number;
    } 
    return number;
}

bool test()
{
    if ((((powerPerLine(3, 4)) - 81) > 1) || (((powerPerLogn(3, 4)) - 81) > 1))
    {
        return false;
    }
    if ((((powerPerLine(2, -2)) - 0.25) > 1) || (((powerPerLogn(2, -2)) - 0.25) > 1))
    {
        return false;
    }
    if ((((powerPerLine(5, 0)) - 1) > 1) || (((powerPerLogn(5, 0)) - 1) > 1))
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
        printf(" Тест не пройден!!!");
        return 1;
    }
    float number = 0;
    int power = 0;
    printf(" Здраствуйте, введите основание и степень: ");
    scanf("%f %i", &number, &power);
    powerPerLine(number, power);
    powerPerLogn(number, power);
    printf("Ответ: %f\n", powerPerLine(number, power));
    printf("Ответ: %f\n", powerPerLogn(number, power));
}