#include "AvlTree.h"

#include <stdio.h>
#include <stdlib.h>\

typedef struct Tree
{
	Node* root;
}Tree;

typedef struct Node
{
	int key;
	char* word;
	unsigned char height;
	Node* left;
	Node* right;
	//Node(int k) { key = k; left = right = 0; height = 1; }
}Node;

unsigned char height(Node* root)
{
	return root ? root->height : 0;
}

int bfactor(Node* root)
{
	return height(root->right) - height(root->left);
}

void fixheight(Node* root)
{
	unsigned char hl = height(root->left);
	unsigned char hr = height(root->right);
	root->height = (hl > hr ? hl : hr) + 1;
}

Node* rotateright(Node* parent) // правый поворот вокруг p
{
	Node* newParent = parent->left;
	parent->left = newParent->right;
	newParent->right = parent;
	fixheight(parent);
	fixheight(newParent);
	return newParent;
}

Node* rotateleft(Node* parent) // левый поворот вокруг q
{
	Node* newParent = parent->right;
	parent->right = newParent->left;
	newParent->left = parent;
	fixheight(parent);
	fixheight(newParent);
	return newParent;
}

Node* balance(Node* parent) // балансировка узла p
{
	fixheight(parent);
	if (bfactor(parent) == 2)
	{
		if (bfactor(parent->right) < 0)
			parent->right = rotateright(parent->right);
		return rotateleft(parent);
	}
	if (bfactor(parent) == -2)
	{
		if (bfactor(parent->left) > 0)
			parent->left = rotateleft(parent->left);
		return rotateright(parent);
	}
	return parent; // балансировка не нужна
}

Node* insert(Node* root, int key, char word[]) // вставка ключа k в дерево с корнем p
{
	if (root == NULL)
	{
		Node* newNode = malloc(sizeof(Node));
		root->key = key;
		char* newWord = malloc(sizeof(char) * 14);
		strcpy(newWord, word);
		root->word = newWord;
		root->left = NULL;
		root->right = NULL;
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

Node* findmin(Node* p) // поиск узла с минимальным ключом в дереве p 
{
	return p->left ? findmin(p->left) : p;
}

Node* removemin(Node* p) // удаление узла с минимальным ключом из дерева p
{
	if (p->left == 0)
		return p->right;
	p->left = removemin(p->left);
	return balance(p);
}

Node* remove(Node* p, int k) // удаление ключа k из дерева p
{
	if (!p) return 0;
	if (k < p->key)
		p->left = remove(p->left, k);
	else if (k > p->key)
		p->right = remove(p->right, k);
	else //  k == p->key 
	{
		Node* q = p->left;
		Node* r = p->right;
		free(p);
		if (!r) return q;
		Node* min = findmin(r);
		min->right = removemin(r);
		min->left = q;
		return balance(min);
	}
	return balance(p);
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

bool checkKey(Node* root, int key)
{

}