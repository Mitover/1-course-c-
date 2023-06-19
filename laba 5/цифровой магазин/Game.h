#pragma once
using namespace std;
class Game
{
private:
	char *Name;
	unsigned int price;
	int Release;
	char *DevName;
	char *description;
	bool Tags[6];
	bool language[5];
	int discount;
public:
	Game()
	{
		price = 0;
		Release = 0;
		discount = 0;
		for (int i = 0; i < 6; i++)
		{
			Tags[i] = 0;
		}
		for (int i = 0; i < 5; i++)
		{
			language[i] = 0;
		}
	}
	void SetName()
	{
		cin.ignore();
		cout << endl << "Введите название игры: ";
		char buff[64];
		cin.getline(buff, 64);
		Name = new char[strlen(buff) + 1];
		strcpy(Name, buff);
		Name[strlen(Name)] = '\0';
	}
	void SetPrice()
	{
		cout << "Введите цену игры: ";
		do
		{
			cin >> price;

			if (price < 0)
			{
				cout << endl << "Цена должна быть больше нуля, вы же понимаете?0_о";
			}
		} while (price < 0);
	}
	void SetRelease()
	{
		cout << endl << "Введите год релиза: ";
		cin >> Release;
	}
	void SetDevname()
	{
		cin.ignore();
		cout << endl << "Введите имя разработчика: ";
		char buff[64];
		cin.getline(buff, 64);
		DevName = new char[strlen(buff) + 1];
		strcpy(DevName, buff);
		DevName[strlen(DevName)] = '\0';
	}
	void SetDescription()
	{
		cin.ignore();
		cout << endl << "Введите описание: ";
		char buff[600];
		cin.getline(buff, 64);
		description = new char[strlen(buff) + 1];
		strcpy(description, buff);
		description[strlen(description)] = '\0';
	}
	void SetTags()
	{
		for (int i = 0; i < 6; i++)
		{
			Tags[i] = 0;
		}
		cout << endl << "Выбери из списка жанры и запиши их номера подряд без пробела" << endl
			<< endl << "1:Action"
			<< endl << "2:RPG"
			<< endl << "3:RTS"
			<< endl << "4:Shooter"
			<< endl << "5:Platformer"
			<< endl << "6:Casual" << endl;
		int tag;
		cin >> tag;

		while (tag != 0)
		{
			int n = 0;
			n = tag % 10;
			switch (n)
			{
			case 1:
				Tags[0] = 1;
				break;
			case 2:
				Tags[1] = 1;
				break;
			case 3:
				Tags[2] = 1;
				break;
			case 4:
				Tags[3] = 1;
				break;
			case 5:
				Tags[4] = 1;
				break;
			case 6:
				Tags[5] = 1;
				break;
			default:
				break;
			}
			tag /= 10;
		}
	}
	void SetLanguage()
	{
		for (int i = 0; i < 5; i++)
		{
			language[i] = 0;
		}
		cout << endl << "Поддерживаемые языки? Выбери из списка и запиши номера языков подряд без пробела" << endl
			<< endl << "1:Russian"
			<< endl << "2:English"
			<< endl << "3:German"
			<< endl << "4:Franche"
			<< endl << "5:Chines" << endl;
		int leng = 0;
		cin >> leng;
		while (leng != 0)
		{
			int n = 0;
			n = leng % 10;
			switch (n)
			{
			case 1:
				language[0] = 1;
				break;
			case 2:
				language[1] = 1;
				break;
			case 3:
				language[2] = 1;
				break;
			case 4:
				language[3] = 1;
				break;
			case 5:
				language[4] = 1;
				break;
			default:
				break;
			}
			leng = leng / 10;
		}
	}
	void SetDiscount()
	{
		cout << "Введите размер скидки: " << endl;
		cin >> discount;
	}

	void ShortInfo()
	{
		cout << endl << "Название игры: " << Name << endl
			<< "Цена:  " << price - (price*(discount / 100.0)) << "  Со скидкой в "
			<< discount << endl << "//////////////////////////////////////////////" << endl;
	}
	char* GetName()
	{
		return Name;
	}
	char* GetDevName()
	{
		return DevName;
	}
	int GetRelease()
	{
		return Release;
	}
	unsigned int GetPrice()
	{
		return price;
	}
	bool IsHereTag(int tag)
	{
		if (Tags[tag] == true)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	bool IsHereLang(int lan)
	{
		if (language[lan] == true)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};