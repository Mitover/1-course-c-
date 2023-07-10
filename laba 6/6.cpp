#include<iostream>
#include<ctime>

using namespace std;
class Begemot
	{
	private:
		int age ,mass;
		bool gender;
	public:
		Begemot(float m)
		{
			mass = m;
			age = 10 + rand() % 15;
			gender = rand() % 2;
		}

		Begemot()
		{
			mass = 200 + (rand() % 30 - 20);
			age = 10 + rand() % 15;
			gender = rand() % 2;
		}
		void Out()
		{
			cout << "Вес:" << mass << endl << "Возраст: " << age << endl << "Пол: " << gender << endl;
		}
		
		void SetTo(Begemot &tmp)
		{
			mass = tmp.mass;
			age = tmp.age;
			gender = tmp.gender;
		}

		Begemot operator+(Begemot &tmp)
		{
			Begemot newone;
			newone.mass = mass + tmp.mass;
			return newone;
		}

		void operator -(Begemot &tmp)
		{
			if (gender = tmp.gender)
			{ 
				delete &tmp;
				cout << "Begemot is dead"<<endl;
			}
			else
			{
				cout << "Inconsistent gender" << endl;
			}
		}
		friend void operator /(Begemot &tmp1, float t)
		{
			tmp1.mass /= t;
			if (tmp1.mass < 0)
			{
				delete &tmp1;
				cout << "Begemot is dead" << endl;
			}
		}
		void operator *(float p)
		{
			 mass * p;
		}
		
		Begemot operator[](int a)
		{
			switch (a)
			{
			case 1:
				cout << "A!" << endl;
				break;
			case 2:
				cout << "Uxodi!" << endl;
				break;
			case 3:
				cout << "Fresh meat!" << endl;
				break;
			default:
				break;
			}
		}
		void operator++()
		{
			age++;
	    }
		
	};


void main()
{
	setlocale(LC_ALL, "russian");
	srand(time(0));

	Begemot Beg1;
	Begemot Beg2;

	Beg1.Out();
	Beg2.Out();

	cout << "сложение бегемотов: " << endl;

	Begemot Dima;
	Dima = Beg1 + Beg2;
	Dima.Out();

	cout << "вычитание бегемотов: " << endl;

	Dima - Beg2;

	cout << "деление бегемота" << endl;

	Beg1 / 3;
	Beg1.Out();
	cout << "Умножение бегемотов" << endl;

	Beg1 * 3;
	Beg1.Out();

	Dima++;
	Dima.Out();
	system("pause");


}