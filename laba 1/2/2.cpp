#include <iostream> 
#include <math.h> 
using namespace std; 

void main() 
{ 
    int a,b,c,x; 
    cout<<"Input a!=0"; 
    cin>>a; 
    cout<<"Input b"; 
    cin>>b; 
    cout<<"Input c"; 
    cin>>c; 
    if((b*b-4*a*c)>=0) 
    { 
      x=(-1*b+sqrt(b*b-4*a*c))/(2*a); 
      cout<<"First root="<<x<<endl; 
      x=(-1*b-sqrt(b*b-4*a*c))/(2*a); 
      cout<<"Second root="<<x<<endl; 
     } 
     else 
    { 
	cout<<"not roots"<<endl; 
    } 
system ("pause");
}