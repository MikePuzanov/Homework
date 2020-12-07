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
        return 0;
    }
    List* head = init(-1);
    for (int i = 0; i < warriors; ++i)
    {
        insert(head, 0, warriors - 1 - i);
    }
    int counter = 0;
    while (getValue(head) != getValue(getNext(getNext(head))))
    {
        if (getValue(head) == -1)
        {
            head = getNext(head);
        }
        counter = 0;
        while (counter != numberDeadWarrior - 2)
        {
            if (getValue(getNext(head)) == -1)
            {
                head = getNext(head);
                continue;
            }
            head = getNext(head);
            counter++;
        }
        if (getValue(getNext(head)) == -1)
        {
            head = getNext(head);
        }
        popFor(&head);
        head = getNext(head);
    }
    if (getValue(head) == -1)
    {
        head = getNext(head);
    }
    int answer = getValue(head);
    deleteList(&head);
    return answer;
}