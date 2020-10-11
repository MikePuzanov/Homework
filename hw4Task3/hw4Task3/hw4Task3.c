#include "Header.h"

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Rus");
    int decide = 0;
    while (decide != -1)
    {
        scanf("%i", &decide);
        switch (decide)
        {
            case 0:
                decide = -1;
            break;
            case 1:

            break;
            case 2:

            break;
            case 3:

            break;
            case 4:

            break;
            case 5:

            break;
        default:
            printf("Введите число от 0 до 5!!!\n");
            break;
        }
    }
}