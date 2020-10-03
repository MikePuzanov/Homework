#include <stdio.h>
#include <locale.h>

void transposition(int leftEnd, int rightEnd, int array[])
{
    for (int i = leftEnd; i < (leftEnd + ((rightEnd - leftEnd) / 2)); ++i)
        {
            array[i] = array[i] + array[rightEnd + leftEnd - 1 - i];
            array[rightEnd + leftEnd - 1 - i] = array[i] - array[rightEnd + leftEnd - 1 - i];
            array[i] = array[i] - array[rightEnd + leftEnd - 1 - i];
        }
}

int main()
{
    setlocale(LC_ALL, "Rus");
    int n = 10;
    int m = 5;
    printf(" Введите m и n: ");
    scanf("%i %i", &m, &n);
    int array[100];
    printf(" Введите массив: ");
    for (int i = 0; i < m + n; ++i)
    {
        scanf(" %i", &array[i]);
    }
    transposition(0, m, array);
    transposition(m , m + n, array);
    transposition(0, m + n, array);
    printf(" Изменёный массив: ");
    for (int i = 0; i < m + n; ++i)
    {
        printf("%i ", array[i]);
    }
}