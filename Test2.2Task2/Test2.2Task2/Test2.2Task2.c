#include "List.h"
#include "Test.h"

#include <stdio.h>

int main()
{
    if (!testList())
    {
        return 4;
    }
    List* head = NULL;
    readFromFile("File.txt", &head);
    List* newList = getNewList(head);
    printList(newList);
    deleteList(&head);
    deleteList(&newList);
}