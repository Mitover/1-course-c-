#include <iostream>
using namespace std;

void main()
{
	int size;
	cin >> size;
	int *arr =new int[size];
    for (int i=0; i < size; i++)
	{
		cin >> arr[i];
	}
	int max=arr[0],min=arr[0],sizemax=0,sizemin=0;
	for (int i=0; i<size;i++)
	{ 
		if(max<arr[i])
		{ sizemax=i;
		max=arr[i]; }
		if(min>arr[i])
		{ sizemin=i;
		min=arr[i]; }
	}
     cout<<"max="<<max<<endl;
	 cout<<"min="<<min<<endl;
	 for (int i=sizemax+1; i<sizemin; i++)
	 { 
		 for (int j=sizemin -1; j>i; -j)
         {
			 if (arr[j]%2==0 && arr[j-1] !=0)
			 {
				 arr[j]*=-1;
			 }
		 }
	 }
	 for (int i=0; i<0; i++)
		 cout<< arr[i];
	system ("pause");
	delete arr;
}	

