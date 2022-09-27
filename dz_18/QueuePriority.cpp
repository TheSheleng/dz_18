#include "QueuePriority.h"

void QueuePriority::Show() {
	cout << "\n-------------------------------------\n";
	//Демонстрация очереди
	for (int i = 0; i < QueueLength; i++) {
		cout << Wait[i] << " - " << Pri[i] << "\n\n";
	}
	cout << "\n-------------------------------------\n";
}

QueuePriority::~QueuePriority()
{
	//удаление очереди
	delete[] Wait;
	delete[] Pri;
}

QueuePriority::QueuePriority(int m)
{
	//получаем размер
	MaxQueueLength = m;
	//создаем очередь
	Wait = new string[MaxQueueLength];
	Pri = new int[MaxQueueLength];
	// Изначально очередь пуста
	QueueLength = 0;
}

void QueuePriority::Clear()
{
	// Эффективная "очистка" очереди 
	QueueLength = 0;
}

bool QueuePriority::IsEmpty()
{
	// Пуст?
	return QueueLength == 0;
}

bool QueuePriority::IsFull()
{
	// Полон?
	return QueueLength == MaxQueueLength;
}

int QueuePriority::GetCount()
{
	// Количество присутствующих в стеке элементов
	return QueueLength;
}

void QueuePriority::Add(string c, int p)
{
	// Если в очереди есть свободное место, то увеличиваем количество
	// значений и вставляем новый элемент
	if (!IsFull()) {
		Wait[QueueLength] = c;
		Pri[QueueLength] = p;
		QueueLength++;
	}
}

void QueuePriority::Init()
{
	if (!IsFull()) {
		MenuByList pos_m{
			"Guest",
			"Worker",
			"Director",
			"Supervisor"
		};

		Pri[QueueLength] = pos_m.getChoice("Give request as ...");
		cout << "Enter print text: " << endl;
		string text_p; getline(cin, text_p);
		Wait[QueueLength] = text_p;

		QueueLength++;
	}
}

string QueuePriority::Extract()
{
	// Если в очереди есть элементы, то возвращаем тот, 
	// у которого наивысший приоритет и сдвигаем очередь	
	if (!IsEmpty()) {


		//пусть приоритетный элемент - нулевой
		int max_pri = Pri[0];
		//а приоритетный индекс = 0
		int pos_max_pri = 0;

		//ищем приоритет
		for (int i = 1; i < QueueLength; i++)
			//если встречен более приоритетный элемент
			if (max_pri < Pri[i]) {
				max_pri = Pri[i];
				pos_max_pri = i;
			}

		//вытаскиваем приоритетный элемент
		string temp1 = Wait[pos_max_pri];
		int temp2 = Pri[pos_max_pri];

		//сдвинуть все элементы
		for (int i = pos_max_pri; i < QueueLength - 1; i++) {
			Wait[i] = Wait[i + 1];
			Pri[i] = Pri[i + 1];
		}
		//уменьшаем количество
		QueueLength--;
		// возврат извлеченного элемента	
		return temp1;

	}
	else return "-";
}