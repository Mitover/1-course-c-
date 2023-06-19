/*#include <iostream>
using namespace std;

void main()
{ 
	int size, sum=0, proiz=1;
	bool a;
	cin>>size; 
	int* arr =new int [];
	for (int i=0; i < size; i++)
	{
		cin>>arr[i];

	}
	cout<<endl;
	for (int i=0; i<size; i++)
	{   
		if(arr[i]<0)
		{
		arr[i]=arr[i]*arr[i];
		}
	cout<<arr[i]<<" ";
	if (arr[i]<arr[i+1])
		a=true;
	else
		a=false;
	}
	for (int i=0; i<size; i++)
	{
		if (a=true)
         sum+=arr[i];
		else
		a=false;
		proiz*=arr[i];
	}
	cout<<"sum="<<sum<<endl;
	cout<<"proiz="<<proiz<<endl;
	system ("pause");
	delete []arr;




}
		*/
		
		#include <iostream>
		#include <time.h>

		using namespace std;

		int main()
		{
		int x[4][4];
		srand(time(NULL));
		unsigned short i = 0, j = 0;
		for (i = 0; i < 4; ++i)
		for(j = 0; j < 4; ++j)
		x[i][j]=rand() % 9;

		for (i = 0; i < 4; ++i)
		{
		for(j = 0; j < 4; ++j)
		cout << x[i][j] << "  ";
		cout << endl;
		}
		system ("pause");
		return 0;
		}