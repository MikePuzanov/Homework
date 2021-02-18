#include <stdio.h>

int main()
{
    int count = 0;
    int kombination[28] = { 0 };
    for (int num1 = 0; num1 < 10; ++num1)
    {
        for (int num2 = 0; num2 < 10; ++num2)
        {
            for (int num3 = 0; num3 < 10; num3++)
            {
                const int sum = num1 + num2 + num3;
                kombination[sum]++;
            }

        }
    }
    for (int sum = 0; sum < 28; ++sum)
    {
        count += kombination[sum] * kombination[sum];
    }
    printf("%i", count);
}
