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
		cout << "   ������: " << MONEY << "    ���-�� ���: " << Game_col << endl << endl;
		cout << "[1]:������ ���� �� ��������" << //
			endl << "[2]:�������� ����� ����" << //
			endl << "[3]:������� ���� ������ ���" <<//
			endl << "[4]:������������� �� ��������" <<//
			endl << "[5]:������������� �� ����" <<//
			endl << "[6]:������������� �� ���� ������" <<
			endl << "[7]:����� ��� �� ����" <<
			endl << "[8]:����� ��� �� �����" <<
			endl << "[9]:�������� ���� ����" <<
			endl << "[10]:�����" << endl;
		
	}
	void Buy_game()
	{
		cin.ignore();
		char buff[64];
		cout << endl << "������� ���� ";
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
		cout << "�������� ���� ��� ������: " 
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
		cout << "�������� ��� ��� ������: "
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
		cout << endl << "������� ���� ";
		cin.getline(buff, 64);
		Game FG = MainList.FindGame(buff);

		cout << "�������� ��� ��� ���������: "
			<< endl << "1:���"
			<< endl << "2:����"
			<< endl << "3:���� ������"
			<< endl << "4:��� ������������"
			<< endl << "5:����"
			<< endl << "6:�����"
			<< endl << "7:��������"
			<< endl << "8:������ ������" << endl;
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
			cout << "/*/*/*/*/*/* ������� �������� �������� */*/*/*/*/*/*/*/" << endl << endl;
			break;
		}
	}
	void Invert()
	{
		Poriadok = !Poriadok;
	}
};