#include "Tree.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

Node* expressionMath(char line[],int* low, int high)
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
			son = expressionMath(line, &low1, high);
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
			symbol = line[*low];
			root->symbol = symbol;
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

char printTree(Node* root)
{
	char line[30];
	int index = 0;
	Node* rootCopy = root;
	while (root->left != NULL)
	{
		if (rootCopy->symbol == '+' || rootCopy->symbol == '-' || rootCopy->symbol == '*' || rootCopy->symbol == '/')
		{
			line[index] = '(';
			index++;
			line[index] = ' ';
			index++;
			line[index] = rootCopy->symbol;
			index++;
		}
		else
		{
			line[index = rootCopy->left; ]
			line[index = ; ]
		}
		rootCopy = rootCopy->left;
	}
}