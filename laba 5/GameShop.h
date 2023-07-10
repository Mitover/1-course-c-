#include"GameList.h"
using namespace std;
class GameShop
{
private:
	unsigned int MONEY;
	int Game_col;
	bool Poriadok;
	List MainList;
public:
	GameShop()
	{
		MONEY = 100;
		Game_col = 0;
	}
	void Menu()
	{
		cout << "   Деньги: " << MONEY << "    Кол-во игр: " << Game_col << endl << endl;
		cout << "[1]:Купить игру по названию" << //
			endl << "[2]:Добавить новую игру" << //
			endl << "[3]:Вывести весь список игр" <<//
			endl << "[4]:Отсортировать по алфавиту" <<//
			endl << "[5]:Отсортировать по цене" <<//
			endl << "[6]:Отсортировать по дате выхода" <<
			endl << "[7]:Поиск игр по тегу" <<
			endl << "[8]:Поиск игр по языку" <<
			endl << "[9]:Изменить поля игры" <<
			endl << "[10]:Выход" << endl;
		
	}
	void Buy_game()
	{
		cin.ignore();
		char buff[64];
		cout << endl << "Введите игру ";
		cin.getline(buff, 64);
		Game FG = MainList.FindGame(buff);
		MONEY += FG.GetPrice();

	}
	void Add_game()
	{
		MainList.AddNewGame();
		Game_col++;
	}

	void Show_All()
	{
		MainList.ShowAll(Poriadok);
	}
	void Sort_by_name()
	{
		MainList.Sort_by_Name();
	}

	void Sort_by_Price()
	{
		MainList.Sort_by_Price();
	}

	void Sort_by_date()
	{
		MainList.Sort_by_date();
	}

	void Show_by_lang()
	{
		cout << "Выберите язык для вывода: " 
			<< endl << "1:Russian"
			<< endl << "2:English"
			<< endl << "3:German"
			<< endl << "4:Franche"
			<< endl << "5:Chines" << endl;
		int ch = 0;
		cin >> ch;
		MainList.Show_by_Lang(ch - 1, Poriadok);
	}
	void Show_by_Tag()
	{
		cout << "Выберете тег для вывода: "
			<< endl << "1:Action"
			<< endl << "2:RPG"
			<< endl << "3:RTS"
			<< endl << "4:Shooter"
			<< endl << "5:Platformer"
			<< endl << "6:Casual" << endl;
		int ch = 0;
		cin >> ch;
		MainList.Show_by_Tag(ch - 1, Poriadok);
	}
	void Change_Info()
	{
		cin.ignore();
		char buff[64];
		cout << endl << "Введите игру ";
		cin.getline(buff, 64);
		Game FG = MainList.FindGame(buff);

		cout << "Выберите поя для изменения: "
			<< endl << "1:Имя"
			<< endl << "2:Цена"
			<< endl << "3:Дата релиза"
			<< endl << "4:Имя разработчика"
			<< endl << "5:Теги"
			<< endl << "6:Языки"
			<< endl << "7:Описание"
			<< endl << "8:Размер скидки" << endl;
		int ch = 0;
		cin >> ch;
		switch (ch)
		{		
		case 1:
			FG.SetName();
			break;
		case 2:
			FG.SetPrice();
			break;
		case 3:
			FG.SetRelease();
			break;
		case 4:
			FG.SetDevname();
			break;
		case 5:
			FG.SetTags();
			break;
		case 6:
			FG.SetLanguage();
			break;
		case 7:
			FG.SetDescription();
			break;
		case 8:
			FG.SetDiscount();
			break;
		default:
			cout << "/*/*/*/*/*/* Введено неверное значение */*/*/*/*/*/*/*/" << endl << endl;
			break;
		}
	}
	void Invert()
	{
		Poriadok = !Poriadok;
	}
};