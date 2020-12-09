#include "AvlTreeDictionary.h"
#include "TestAvlDictionary.h"

#include <stdio.h>
#include <locale.h>
#include <stdbool.h>
#include <stdlib.h>

int main()
{
    setlocale(LC_ALL, "Rus");
    if (!test())
    {
        return 1;
    }
    printf("0 - Выход.\n");
    printf("1 - Добавить значение по заданному ключу в словарь.\n");
    printf("2 - Получить значение по заданному ключу из словаря.\n");
    printf("3 - Проверить наличие заданного ключа.\n");
    printf("4 - Удалить заданный ключ и связанное с ним значение из словаря.\n");
    bool result = true;
    char key[13];
    char word[30];
    Dictionary* root = NULL;
    while (result)
    {
        int key = 0;
        printf("Выберите дейсвтие - ");
        scanf("%i", &key);
        switch (key)
        {
        case 0:
            result = false;
            break;
        case 1:
            printf("\nВведите слово - ");
            scanf("%s", &word);
            printf("\nВведите ключ - ");
            scanf("%S", &key);
            root = insert(root, key, word);
            break;
        case 2:
            printf("\nВведите ключ - ");
            scanf("%i", &key);
            if (getNode(root, key) == NULL)
            {
                printf("\nПо данному ключу слова не найдено!\n");
            }
            else
            {
                char word[15];
                printf("\nПо данному ключу слова найдено - ");
                printWord(root);
            }
            break;
        case 3:
            printf("\nВведите ключ - ");
            scanf("%i", &key);
            if (isKeyExist(root, key))
            {
                printf("\nТакой ключ есть!");
                break;
            }
                printf("\nТакого ключ нет!");
            break;
        case 4:
            printf("\nВведите ключ - ");
            scanf("%i", &key);
            root = deleteNode(root, key);
            break;
        default:
            printf("Повторите ввод.");
            break;
        }
    }
    root = deleteTree(root);
}