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
	if (root != getNode(root, "4"))
	{
		deleteTree(root);
		return false;
	}
	root = deleteElement(root, "4");
	if (!isKeyExist(root, "5"))
	{
		deleteTree(root);
		return false;
	}
	root = deleteElement(root, "5");
	if (root != getNode(root, "6"))
	{
		deleteTree(root);
		return false;
	}
	deleteTree(root);
	return true;
}