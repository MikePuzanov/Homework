#include "Dictionary.h"
#include "TaskTest.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool testTask()
{
	Node* root = NULL;
	pushToTree("word", 22, &root);
	pushToTree("lemon", 35, &root);
	pushToTree("pie", 65, &root);
	if (strcmp(getWord(root, 22), "word") != 0)
	{
		deleteTree(&root);
		return false;
	}
	if (getWord(root, 242) != NULL)
	{
		deleteTree(&root);
		return false;
	}
	if (getKey(findRoot(root, 65)) != 65)
	{
		deleteTree(&root);
		return false;
	}
	deleteNode(&root, 22);
	if (getWord(root, 22) != NULL)
	{
		deleteTree(&root);
		return false;
	}
	deleteTree(&root);
	return true;
}