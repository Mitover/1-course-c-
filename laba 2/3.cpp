#include <iostream>
using namespace std;

void main()
{
   
	int size;
	cin >>size;
	int *arr=new int[size];
	for (int i=0; i<size; i++)
	{
		cin >>arr[i];
	}
	cout<<endl;
	for(int i=0;i<size;i++)
	{
		for(int j=size;j>=0;j--)
		{		
			
		if(arr[j]<0 && i%4==0)
		     {
			arr[i+1]=arr[j];
			cout<<arr[j]<<endl;
		     }
		}	
	}

	for(int i=0;i<size;i++)
	{
		if(arr[i]==0)
			continue;
        cout<<arr[i];	
	}
	delete[] arr;
	system("pause");
}