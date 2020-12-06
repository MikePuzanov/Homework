#pragma once

#include "List.h"

// ���������
typedef struct Graph Graph;

// �������� ����� 
Graph* createGraph(int count);

// �������� ������ �������
List* getList(Graph* graph, int i);

// ��� ���������� �����
void fillGraph(Graph* graph, int i, int j, int len);

// �������� ���-�� ������
int getCount(Graph* graph);

// �������� ����� ����� ��������
int getLen(Graph* graph, int i, int j);

// �������� �����
void deleteGraph(Graph** graph);