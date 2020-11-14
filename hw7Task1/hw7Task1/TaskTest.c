#include "Dictionary.h"
#include "TaskTest.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool testTask()
{
	Node* root = createRoot();
	pushToTree("word", 22, root);
	pushToTree("lemon", 35, root);
	pushToTree("pie", 65, root);
	if (strcmp(findCurrentNode(root, 22)->word, "word") != 0)
	{
		return false;
	}
	if (findCurrentNode(root, 242) != NULL)
	{
		return false;
	}
	deleteNode(root, 22);
	if (findCurrentNode(root, 22) != NULL)
	{
		return false;
	}
	deleteTree(root);
	if (root->key == 50)
	{
		return false;
	}
	return true;
}