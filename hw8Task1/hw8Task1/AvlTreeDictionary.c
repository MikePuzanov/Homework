#include "AvlTreeDictionary.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct Node
{
	int key;
	char* word;
	unsigned char height;
	Node* left;
	Node* right;
}Node;

unsigned char height(Node* root)
{
	if (root)
	{
		return root->height;
	}
	return 0;
}

int balanceFactor(Node* root)
{
	return height(root->right) - height(root->left);
}

void fixHeight(Node* root)
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

Node* turnRight(Node* parent)
{
	Node* newParent = parent->left;
	parent->left = newParent->right;
	newParent->right = parent;
	fixHeight(parent);
	fixHeight(newParent);
	return newParent;
}

Node* turnLeft(Node* parent)
{
	Node* newParent = parent->right;
	parent->right = newParent->left;
	newParent->left = parent;
	fixHeight(parent);
	fixHeight(newParent);
	return newParent;
}

Node* balance(Node* parent)
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

Node* insert(Node* root, int key, char word[])
{
	if (root == NULL)
	{
		Node* newNode = malloc(sizeof(Node));
		newNode->key = key;
		char* newWord = malloc(sizeof(char) * 14);
		newNode->height = 1;
		strcpy(newWord, word);
		newNode->word = newWord;
		newNode->left = NULL;
		newNode->right = NULL;
		root = newNode;
		return root;
	}
	if (key < root->key)
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
	}
	return balance(root);
}

Node* findSwapNode(Node* root)
{
	return root->left ? findSwapNode(root->left) : root;
}

Node* removeSwap(Node* root) 
{
	if (root->left == 0)
	{
		return root->right;
	}
	root->left = removeSwap(root->left);
	return balance(root);
}

bool isKeyExist(Node* root, int key)
{
	while (key != root->key)
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

Node* removeNode(Node* root, int key) // удаление ключа k из дерева p
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
		Node* leftNode = root->left;
		Node* rightNode = root->right;
		char* word[1];
		*word = root->word;
		free(*word);
		free(root);
		if (rightNode == NULL)
		{
			return leftNode;
		}
		Node* min = findSwapNode(rightNode);
		min->right = removeSwap(rightNode);
		min->left = leftNode;
		return balance(min);
	}
	return balance(root);
}

Node* deleteNode(Node* root, int key)
{
	if (isKeyExist(root, key))
	{
		return removeNode(root, key);
	}
	return root;
}

Node* getNode(Node* root, int key)
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

void printWord(Node* root)
{
	char word[15];
	strcpy(word, root->word);
	for (int i = 0; i < strlen(word); ++i)
	{
		printf("%c", word[i]);
	}
}

Node* deleteTree(Node* root)
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

bool isEmpty(Node* root)
{
	return root == NULL;
}