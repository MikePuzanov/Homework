#include "Tree.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

typedef struct Node
{
	int key;
	char symbol;
	struct Node* left;
	struct Node* right;
} Node;

bool isOperator(char symbol)
{
	return symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/';
}

int readNumber(char line[], int* index)
{
	int minus = 1;
	if (line[*index] == '-')
	{
		minus = -1;
		(*index)++;
	}
	int power = 1;
	int number = 0;
	while (isdigit(line[*index]))
	{
		number += number * power + ((int)line[*index] - '0');
		power *= 10;
		(*index)++;
	}
	(*index)--;
	number *= minus;
	return number;
}

Node* buildTree(char line[], int* low, int high)
{
	char symbol = ' ';
	char sign = ' ';
	Node* root = malloc(sizeof(Node));
	root->left = NULL;
	root->right = NULL;
	while (line[*low] != ')' && (*low) < high)
	{
		if (line[*low] == '(')
		{
			Node* son = malloc(sizeof(Node));
			(*low)++;
			son = buildTree(line, low, high);
			if (root->left == NULL)
			{
				root->left = son;
			}
			else
			{
				root->right = son;
			}
		}
		
		if (isOperator(line[*low]) && line[*low + 1] == ' ')
		{
			root->symbol = line[*low];
		}
		if (line[*low] == '-' && isdigit(line[*low + 1]) || isdigit(line[*low]))
		{
			Node* son = malloc(sizeof(Node));
			son->left = NULL;
			son->right = NULL;
			son->key = readNumber(line, low);
			if (root->left == NULL)
			{
				root->left = son;
			}
			else
			{
				root->right = son;
			}
		}
		(*low)++;
	}
	return root;
}

Node* checkTree(Node* root)
{
	Node* mainRoot = root;
	if (!isOperator(root->symbol))
	{
		mainRoot = root->left;
		free(root);
		return mainRoot;
	}
	return root;
}

void printNumber(char line[], int key, int* index)
{
	if (key < 0)
	{
		line[*index] = '-';
		(*index)++;
		key *= -1;
	}
	if (key == 0)
	{
		line[*index] = '0';
		(*index)++;
	}
	int divider = 1;
	while (key / divider > 9)
	{
		divider *= 10;
	}
	while (key > 0)
	{
		int mod = key / divider + '0';
		line[*index] = mod;
		key %= divider;
		divider /= 10;
		(*index)++;
	}
	line[*index] = ' ';
	(*index)++;
}

char printTree(Node* root, char line[], int* index)
{
	if (isOperator(root->symbol))
	{
		line[*index] = '(';
		(*index)++;
		line[*index] = ' ';
		(*index)++;
		line[*index] = root->symbol;
		(*index)++;
		line[*index] = ' ';
		(*index)++;
		int index1 = *index;
		printTree(root->left, line, &index1);
		printTree(root->right, line, &index1);
		*index = index1;
		line[*index] = ')';
		(*index)++;
		line[*index] = ' ';
		(*index)++;
		exit;
	}
	else
	{
		printNumber(line, root->key, index);
	}
	return line;
}

int countTree(Node* root, bool* qualityExpression)
{
	bool correct = *qualityExpression;
	if (root->symbol != '/' && root->symbol != '*' && root->symbol != '-' && root->symbol != '+')
	{
		return root->key;
	}
	int number1 = 0;
	int number2 = 0;
	switch (root->symbol)
	{
	case '+':
		number1 = countTree(root->left, &correct);
		number2 = countTree(root->right, &correct);
		*qualityExpression = correct;
		return number1 + number2;
	case '-':
		number1 = countTree(root->left, &correct);
		number2 = countTree(root->right, &correct);
		*qualityExpression = correct;
		return number1 - number2;
	case '*':
		number1 = countTree(root->left, &correct);
		number2 = countTree(root->right, &correct);
		*qualityExpression = correct;
		return number1 * number2;
	case '/':
		number1 = countTree(root->left, &correct);
		number2 = countTree(root->right, &correct);
		*qualityExpression = correct;
		if (number2 == 0)
		{
			*qualityExpression = false;
			return 0;
		}
		return number1 / number2;
	}
}

void deleteTree(Node* root)
{
	if (root == NULL)
	{
		return;
	}
	if (root->left != NULL)
	{
		deleteTree(root->left);
	}
	if (root->right != NULL)
	{
		deleteTree(root->right);
	}
	free(root);
}