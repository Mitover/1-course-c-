/*#include <iostream>
#include <math.h>
using namespace std;

void main()
{
int sum=0;

for (int i=20; i < 100; i++)
{

if ( (i % 3)== 0 && ((i % 10) == 2 || (i % 10) == 4 || (i % 10) == 8))
{
sum += i;
}

}
cout << sum;
system("pause");*/
#include <iostream>
using namespace std;

int Sym(long a)
{
	long x = a, y = 0;
	while (a)
	{
		y = y * 10 + a % 10;
		a /= 10;
	}
	cout << "1" << endl;
	return x == y;
}


int main()
{
	int n;
	cin >> n;
	cout << (Sym(n) ? "yes" : "no");
	return 0;
	system("pause");
}

	/* 
     cin >> n; 
     while (n!=0) 
     { 
      if (n > -34 && n < 90 ) 
       {   
           s*=n; 
               } 
       cin>>n;
      } 
     cout << s << endl; 
     system("pause"); */
