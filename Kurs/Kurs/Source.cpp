#include <iostream>
#include <fstream>
using namespace std;

class Bus
{
	char* name;
	char* routatnumber;
	bool flag;
public:
	friend ostream& operator << (ostream&str, Bus& NewBus)
	{
		str << endl << NewBus.name << endl << NewBus.routatnumber << endl << NewBus.flag << endl;;
		return str;
	}
	friend istream& operator >> (istream& str, Bus& NewBus)
	{
		char* name = new char;
		char* routatnumber = new char;
		bool flag;
		str >> name;
		NewBus.name = name;
		str >> routatnumber;
		NewBus.routatnumber = routatnumber;
		str >> flag;
		NewBus.flag = flag;
		return str;
	}
	void OntheRoad()
	{
		if (this->flag == false) { cout << "������� ��� � ����" << endl; }
		this->flag = false;
	}
	void InthePark()
	{
		if (this->flag == true) { cout << "������� ��� � �����" << endl; }
		this->flag = true;
	}
};

template< class T, class N>
class Collection
{
	struct Element
	{
		T key;
		N data;
		Element *next;
	};
	Element* Head;
	Element* FindEl(T key)
	{
		Element *Find = new Element;
		Find = Head;
		while (Find != nullptr)
		{
			int i = 0;
			bool yes = 1;
			for (Find->key[i]; i < sizeof(Find->key); i++)
			{
				if (Find->key[i] == key[i]) { yes = 1; }

				else { yes = 0; break; }
			}
			if (yes == 0) Find = Find->next;
			else { return Find; break; }
		};
		if (Find == nullptr) { return NULL; }
	}
	void Delete(T key)
	{
		Element*Delete = FindEl(key);
		Element*Buff = Head;
		if (Head&&Head != Delete)
		{
			while (Buff->next != Delete) Buff = Buff->next;
			Buff->next = Buff->next->next;
			delete(Delete);
		}
		else if (Head&&Head == Delete)
		{
			Head = Head->next;
			delete(Delete);
		}
	}
	void ShowData()
	{
		Element *Show = Head;
		while (Show != nullptr)
		{
			Print(Show);
			Show = Show->next;
		};
	}
	void Print(Element*Print) { cout << Print->key << Print->data << "------------------------------------" << endl; }
public:
	void add(N data, T key)
	{
		Element* NewElement = new Element;
		NewElement->key = key;
		NewElement->data = data;
		NewElement->next = Head;
		Head = NewElement;
	}
	Collection() { Head = NULL; }
	void Del(T key) { Delete(key); }
	Element* Find(T key)
	{

		return FindEl(key);
	}
	void show() { ShowData(); }
};
int main()
{
	setlocale(LC_ALL, "Russian");
	Collection<char*, class Bus> *New = new Collection<char*, class  Bus>;
	char choise = '8';
	while (choise != '0')
	{
		cout << "������� �����:" << endl;
		cout << "(1):���� ������" << endl;
		cout << "(2):�������� ��������" << endl;
		cout << "(3):�������� ������ � ������" << endl;
		cout << "(4):�������� ��� ��������" << endl;
		cout << "(5):����������" << endl;
		cout << "(6):��������" << endl;
		cin >> choise;
		
		if (choise == '1')
		{
			char i = '1';
			while (i == '1')
			{
				cout << "������� ������ � ������� (����� ���� ��� ����� ��������)" << endl << "(���� ������� � ����� ������� 1 ���� � ���� ������� 0)" << endl;
				char* key = new char;
				cin >> key;
				Bus NewBus;
				cin >> NewBus;
				New->add(NewBus, key);
				cout << "press 1 to continue or press 0 to exit" << endl;
				cin >> i;
			}
		}
		
		else if (choise == '2')
		{
			char* key = new char;
			cin >> key;
			New->Del(key);
		}
		
		else if (choise == '3')
		{
			char* key = new char;
			cout << "������� ����:";
			cin >> key;
			char i;
			cout << "������� ���� ���� �������� (1) � ����, (2) �� ����=";
			cin >> i;
			if (i == '1') { New->Find(key)->data.InthePark(); }
			else if (i == '2') { New->Find(key)->data.OntheRoad(); }
			else cout << "����������� ������ ������";
		}
		
		else if (choise == '4') { New->show(); }
		
		else if (choise == '5')
		{
			ofstream SaveData("SaveData.txt");

			char i = '1';
			while (i == '1')
			{
				char* key = new char;
				cout << "������� ����, �������� �������� ���� ���������" << endl;
				cin >> key;
				if (New->Find(key) == NULL) { cout << "Key Not Found" << endl; }
				else
				{
					SaveData << key;
					SaveData << New->Find(key)->data;

					cout << "���������� ������ ������ " << key << " ���������" << endl;
				}
				cout << "��� ���������� ��� �������� ������� 1 ��� ������ ������� ����� ����� ��� �����=";
				cin >> i;
			}
			SaveData.close();
		}

		else if (choise == '6')
		{
			ifstream LoadData("SaveData.txt");
			if (!LoadData.is_open())cout << "���������� �� �������" << endl;
			else
			{
				while (!LoadData.eof())
				{
					Bus NewBus;
					char* key = new char;
					LoadData >> key;
					if (key[0] == '\0')break;
					LoadData >> NewBus;
					New->add(NewBus, key);

				}
				LoadData.close(); cout << "�������� ���������" << endl;
			}

		}
		else { cout << "������ �������������� �����" << endl; }
	}
	return 0;
}
