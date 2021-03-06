#include "AvlTreeDictionary.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct Dictionary
{
	char* key;
	char* word;
	unsigned char height;
	Dictionary* left;
	Dictionary* right;
} Dictionary;

unsigned char height(Dictionary* root)
{
	return root ? root->height : 0;
}

int balanceFactor(Dictionary* root)
{
	return height(root->right) - height(root->left);
}

void fixHeight(Dictionary* root)
{
	unsigned char heightLeft = height(root->left);
	unsigned char heightRight = height(root->right);
	root->height = heightLeft > heightRight ? heightLeft + 1 : heightRight + 1;
}

Dictionary* turnRight(Dictionary* parent)
{
	Dictionary* newParent = parent->left;
	parent->left = newParent->right;
	newParent->right = parent;
	fixHeight(parent);
	fixHeight(newParent);
	return newParent;
}

Dictionary* turnLeft(Dictionary* parent)
{
	Dictionary* newParent = parent->right;
	parent->right = newParent->left;
	newParent->left = parent;
	fixHeight(parent);
	fixHeight(newParent);
	return newParent;
}

Dictionary* balance(Dictionary* parent)
{
	fixHeight(parent);
	if (balanceFactor(parent) == 2)
	{
		if (balanceFactor(parent->right) < 0)
		{
			parent->right = turnRight(parent->right);
		}
		return turnLeft(parent);
	}
	if (balanceFactor(parent) == -2)
	{
		if (balanceFactor(parent->left) > 0)
		{
			parent->left = turnLeft(parent->left);
		}
		return turnRight(parent);
	}
	return parent;
}

Dictionary* insert(Dictionary* root, const char* key, const char* word)
{
	if (root == NULL)
	{
		Dictionary* newNode = malloc(sizeof(Dictionary));
		if (newNode == NULL)
		{
			return NULL;
		}
		newNode->key = malloc(sizeof(char) * (strlen(key) + 1));
		strcpy(newNode->key, key);
		newNode->word = malloc(sizeof(char) * (strlen(word) + 1));
		strcpy(newNode->word, word);
		newNode->height = 1;
		newNode->left = NULL;
		newNode->right = NULL;
		return newNode;
	}
	if (strcmp(key, root->key) < 0)
	{
		root->left = insert(root->left, key, word);
	}
	else if (strcmp(key, root->key) > 0)
	{
		root->right = insert(root->right, key, word);
	}
	else
	{
		strcpy(root->word, word);
		return root;
	}
	return balance(root);
}

Dictionary* findSwapNode(Dictionary* root)
{
	return root->left ? findSwapNode(root->left) : root;
}

Dictionary* removeSwap(Dictionary* root) 
{
	if (root->left == 0)
	{
		return root->right;
	}
	root->left = removeSwap(root->left);
	return balance(root);
}

Dictionary* getNode(Dictionary* root, const char* key)
{
	while (strcmp(key, root->key) != 0 && root->left != NULL && root->right != NULL)
	{
		if (strcmp(key, root->key) < 0)
		{
			root = root->left;
			if (root == NULL)
			{
				return NULL;
			}
		}
		else
		{
			root = root->right;
			if (root == NULL)
			{
				return NULL;
			}
		}
	}
	return strcmp(root->key, key) == 0 ? root : NULL;
}

bool isKeyExist(Dictionary* root, const char* key)
{
	return getNode(root, key);
}

Dictionary* removeNode(Dictionary* root, const char* key)
{
	if (root == NULL)
	{
		return 0;
	}
	if (strcmp(key, root->key) < 0)
	{
		root->left = removeNode(root->left, key);
	}
	else if (strcmp(key, root->key) > 0)
	{
		root->right = removeNode(root->right, key);
	}
	else
	{
		Dictionary* leftNode = root->left;
		Dictionary* rightNode = root->right;
		free(root->key);
		free(root->word);
		free(root);
		if (rightNode == NULL)
		{
			return leftNode;
		}
		Dictionary* min = findSwapNode(rightNode);
		min->right = removeSwap(rightNode);
		min->left = leftNode;
		return balance(min);
	}
	return balance(root);
}

Dictionary* deleteElement(Dictionary* root, const char* key)
{
	return getNode(root, key) != NULL ? removeNode(root, key) : root;
}

void printWord(Dictionary* root)
{
	printf("%s", root->word);
}

void deleteTree(Dictionary* root)
{
	if (root->left != NULL)
	{
		deleteTree(root->left);
	}
	if (root->right != NULL)
	{
		deleteTree(root->right);
	}
	if (root->word == NULL)
	{
		free(root);
		return;
	}
	free(root->key);
	free(root->word);
	free(root);
	return;
}