
#include <iostream> 
#include <math.h> 

using namespace std; 

void main () 
{ 
	int N=0; 
	cin >> N; 

	int** A = new int*[N]; 
	for (int i=0;i<N;i++)
	A[i] =new int [N];

    for (int i=0; i<N;i++)
	{
		for(int j=0; j<N;i++)
		{
			cin>>A[i][j];
			cout<< A[i][j];  
		}
		cout<<endl;
	}
	cout<<"test"<<endl;
	double *M = new double[N * 2 - 1]; 

	for (int i = 0; i < N; i++) 
	{ 
		double res = 1; int j = 1, z = i; 
		while (z >= 0) 
		{ 
			res *= A[z][j]; 
			z--; 
			j++; 
		} 
		M[i] = res;
	} 

	for (int i = N; N > 0; i--) 
	{ 
		double res = 1; int j = 1, z = i; 
		while (z <= N + 1) 
		{ 
			res *= A[z][j]; 
			z--; 
			j++; 
		} 
		M[N + (N - z)] = res; 
	} 

	for (int i = 0; i < (N * 2 - 1); i++) { 
		cout << M[i] << " " ; 
	} 
	
	for(int i=0; i < N; i++)
	 delete A[i];
	 delete [] A;
	
	 system("PAUSE"); 
}