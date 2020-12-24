#include "Dictionary.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct Node
{
	int key;
	char* word;
	struct Node* left;
	struct Node* right;
} Node;

Node* createRoot(const int key, const char* word)
{
	Node* root = malloc(sizeof(Node));
	if (root == NULL)
	{
		return NULL;
	}
	root->key = key;
	root->left = NULL;
	root->right = NULL;
	root->word = malloc(sizeof(char) * (strlen(word) + 1));
	strcpy(root->word, word);
	return root;
	return root;
}

int getKey(Node* root)
{
	return root->key;
}

Node* findRoot(Node* root, const int key)
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

void pushToTree(const char* word, const int key, Node** root)
{
	if (*root == NULL)
	{
		*root = createRoot(key, word);
		return;
	}
	if (key == (*root)->key)
	{
		free((*root)->word);
		(*root)->word = malloc(sizeof(char) * (strlen(word) + 1));
		strcpy((*root)->word, word);
		return;
	}
	Node* newNode = createRoot(key, word);
	Node* node = findRoot((*root), key);
	if (key > node->key)
	{
		node->right = newNode;
	}
	else
	{
		node->left = newNode;
	}
}

char* getWord(Node* root, const int key)
{
	root = findRoot(root, key);
	return key == root->key ? root->word : NULL;
}

Node* parent(Node* root, const int key)
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
	Node* left = current->left;
	if (left == NULL)
	{
		Node* right = current->right;
		while (right->left != NULL)
		{
			right = right->left;
		}
		return right;
	}
	while (left->right != NULL)
	{
		left = left->right;
	}
	return left;
}

void deleteNode(Node** root, const int key)
{
	Node* delete = findRoot(*root, key);
	Node* previous = parent(*root, key);
	if (delete->key != key)
	{
		return;
	}
	if (delete == *root)
	{ 
		if (delete->right == NULL && delete->left == NULL)
		{
			free(delete->word);
			free(delete);
			*root = NULL;
			return;
		}
		if (delete->right == NULL && delete->left != NULL)
		{
			*root = delete->left;
			free(delete->word);
			free(delete);
			return;
		}
		if (delete->right != NULL && delete->left == NULL)
		{
			*root = delete->right;
			free(delete->word);
			free(delete);
			return;
		}
		Node* swapNode = findSwapNode(delete);
		free(delete->word);
		char* newWord = malloc(sizeof(char) * (strlen(swapNode->word) + 1));
		strcpy(newWord, swapNode->word);
		delete->word = newWord;
		delete->key = swapNode->key;
		deleteNode(&(delete->left), swapNode->key);
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
		free(delete->word);
		free(delete);
		return;
	}
	if (delete->right != NULL && delete->left == NULL)
	{
		if (delete->key < previous->key)
		{
			previous->left = delete->right;
		}
		else
		{
			previous->right = delete->right;
		}
		free(delete->word);
		free(delete);
		return;
	}
	if (delete->left != NULL && delete->right == NULL)
	{
		if (delete->key < previous->key)
		{
			previous->left = delete->left;
		}
		else
		{
			previous->right = delete->left;
		}
		free(delete->word);
		free(delete);
		return;
	}
	Node* swapNode = findSwapNode(delete);
	free(delete->word);
	delete->word = malloc(sizeof(char) * (strlen(swapNode->word) + 1));
	strcpy(delete->word, swapNode->word);
	delete->key = swapNode->key;
	deleteNode(&(delete->left), swapNode->key);
}

void deleteTree(Node** root)
{
	if ((*root)->left != NULL)
	{
		deleteTree(&((*root)->left));
	}
	if ((*root)->right != NULL)
	{
		deleteTree(&((*root)->right));
	}
	if ((*root)->word == NULL)
	{
		free(*root);
		return;
	}
	free((*root)->word);
	free(*root);
	*root = NULL;
}