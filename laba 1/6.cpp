#include <math.h>
#include <iostream> 
using namespace std;


long double Fact(int i)
{ 
	if (i<0)
		return 0;
	if (i==0)
		return 1;
	else return i*Fact(i-1);
}

void main()
{
	double e, a = -2;
	double k = 0;
	int i = 0;
	cin >> e;
	while (abs(a)>e)
	{
		k+=a;
		a = pow(-2,i)/Fact(i);
		i++;
	}
	cout <<k;
	system ("pause");
}