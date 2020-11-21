#pragma once

//
typedef struct Node
{
	int key;
	char* word;
	Node* left;
	Node* right;
}Node;

//
unsigned char height(Node* root);

//
int bfactor(Node* root);

//
void fixheight(Node* root);

// правый поворот вокруг p
Node* rotateright(Node* parent);

// левый поворот вокруг q
Node* rotateleft(Node* parent);

// балансировка узла p
Node* balance(Node* parent);

// вставка ключа k в дерево с корнем p
Node* insert(Node* root, int key, char word[]);

// поиск узла с минимальным ключом в дереве p
Node* findmin(Node* p);

// удаление узла с минимальным ключом из дерева p
Node* removemin(Node* p);

// удаление ключа k из дерева p
Node* remove(Node* p, int k);

//
Node* getNode(Node* root, int key);