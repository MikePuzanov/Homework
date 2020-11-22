#pragma once

#include <stdbool.h>

// ���������
typedef struct Node Node;

// ������� �����
Node* insert(Node* root, int key, char word[]);

// �������� ����� � ������
bool isKeyExist(Node* root, int key);

// �������� ����
Node* deleteNode(Node* root, int key);

// �������� ���� �� �����
Node* getNode(Node* root, int key);

// ������ ����� � ���� 
void printWord(Node* root);

//
Node* deleteTree(Node* root);

//
bool isEmpty(Node* root);