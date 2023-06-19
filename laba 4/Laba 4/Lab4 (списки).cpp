#define _CRT_SECURE_NO_WARNINGS //��������� ���� ��������� �� �������� �������� �� ������� strcpy � ������ ���������� �������.
#include <iostream>
#include <string.h>

using namespace std;

struct Note { // ���������
	char* FIO;
	long long int number;
	int data[3];
};

struct Node { // ������ ��������� Note 
	Note data;
	Node* next;
};

int main() {
	setlocale(LC_ALL, "Russian");
	int ans = 1;
	Node* head = NULL;

	while (ans == 1) { //���� ������ � ���� ���������
		Node* newNode = new Node;
		cout << "������� ������� � ���: " << endl;
		char* newName = new char[256];
		cin.getline(newName, 256);
		char* actualName = new char[strlen(newName) + 1];
		strcpy(actualName, newName);
		actualName[strlen(actualName)] = '\0';
		newNode->data.FIO = actualName;
		delete[] newName;

		cout << "������� ����: ";
		for (int i = 0; i < 3; i++) {
			cin >> newNode->data.data[i];
		}

		long long int  num;
		cout << "������� ����� ��������: ";
		cin >> num;
		newNode->data.number = num;

		cout << "���������� ���� ? �� - 1, ��� - 0" << endl;
		cin >> ans;
		cin.ignore();
		newNode->next = NULL;
		if (head == NULL) { // ����������� ����� 
			head = newNode;
		}
		else {
			Node* tmp = head;
			while (tmp->next != NULL)
			{
				tmp = tmp->next;
			}
			tmp->next = newNode;
			tmp = newNode;
		}
	}
	Node* iterator = head; // ��� ��������� ������ ������ ������ (�������� ��������� �� �������)
	if (iterator == NULL) // �������� �� ������� ������ � ������ ��� ���������� 
		cout << "������ ����";
	else if (iterator->next == NULL)
		cout << "���������� ������" << endl;
	else
	{
		bool flag = true; // ���������� 
		while (flag)
		{
			iterator = head;
			flag = false;
			while (iterator->next != NULL) {
				Node* e = iterator->next;
				if (iterator->data.number < e->data.number) {
					flag = true;

					Note tmp = iterator->data;
					iterator->data = e->data;
					e->data = tmp;
				}
				iterator = iterator->next;
			}
		}
	}
	Node* tmp = head; // ���� ������� � ��� ��������,������ �������� ����� �������.
	cout << "������� ������� � ��� ��������: ";
	char name_buf[256];
	cin.getline(name_buf, 256);
	char* newName = new char[strlen(name_buf) + 1];
	strcpy(newName, name_buf);
	newName[strlen(name_buf)] = '\0';
	bool flag = true;

	do
	{
		if (!strcmp(newName, tmp->data.FIO)) {
			cout << "���� ��������: ";
			cout << tmp->data.data[0] << '.';
			cout << tmp->data.data[1] << '.';
			cout << tmp->data.data[2] << ' ' << endl;

			cout << "����� ��������: ";
			cout << tmp->data.number << endl;
			flag = false;
		}
		tmp = tmp->next;
	} while (tmp != NULL);  // �������� �� ������� �������� � �������
	if (flag) {
		cout << "������� �� �������� �������: " << endl;
	}
	system("pause");
}