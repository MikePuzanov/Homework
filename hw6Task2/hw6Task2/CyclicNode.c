#include "CyclicNode.h"
#include "../../hw6Node/hw6Node/Node.h"

#include <stdio.h>
#include <stdlib.h>

void init(Node* head)
{
    head->next = head;
}

void popFor(Node** head)
{
    if (head == NULL)
    {
        exit(-1);
    }
    Node* prev = *head;
    Node* delete = prev->next;
    int val = delete->value;
    prev->next = delete->next;
    free(delete);
}