#include "QueuePriority.h"

void QueuePriority::Show() {
	cout << "\n-------------------------------------\n";
	//������������ �������
	for (int i = 0; i < QueueLength; i++) {
		cout << Wait[i] << " - " << Pri[i] << "\n\n";
	}
	cout << "\n-------------------------------------\n";
}

QueuePriority::~QueuePriority()
{
	//�������� �������
	delete[] Wait;
	delete[] Pri;
}

QueuePriority::QueuePriority(int m)
{
	//�������� ������
	MaxQueueLength = m;
	//������� �������
	Wait = new string[MaxQueueLength];
	Pri = new int[MaxQueueLength];
	// ���������� ������� �����
	QueueLength = 0;
}

void QueuePriority::Clear()
{
	// ����������� "�������" ������� 
	QueueLength = 0;
}

bool QueuePriority::IsEmpty()
{
	// ����?
	return QueueLength == 0;
}

bool QueuePriority::IsFull()
{
	// �����?
	return QueueLength == MaxQueueLength;
}

int QueuePriority::GetCount()
{
	// ���������� �������������� � ����� ���������
	return QueueLength;
}

void QueuePriority::Add(string c, int p)
{
	// ���� � ������� ���� ��������� �����, �� ����������� ����������
	// �������� � ��������� ����� �������
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
	// ���� � ������� ���� ��������, �� ���������� ���, 
	// � �������� ��������� ��������� � �������� �������	
	if (!IsEmpty()) {


		//����� ������������ ������� - �������
		int max_pri = Pri[0];
		//� ������������ ������ = 0
		int pos_max_pri = 0;

		//���� ���������
		for (int i = 1; i < QueueLength; i++)
			//���� �������� ����� ������������ �������
			if (max_pri < Pri[i]) {
				max_pri = Pri[i];
				pos_max_pri = i;
			}

		//����������� ������������ �������
		string temp1 = Wait[pos_max_pri];
		int temp2 = Pri[pos_max_pri];

		//�������� ��� ��������
		for (int i = pos_max_pri; i < QueueLength - 1; i++) {
			Wait[i] = Wait[i + 1];
			Pri[i] = Pri[i + 1];
		}
		//��������� ����������
		QueueLength--;
		// ������� ������������ ��������	
		return temp1;

	}
	else return "-";
}