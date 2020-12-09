#include "AvlTreeDictionary.h"
#include "TestAvlDictionary.h"

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

bool test()
{
	Dictionary* root = NULL;
	root = insert(root, 4, "abc");
	root = insert(root, 1, "abc");
	root = insert(root, 2, "abc");
	root = insert(root, 3, "abc");
	root = insert(root, 5, "abc");
	root = insert(root, 6, "abc");
	root = insert(root, 7, "abc");
	root = insert(root, 8, "abc");
	root = insert(root, 9, "abc");
	root = insert(root, 10, "abc");
	root = insert(root, 11, "abc");
	if (root != getNode(root, 4))
	{
		return false;
	}
	root = deleteNode(root, 4);
	if (root != getNode(root, 5))
	{
		return false;
	}
	root = deleteNode(root, 5);
	if (root != getNode(root, 6))
	{
		return false;
	}
	if (isKeyExist(root, 5))
	{
		return false;
	}
	if (!isKeyExist(root, 9))
	{
		return false;
	}
	if (isEmpty(root))
	{
		return false;
	}
	root = deleteTree(root);
	if (!isEmpty(root))
	{
		return false;
	}
	return true;
}