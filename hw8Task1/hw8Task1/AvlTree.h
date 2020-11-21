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

// ������ ������� ������ p
Node* rotateright(Node* parent);

// ����� ������� ������ q
Node* rotateleft(Node* parent);

// ������������ ���� p
Node* balance(Node* parent);

// ������� ����� k � ������ � ������ p
Node* insert(Node* root, int key, char word[]);

// ����� ���� � ����������� ������ � ������ p
Node* findmin(Node* p);

// �������� ���� � ����������� ������ �� ������ p
Node* removemin(Node* p);

// �������� ����� k �� ������ p
Node* remove(Node* p, int k);

//
Node* getNode(Node* root, int key);