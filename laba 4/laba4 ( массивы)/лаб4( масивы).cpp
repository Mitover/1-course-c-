#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>

using namespace std;

struct Note { // структура
	char* FIO;
	long long int number;
	int data[3];
};
int main() {
	setlocale(LC_ALL, "Russian");
	Note allNote[8];
	int N = 0;
	int ans = 1;

	for (int i = 0; i < 8; i++) {
		char buf[256];
		cout << "Введите Фамилию и Имя" << endl;
		cin.getline(buf, 256);
		char* new_name = new char[strlen(buf) + 1];
		strcpy(new_name, buf);
		new_name[strlen(new_name)] = '\0';
		allNote[i].FIO = new_name;

		cout << "Введите номер телефона" << endl;
		cin >> allNote[i].number;

		cout << "Введите дату[dd mm yyyy]: ";
		for (int j = 0; j < 3; j++) {
			cin >> allNote[i].data[j];
		}
		N++;
		cout << "Продолжите ввод данных ? y/n 1/0" << endl;
		cin >> ans;
		cin.ignore();
		if (ans == 0) {
			break;
		}
	}
	long long int t;
	int item;
	for (int i = 1; i < N; i++) { // сортировка вставкой !
		t = allNote[i].number;
		item = i - 1;
		while (item >= 0 && allNote[item].number > t)
		{
			allNote[item + 1].number = allNote[item].number;
			allNote[item].number = t;
			item--;
		}
	}
	cout << "Введите Фамилию и Имя человека информацию которого нужно получить" << endl;
	char buf[256];
	cin.getline(buf, 256);
	char* newName = new char[strlen(buf) + 1];
	strcpy(newName, buf);
	newName[strlen(newName)] = '\0';
	bool flag = true;
	for (int i = 0; i < N; i++)
	{
		if (!strcmp(allNote[i].FIO, newName)) {
			cout << "Дата рождения: ";
			cout << allNote[i].data[0] << '.';
			cout << allNote[i].data[1] << '.';
			cout << allNote[i].data[2] << endl;
			cout << "Номер телефона: ";
			cout << allNote[i].number << endl;
			flag = false;
		}
	}
	if (flag) {
		cout << "Человек не известен системе :(" << endl;
	}
	delete[] newName;

	system("pause");
}