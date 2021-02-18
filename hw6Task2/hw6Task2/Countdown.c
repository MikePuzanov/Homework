#include "CyclicList.h"
#include "Countdown.h"

#include <stdio.h>
#include <stdlib.h>

int countdown(int warriors, int numberDeadWarrior)
{
    if (warriors < 1)
    {
        return -1;
    }
    if (warriors == 1)
    {
        return 1;
    }
    List* head = init(0);
    for (int i = 0; i < warriors - 1; ++i)
    {
        insert(head, 0, warriors - 1 - i);
    }
    int counter = 0;
    while (getValue(head) != getValue(getNext(head)))
    {
        counter = 0;
        while (counter != numberDeadWarrior - 2)
        {
            head = getNext(head);
            counter++;
        }
        deleteNode(&head);
        head = getNext(head);
    }
    int answer = getValue(head) + 1;
    deleteList(&head);
    return answer;
}