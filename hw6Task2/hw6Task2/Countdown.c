#include "CyclicList.h"
#include "../../hw6Node/hw6Node/List.h"

#include <stdio.h>
#include <stdlib.h>

int countdown(int n, int m)
{
    if (n < 1)
    {
        return -1;
    }
    if (n == 1)
    {
        return 0;
    }
    List first;
    List* head = &first;
    head->value = -1;
    init(head);
    for (int i = 0; i < n; ++i)
    {
        insert(head, i, i);
    }
    int counter = 0;
    while (head->value != head->next->next->value)
    {
        if (head->value == -1)
        {
            head = head->next;
        }
        counter = 0;
        while (counter != m - 2)
        {
            if (head->next->value == -1)
            {
                head = head->next;
                continue;
            }
            head = head->next;
            counter++;
        }
        if (head->next->value == -1)
        {
            head = head->next;
        }
        popFor(&head);
        head = head->next;
    }
    if (head->value == -1)
    {
        head = head->next;
    }
    int answer = head->value;
    popFor(&(head->next));
    return answer;
}