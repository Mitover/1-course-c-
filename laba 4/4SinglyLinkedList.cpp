#define _CRT_SECURE_NO_WARNINGS //директива пред процесора не обращать внимание на функцию strcpy и другие устаревшие функции.
#include <iostream>
#include <string.h>

using namespace std;

struct Note { // структура
	char* FIO;
	long long int number;
	int data[3];
};

struct Node { // объект структуры Note 
	Note data;
	Node* next;
};

int main() {
	setlocale(LC_ALL, "Russian");
	int ans = 1;
	Node* head = NULL;

	while (ans == 1) { //Ввод данных в поля структуры
		Node* newNode = new Node;
		cout << "Введите Фамилию и Имя: " << endl;
		char* newName = new char[256];
		cin.getline(newName, 256);
		char* actualName = new char[strlen(newName) + 1];
		strcpy(actualName, newName);
		actualName[strlen(actualName)] = '\0';
		newNode->data.FIO = actualName;
		delete[] newName;

		cout << "Введите дату: ";
		for (int i = 0; i < 3; i++) {
			cin >> newNode->data.data[i];
		}

		long long int  num;
		cout << "Введите номер телефона: ";
		cin >> num;
		newNode->data.number = num;

		cout << "Продолжить ввод ? Да - 1, Нет - 0" << endl;
		cin >> ans;
		cin.ignore();
		newNode->next = NULL;
		if (head == NULL) { // Односвязный списк 
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
	Node* iterator = head; // это указатель хранит начало списка (итератор действует со списком)
	if (iterator == NULL) // Проверка на наличие данных в списке для сортировки 
		cout << "Список пуст";
	else if (iterator->next == NULL)
		cout << "Сравнивать нечего" << endl;
	else
	{
		bool flag = true; // Сортировка 
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
	Node* tmp = head; // Ввод фамилии и имя человека,данные которого хотим вывести.
	cout << "Введите Фамилию и Имя человека: ";
	char name_buf[256];
	cin.getline(name_buf, 256);
	char* newName = new char[strlen(name_buf) + 1];
	strcpy(newName, name_buf);
	newName[strlen(name_buf)] = '\0';
	bool flag = true;

	do
	{
		if (!strcmp(newName, tmp->data.FIO)) {
			cout << "Дата рождения: ";
			cout << tmp->data.data[0] << '.';
			cout << tmp->data.data[1] << '.';
			cout << tmp->data.data[2] << ' ' << endl;

			cout << "Номер телефона: ";
			cout << tmp->data.number << endl;
			flag = false;
		}
		tmp = tmp->next;
	} while (tmp != NULL);  // Проверка на наличие человека в системе
	if (flag) {
		cout << "Человек не известен системе: " << endl;
	}
	system("pause");
}