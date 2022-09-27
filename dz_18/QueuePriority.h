#pragma once

#include <iostream>
#include <string.h>
#include <time.h>

#include "MenuByList.h"

using namespace std;

class QueuePriority
{
	// �������
	string* Wait;
	// ���������
	int* Pri;
	// ������������ ������ �������
	int MaxQueueLength;
	// ������� ������ �������
	int QueueLength;

public:
	// �����������
	QueuePriority(int m);

	//����������
	~QueuePriority();

	// ���������� ��������
	void Add(string c, int p);
	void Init();

	// ���������� ��������
	string Extract();

	// ������� �������
	void Clear();

	// �������� ������������� ��������� � �������
	bool IsEmpty();

	// �������� �� ������������ �������
	bool IsFull();

	// ���������� ��������� � �������
	int GetCount();

	//������������ �������
	void Show();
};