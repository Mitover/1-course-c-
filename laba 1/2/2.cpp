#include <iostream> 
#include <math.h> 
using namespace std; 

void main() 
{ 
    int a,b,c,x; 
    cout<<"Vedite a!=0"; 
    cin>>a; 
    cout<<"Vedite b"; 
    cin>>b; 
    cout<<"Vedite c"; 
    cin>>c; 
    if((b*b-4*a*c)>=0) 
    { 
      x=(-1*b+sqrt(b*b-4*a*c))/(2*a); 
      cout<<"Pervii koren raven"<<x<<endl; 
      x=(-1*b-sqrt(b*b-4*a*c))/(2*a); 
      cout<<"Vtoroi koren raven"<<x<<endl; 
     } 
     else 
    { 
	cout<<"net kornei"<<endl; 
    } 
system ("pause");
}