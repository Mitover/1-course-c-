#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>
#include<cstdlib>
#include<string.h>
#include"GameShop.h"
using namespace std;

//� ������� ���������� ���� �������� ���� �������� - ������� � ������� �������.� ������� ������ ���� ��������, ����, ���� ������������, ��� - �� �� ������, 
//� ����� ���������, � ������� ��������� ���� �����.���� ����� ����� ������� � ��������� ���������.������, ���� �������� ����� � ����� ���������, 
//�� �� ������ ���������� �� ���� ����������.
//������������� �������� ����� ��������� ����� ���������, ��������� ���� ����� ������, ������������� ��������� � ������.
//������������ ��, ������ � �������, ����� ����������� ��� ������ �������� �������, ��� � ������ ��������� �� �����������.
//������������ ����� ����������� ����� �� ��������, ���� � ����� ������������.����� � �������� ���� ����� �� ��������(���� ������ ����� ��������, 
//�� ������ ��� ������, ���� ������ ������� ������).
//������ � �������, ������������ ��������� ������ �� �������� �������.��������������� ������ ��������, ����� ������������ �� ���� �������� �����, �������� ��� �� ������.


void main()
{
	setlocale(LC_ALL, "Russian");

	GameShop MyShop;
	

	bool ON = true;
	while (ON)
	{
		MyShop.Menu();
		int answ = 0;
		cin >> answ;
		switch (answ)
		{
		case 1:
			system("cls");
			MyShop.Buy_game();
			break;
		case 2:
			system("cls");
			MyShop.Add_game();
			break;
		case 3:
			system("cls");
			MyShop.Show_All();
			break;
		case 4:
			system("cls");
			MyShop.Sort_by_name();
			cout << "�������������� �� ��������!" << endl;
			break;
		case 5:
			system("cls");
			MyShop.Sort_by_Price();
			cout << "�������������� �� ����!" << endl;
			break;
		case 6:
			system("cls");
			MyShop.Sort_by_date();
			cout << "�������������� �� ���� ������!" << endl;
			break;
		case 7:
			system("cls");
			MyShop.Show_by_lang();
			cout << "����� �� ��������� �����!" << endl;
			break;
		case 8:
			system("cls");
			MyShop.Show_by_Tag();
			cout << "����� �� ��������� ����!" << endl;
			break;
		case 9:
			system("cls");
			MyShop.Change_Info();
			cout << "������� ���� ��� ���������!" << endl;
			break;
		case 10:
			system("cls");
			MyShop.Sort_by_name();
			cout << "������������� ������� ������!" << endl;
			break;
		case 11:
			system("cls");
			ON = false;
			break;
		default:
			break;
		}
	}
	
}

