#pragma once

#include <iostream>
#include <string.h>
#include <time.h>

#include "MenuByList.h"

using namespace std;

class QueuePriority
{
	// Очередь
	string* Wait;
	// Приоритет
	int* Pri;
	// Максимальный размер очереди
	int MaxQueueLength;
	// Текущий размер очереди
	int QueueLength;

public:
	// Конструктор
	QueuePriority(int m);

	//Деструктор
	~QueuePriority();

	// Добавление элемента
	void Add(string c, int p);
	void Init();

	// Извлечение элемента
	string Extract();

	// Очистка очереди
	void Clear();

	// Проверка существования элементов в очереди
	bool IsEmpty();

	// Проверка на переполнение очереди
	bool IsFull();

	// Количество элементов в очереди
	int GetCount();

	//демонстрация очереди
	void Show();
};