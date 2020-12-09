#include "AvlTreeDictionary.h"
#include "TestAvlDictionary.h"

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

bool test()
{ 
	Dictionary* root = NULL;
	root = insert(root, "4", "abc");
	root = insert(root, "1", "abc");
	root = insert(root, "2", "abc");
	root = insert(root, "3", "abc");
	root = insert(root, "5", "abc");
	root = insert(root, "6", "abc");
	root = insert(root, "7", "abc");
	root = insert(root, "8", "abc");
	root = insert(root, "9", "abc");
	root = insert(root, "10", "abc");
	root = insert(root, "11", "abc");
	if (root != isKeyExist(root, "4"))
	{
		root = deleteTree(root);
		return false;
	}
	root = deleteElement(root, "4");
	if (root != isKeyExist(root, "5"))
	{
		root = deleteTree(root);
		return false;
	}
	root = deleteElement(root, "5");
	if (root != isKeyExist(root, "6"))
	{
		root = deleteTree(root);
		return false;
	}
	if (isEmpty(root))
	{
		root = deleteTree(root);
		return false;
	}
	root = deleteTree(root);
	if (!isEmpty(root))
	{
		root = deleteTree(root);
		return false;
	}
	return true;
}