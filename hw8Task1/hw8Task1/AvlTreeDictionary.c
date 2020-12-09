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
	if (root)
	{
		return root->height;
	}
	return 0;
}

int balanceFactor(Dictionary* root)
{
	return height(root->right) - height(root->left);
}

void fixHeight(Dictionary* root)
{
	unsigned char heightLeft = height(root->left);
	unsigned char heightRight = height(root->right);
	if (heightLeft > heightRight)
	{
		root->height = heightLeft + 1;
	}
	else
	{
		root->height = heightRight + 1;
	}
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

Dictionary* insert(Dictionary* root, char key[], char word[])
{
	if (root == NULL)
	{
		Dictionary* newNode = malloc(sizeof(Dictionary));
		char* newKey = malloc(sizeof(char) * (strlen(key) + 1));
		strcpy(newKey, key);
		newNode->key = newKey;
		char* newWord = malloc(sizeof(char) * (strlen(word) + 1));
		newNode->height = 1;
		strcpy(newWord, word);
		newNode->word = newWord;
		newNode->left = NULL;
		newNode->right = NULL;
		root = newNode;
		return root;
	}
	if (strlen(key) == strlen(root->key))
	{
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
	}
	else if (strlen(key) < strlen(root->key))
	{
		root->left = insert(root->left, key, word);
	}
	else
	{
		root->right = insert(root->right, key, word);
	}
	/*if (key < root->key)
	{ 
		root->left = insert(root->left, key, word);
	}
	else if (key > root->key)
	{
		root->right = insert(root->right, key, word);
	}
	else
	{
		strcpy(root->word, word);
		return root;
	}*/
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

bool isKeyExist(Dictionary* root, char key[])
{
	while (strcmp(key, root->key) != 0) /*key != root->key)*/
	{
		if (key < root->key)
		{
			root = root->left;
			if (root == NULL)
			{
				return false;
			}
		}
		else
		{
			root = root->right;
			if (root == NULL)
			{
				return false;
			}
		}
	}
	return true;
}

Dictionary* removeNode(Dictionary* root, char key[]) // удаление ключа k из дерева p
{
	if (root == NULL)
	{
		return 0;
	}
	if (key < root->key)
	{
		root->left = removeNode(root->left, key);
	}
	else if (key > root->key)
	{
		root->right = removeNode(root->right, key);
	}
	else //  k == p->key 
	{
		Dictionary* leftNode = root->left;
		Dictionary* rightNode = root->right;
		char* word[1];
		*word = root->word;
		free(*word);
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

Dictionary* deleteNode(Dictionary* root, char key[])
{
	if (isKeyExist(root, key))
	{
		return removeNode(root, key);
	}
	return root;
}

Dictionary* getNode(Dictionary* root, char key[])
{
	while (key != root->key && root->left != NULL && root->right != NULL)
	{
		if (key < root->key)
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
	return root;
}

void printWord(Dictionary* root)
{
	char word[15];
	strcpy(word, root->word);
	for (int i = 0; i < strlen(word); ++i)
	{
		printf("%c", word[i]);
	}
}

Dictionary* deleteTree(Dictionary* root)
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
		root = NULL;
		return;
	}
	char* word[1];
	*word = root->word;
	free(*word);
	free(root);
	root = NULL;
}

bool isEmpty(Dictionary* root)
{
	return root == NULL;
}