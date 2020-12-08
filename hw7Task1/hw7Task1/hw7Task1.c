#include "Dictionary.h"
#include "TaskTest.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Rus");
    if (!testTask())
    {
        printf("");
        return 1;
    }
    printf("Меню выбора:\n");
    printf("0 - Выход.\n");
    printf("1 - Добавить значение по заданному ключу в словарь.\n");
    printf("2 - Получить значение по заданному ключу из словаря.\n");
    printf("3 - Проверить наличие заданного ключа в словаре.\n");
    printf("4 - Удалить заданный ключ и связанное с ним значение из словаря.\n");
    bool isExit = true;
    Node* root = createRoot(NULL, NULL);
    while (isExit)
    {
        int key = 0;
        int choice = 0;
        char word[15];
        printf("\nВыберите ваше действие - ");
        scanf("%i", &choice);
        switch (choice)
        {
        case 0:
            isExit = false;
            printf("\nВыход.");
            break;
        case 1:
            printf("\nВведите слово - ");
            scanf("%s", &word);
            printf("Введите ключ - ");
            scanf("%i", &key);
            pushToTree(word, key, &root);
            break;
        case 2:
            printf("\nВведите ключ - ");
            scanf("%i", &key);
            printf("Найденное слоово - %s\n", getWord(root, key));
            break;
        case 3:
            printf("\nВведите ключ - ");
            scanf("%i", &key);
            if (getKey(findRoot(root, key)) == key)
            {
                printf("\nСлово с таким ключом есть!\n");
                break;
            }
            printf("\nСлова с таким ключом нет!\n");
            break;
        case 4:
            printf("\nВведите ключ - ");
            scanf("%i", &key);
            deleteNode(&root, key);
            break;
        default:
            printf("\nВы ввели номер действия, которого нет в меню!");
            printf("\nПопробуйте еще раз:)\n");
            break;
        }
    }
    deleteTree(&root);
    printf("");
}