#include "Dictionary.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

Node* createRoot()
{
	Node* root = malloc(sizeof(Node));
	if (root == NULL)
	{
		return NULL;
	}
	root->key = 50;
	root->word = NULL;
	root->left = NULL;
	root->right = NULL;
	return root;
}

Node* findRoot(Node* root, int key)
{
	while (true)
	{
		if (key == root->key)
		{
			return root;
		}
		if (key > root->key)
		{
			if (root->right == NULL)
			{
				return root;
			}
			root = root->right;
		}
		else
		{
			if (root->left == NULL)
			{
				return root;
			}
			root = root->left;
		}
	}
}

void pushToTree(char word[], int key, Node* root)
{
	root = findRoot(root, key);
	Node* newNode = malloc(sizeof(Node));
	if (newNode == NULL)
	{
		return NULL;
	}
	if (key == 50)
	{
		char* newWord = malloc(sizeof(char) * 14);
		strcpy(newWord, word);
		root->word = newWord;
		return;
	}
	char* newWord = malloc(sizeof(char) * 14);
	strcpy(newWord, word);
	newNode->word = newWord;
	newNode->key = key;
	newNode->left = NULL;
	newNode->right = NULL;
	if (key > root->key)
	{
		root->right = newNode;
	}
	else
	{
		root->left = newNode;
	}
}

Node* findCurrentNode(Node* root, int key)
{
	while (true)
	{
		if (key == root->key)
		{
			return root;
		}
		if (key > root->key)
		{
			if (root->right != NULL)
			{
				root = root->right;;
			}
			else
			{
				return NULL;
			}
		}
		else
		{
			if (root->left != NULL)
			{
				root = root->left;
			}
			else
			{
				return NULL;
			}
		}
	}
}

Node* parent(Node* root, int key)
{
	Node* previous = NULL;
	while (true)
	{
		if (key == root->key)
		{
			return previous;
		}
		if (key > root->key)
		{
			if (root->right != NULL)
			{
				previous = root;
				root = root->right;;
			}
			else
			{
				return NULL;
			}
		}
		else
		{
			if (root->left != NULL)
			{
				previous = root;
				root = root->left;
			}
			else
			{
				return NULL;
			}
		}
	}
}

Node* findSwapNode(Node* current)
{
	int leftHeight = 0;
	int rightHeight = 0;
	Node* left = current->left;
	while (left->right != NULL)
	{
		leftHeight++;
		left = left->right;
	}
	Node* right = current->right;
	while (right->left != NULL)
	{
		rightHeight++;
		right = right->left;
	}
	if (leftHeight > rightHeight)
	{
		return left;
	}
	else
	{
		return right;
	}
}

void deleteNode(Node* root, int key)
{
	Node* delete = findCurrentNode(root, key);
	Node* previous = parent(root, key);
	char* word[1];
	if (key == 50)
	{
		*word = root->word;
		free(*word);
		root->word == NULL;
		return;
	}
	if (delete == NULL)
	{
		return;
	}
	if (delete->right == NULL && delete->left == NULL)
	{
		previous->left = NULL;
		previous->right = NULL;
		*word = delete->word;
		free(*word);
		free(delete);
		return;
	}
	if (delete->right != NULL && delete->left == NULL)
	{
		if (delete->key < previous->key)
		{
			previous->left = delete->right;
			*word = delete->word;
			free(*word);
			free(delete);
			return;
		}
		else
		{
			previous->right = delete->right;
			*word = delete->word;
			free(*word);
			free(delete);
			return;
		}
	}
	if (delete->left != NULL && delete->right == NULL)
	{
		if (delete->key < previous->key)
		{
			previous->left = delete->left;
			*word = delete->word;
			free(*word);
			free(delete);
			return;
		}
		else
		{
			previous->right = delete->left;
			*word = delete->word;
			free(*word);
			free(delete);
			return;
		}
	}
	Node* swapNode = findSwapNode(delete);
	if (delete->key > previous->key)
	{
		previous->right = swapNode;
		swapNode->right = delete->right;
		swapNode->left = delete->left;
		*word = delete->word;
		free(*word);
		free(delete);
		return;
	}
}

void deleteTree(Node* root)
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
	char* word[1];
	*word = root->word;
	free(*word);
	free(root);
	root = NULL;
}

bool checkWordInTree(Node* root, int key)
{
	if (key == 50)
	{
		return root->word != NULL;
	}
	while (true)
	{
		if (key == root->key)
		{
			return true;
		}
		if (key > root->key)
		{
			if (root->right != NULL)
			{
				root = root->right;;
			}
			else
			{
				return false;
			}
		}
		else
		{
			if (root->left != NULL)
			{
				root = root->left;
			}
			else
			{
				return false;
			}
		}
	}
}