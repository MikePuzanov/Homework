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
		}
		if (key == 0)
		{
			line[*index] = '-';
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