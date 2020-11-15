#include "Tree.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

Node* buildTree(char line[],int* low, int high)
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
			int low1 = *low;
			son = buildTree(line, &low1, high);
			*low = low1;
			if (root->left == NULL)
			{
				root->left = son;
			}
			else
			{
				root->right = son;
			}
		}
		if ((line[*low] == '+' || line[*low] == '-' || line[*low] == '*' || line[*low] == '/') && line[*low + 1] == ' ')
		{
			root->symbol = line[*low];
		}
		if (line[*low] == '-' && isdigit(line[*low + 1]) || isdigit(line[*low]))
		{
			Node* son = malloc(sizeof(Node));
			son->left = NULL;
			son->right = NULL;
			int minus = 1;
			if (line[*low] == '-')
			{
				minus = -1;
				(*low)++;
			}
			int power = 1;
			int number = 0;
			while (isdigit(line[*low]))
			{
				number += number * power + ((int)line[*low] - 48);
				power *= 10;
				(*low)++;
			}
			(*low)--;
			number *= minus;
			son->key = number;
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
	if (root->symbol != '/' && root->symbol != '*' && root->symbol != '-' && root->symbol != '+')
	{
		mainRoot = root->left;
		free(root);
		return mainRoot;
	}
	return root;
}

char printTree(Node* root, char line[], int* index)
{
	if (root->symbol == '+' || root->symbol == '-' || root->symbol == '*' || root->symbol == '/')
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
		int key = root->key;
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
		int devider = 1;
		while (key / devider > 9)
		{
			devider *= 10;
		}
		while (key > 0)
		{
			int mod = key / devider;
			switch (mod)
			{
			case 0:
				line[*index] = '0';
			break;
			case 1:
				line[*index] = '1';
			break;
			case 2:
				line[*index] = '2';
			break;
			case 3:
				line[*index] = '3';
			break;
			case 4:
				line[*index] = '4';
			break;
			case 5:
				line[*index] = '5';
			break;
			case 6:
				line[*index] = '6';
			break;
			case 7:
				line[*index] = '7';
			break;
			case 8:
				line[*index] = '8';
			break;
			case 9:
				line[*index] = '9';
			break;
			}
			key %= devider;
			devider /= 10;
			(*index)++;
		}
		line[*index] = ' ';
		(*index)++;
		exit;
	}
	return line;
}

int countTree(Node* root, bool* qualityExpression)
{
	bool correct = *qualityExpression;
	int number1 = 0;
	int number2 = 0;
	if (root->symbol != '/' && root->symbol != '*' && root->symbol != '-' && root->symbol != '+')
	{
		return root->key;
	}
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

bool test()
{
	char line1[30];
	int size = 0;
	char symbol = ' ';
	FILE* expression1 = fopen("Test1.txt", "r");
	while ((fscanf(expression1, "%c", &symbol)) != EOF)
	{
		line1[size] = symbol;
		++size;
	}
	fclose(expression1);
	Node* root = NULL;
	int low = 0;
	root = buildTree(line1, &low, size);
	root = checkTree(root);
	char answerLine1[30];
	size = 0;
	char test1[18] = "( * ( + 3 -1 ) 2 )";
	printTree(root, answerLine1, &size);
	for (int i = 0; i < size - 1; ++i)
	{
		if (test1[i] != answerLine1[i])
		{
			return false;
		}
	};
	bool correct = true;
	if (countTree(root, &correct) != 4 || !correct)
	{
		return false;
	}
	char line2[30];
	size = 0;
	deleteTree(root);
	FILE* expression2 = fopen("Test2.txt", "r");
	while ((fscanf(expression2, "%c", &symbol)) != EOF)
	{
		line2[size] = symbol;
		++size;
	}
	fclose(expression2);
	root = NULL;
	low = 0;
	root = buildTree(line2, &low, size);
	root = checkTree(root);
	char answerLine[30];
	size = 0;
	char test2[18] = "( / ( + 1 1 ) 0 )";
	printTree(root, answerLine, &size);
	for (int i = 0; i < size - 1; ++i)
	{
		if (test2[i] != answerLine[i])
		{
			return false;
		}
	}
	correct = true;
	if (countTree(root, &correct) != 0 || correct)
	{
		return false;
	}
	return true;
}
