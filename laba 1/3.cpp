#include<iostream> 
#include<math.h> 
using namespace std; 

void main() 
{ 
     int s=0; 
     for (int i = 10; i < 100; i++){ 
          s = (i / 10) + (i % 10); 
          s = s + pow(s, 2); 
          if (i == s) 
          { 
                cout << s << endl; 
          } 
     } 
     system("pause"); 
}
