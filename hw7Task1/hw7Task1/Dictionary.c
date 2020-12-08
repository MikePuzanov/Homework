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

Node* createRoot(int key, const char word[])
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
		char* newWord = malloc(sizeof(char) * (strlen(word) + 1));
		strcpy(newWord, word);
		root->word = newWord;
		return root;
	}
	root->word = NULL;
	return root;
}

int getKey(Node* root)
{
	return root->key;
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

void pushToTree(const char word[], int key, Node** root)
{
	if ((*root)->word == NULL)
	{
		char* newWord = malloc(sizeof(char) * strlen(word) + 1);
		strcpy(newWord, word);
		(*root)->key = key;
		(*root)->word = newWord;
		return;
	}
	Node* node = findRoot((*root), key);
	Node* newNode = createRoot(key, word);
	if (key == (*root)->key)
	{
		Node* delete = (*root);
		(*root) = newNode;
		free(delete->word);
		free(delete);
		return;
	}
	if (key > node->key)
	{
		node->right = newNode;
	}
	else
	{
		node->left = newNode;
	}
}

char* getWord(Node* root, int key)
{
	root = findRoot(root, key);
	return key == root->key ? root->word : NULL;
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

void deleteNode(Node** root, int key)
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
			delete->key = NULL;
			delete->word = NULL;
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
		char* newWord = malloc(sizeof(char) * strlen(swapNode->word) + 1);
		strcpy(newWord, swapNode->word);
		delete->word = newWord;
		delete->key = swapNode->key;
		deleteNode(delete->left, swapNode->key);
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
	char* newWord = malloc(sizeof(char) * (strlen(swapNode->word) + 1));
	strcpy(newWord, swapNode->word);
	delete->word = newWord;
	delete->key = swapNode->key;
	deleteNode(delete->left, swapNode->key);
	return;
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
	char* word[1];
	*word = (*root)->word;
	free((*root)->word);
	free(*root);
	*root = NULL;
}