#include "AvlTree.h"

#include <stdio.h>
#include <locale.h>
#include <stdbool.h>
#include <stdlib.h>

int main()
{
    printf("\n0 - Выход.");
    printf("\1 - nДобавить значение по заданному ключу в словарь.\n");
    printf("2 - Получить значение по заданному ключу из словаря.\n");
    printf("3 - Проверить наличие заданного ключа.\n");
    printf("4 - Удалить заданный ключ и связанное с ним значение из словаря.\n");
    bool result = true;
    int key = 0;
    char word[15];
    Node* root = NULL;
    while (result)
    {
        int key = 0;
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
            scanf("%i", &key);
            insert(root, key, word);
            break;
        case 2:
            printf("\nВведите ключ - ");
            scanf("%i", &key);
            Node* nodeInTree = getNode(root, key);
            if (getNode == NULL)
            {
                printf("\nПо данному ключу слова не найдено!\n");
            }
            else
            {
                printf("\nПо данному ключу слова найдено - %s", nodeInTree->word);
            }
            break;
        case 3:

            break;
        case 4:

            break;
        default:
            printf("Повторите ввод.");
            break;
        }
    }
}