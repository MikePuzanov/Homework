#include "Dictionary.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct
{
	int key;
	char* word;
	struct Node* left;
	struct Node* right;
} Node;

Node* createRoot(int key, const char word)
{
	Node* root = malloc(sizeof(Node));
	if (root == NULL)
	{
		return NULL;
	}
	root->key = key;
	root->left = NULL;
	root->right = NULL;
	if (word != NULL)
	{
		char* newWord = malloc(sizeof(char) * strlen(word) + 1);
		strcpy(newWord, word);
		root->word = newWord;
		return root;
	}
	root->word = NULL;
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

void pushToTree(const char word[], int key, Node* root)
{
	if (root->key == NULL)
	{
		char* newWord = malloc(sizeof(char) * strlen(word) + 1);
		strcpy(newWord, word);
		root->key = key;
		root->word = newWord;
		return;
	}
	root = findRoot(root, key);
	Node* newNode = createRoot(key, word);
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
				root = root->right;
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
	Node* left = current->left;
	while (left->right != NULL)
	{
		leftHeight++;
		left = left->right;
	}
	return left;
}

void deleteNode(Node* root, int key)
{
	Node* delete = findCurrentNode(root, key);
	Node* previous = parent(root, key);
	char* word[1];
	if (delete == NULL)
	{
		return;
	}
	if (delete->right == NULL && delete->left == NULL)
	{
		if (previous->left == delete)
		{
			previous->left = NULL;
		}
		else
		{
			previous->right = NULL;
		}
		*word = delete->word;
		free(root->word);
		free(delete);
		return;
	}
	if (delete->right != NULL && delete->left == NULL)
	{
		if (delete->key < previous->key)
		{
			previous->left = delete->right;
			*word = delete->word;
			free(root->word);
			free(delete);
			return;
		}
		else
		{
			previous->right = delete->right;
			*word = delete->word;
			free(root->word);
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
			free(root->word);
			free(delete);
			return;
		}
		else
		{
			previous->right = delete->left;
			*word = delete->word;
			free(root->word);
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
		free(root->word);
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
	free(root->word);
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