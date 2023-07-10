#include <iostream>
#include <math.h>
using namespace std;

void main()
{
	double a=0;
	int n,i=1;
	cin >> n;
	while (i<=n)
	{
		a += (cos(i)/sin(i))+(cos(i+1)/sin(i+1));
		i++;
	}
cout <<a;
}