#include <iostream>
#include <math.h>
#define p 3.14
using namespace std;

void main()
{
	double a,b;
	int x,y,z;
	cout<<" vedite x, y , z"<<endl;
	cin>>x;
	cin>>y;
	cin>>z;
	a=2*cos(x-(p/4))/(1/2+pow(sin(y),2))+acos(x+(p/2));
	b=1+(pow(z,2)/3+pow(z,2)/5);
	cout<<a<<endl;
	cout<<b<<endl;
	system("pause");
}