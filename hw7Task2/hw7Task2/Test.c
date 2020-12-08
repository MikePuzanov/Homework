#include "Tree.h"
#include "Test.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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
			deleteTree(root);
			return false;
		}
	};
	bool correct = true;
	if (countTree(root, &correct) != 4 || !correct)
	{
		deleteTree(root);
		return false;
	}
	char line2[30];
	size = 0;
	deleteTree(root);
	FILE* expression2 = fopen("Test2.txt", "r");
	while ((fscanf(expression2, "%c", &symbol)) != EOF)
	{
		line2[++size] = symbol;
		//++size;
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
			deleteTree(root);
			return false;
		}
	}
	correct = true;
	if (countTree(root, &correct) != 0 || correct)
	{
		deleteTree(root);
		return false;
	}
	return true;
}