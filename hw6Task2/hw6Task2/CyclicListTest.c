#include "CyclicList.h"
#include "CyclicListTest.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool testList()
{
    List* head = init(-1);
    for (int i = 0; i < 3; ++i)
    {
        insert(head, 0, i);
    }
    head = getNext(head);
    for (int i = 2; i >= 0; --i)
    {
        if (getValue(head) != i)
        {
            deleteList(&head);
            return false;
        }
    head = getNext(head);
    }
    popFor(&head);
    head = getNext(head);
    if (getValue(head) != 1)
    {
        deleteList(&head);
        return false;
    }
    if (isEmpty(head))
    {
        deleteList(&head);
        return false;
    }
    deleteList(&head);
    return isEmpty(head);
}