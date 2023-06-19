#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>
#include<cstdlib>
#include<string.h>
#include"GameShop.h"
using namespace std;

//” каждого уважающего себ€ магазина есть интернет - магазин с прайсом товаров.” каждого товара есть название, цена, срок изготовлени€, кол - во на складе, 
//а также категори€, к которой относитс€ этот товар.ќдин товар может входить в несколько категорий.ѕричем, если изменить товар в одной категории, 
//то он должен изменитьс€ во всех категори€х.
//јдминистратор магазина может создавать новые категории, добавл€ть туда новые товары, редактировать категории и товары.
//ѕользователь же, заход€ в магазин, может просмотреть как полный перечень товаров, так и каждую категорию по отдельности.
//ѕользователь может сортировать товар по названию, цене и сроку изготовлени€.“акже в магазине есть поиск по названию(если ввести часть названи€, 
//то найдут все товары, куда входит искома€ строка).
//«аход€ в магазин, пользователь формирует за€вку на доставку товаров.јвтоматизируйте работу магазина, чтобы пользователь не смог заказать товар, которого нет на складе.


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
			cout << "ќтсортированно по алфавиту!" << endl;
			break;
		case 5:
			system("cls");
			MyShop.Sort_by_Price();
			cout << "ќтсортированно по цене!" << endl;
			break;
		case 6:
			system("cls");
			MyShop.Sort_by_date();
			cout << "ќтсортированно по дате выхода!" << endl;
			break;
		case 7:
			system("cls");
			MyShop.Show_by_lang();
			cout << "¬ывод по выбраному €зыку!" << endl;
			break;
		case 8:
			system("cls");
			MyShop.Show_by_Tag();
			cout << "¬ывод по выбраному тегу!" << endl;
			break;
		case 9:
			system("cls");
			MyShop.Change_Info();
			cout << "¬ведите игру дл€ изменени€!" << endl;
			break;
		case 10:
			system("cls");
			MyShop.Sort_by_name();
			cout << "»нвертировать пор€док вывода!" << endl;
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

