#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	ifstream fin;
	ofstream fout;
	fout.open("output.txt", ios::trunc);
	fout.close();
	fin.open("input.txt");
	int a_buf[255];
	char bufin[255];
	int n = 0;
	double u = 0;
	while (fin.getline(bufin, 255)) {
		char* str = new char[strlen(bufin)];
		strcpy(str, bufin);
		int l = 0;
		while (l) {
			int k = atoi(str);
			u += k;
			int s = strlen(bufin);
			int j = 0;
			a_buf[n] = k;
			n++;
			do {
				k /= 10;
				j++;
			} while (k != 0);
			l += j + 1;
			str += j + 1;
			if (l >= s) break;
		}
	}
	fout.open("output.txt", ios::app);
	for (int j = 0; j < n; j++)
	{
		fout << a_buf[j] << " ";
	}
	fout << u / n << " ";
	fin.close();
	fout.close();

	system("pause");
}