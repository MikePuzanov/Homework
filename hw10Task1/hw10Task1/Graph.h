#pragma once

// ���������
typedef struct Graph Graph;

// �������� ����� 
Graph* createGraph(int count);

// ��� ���������� �����
void fillGraph(Graph* graph, int i, int j, int distance);

// �������� ���-�� ������
int getCount(Graph* graph);

// �������� ����� ����� ��������
int getLen(Graph* graph, int i, int j);

// �������� �����
void deleteGraph(Graph** graph);