//============================================================================
// Name        : Fact.cpp
// Author      : f
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <string>
#include <iostream>
using namespace std;
void Show(int * ar)
{
	for (int i = ar[0]; i >=1; --i) {
		cout << ar[i];
	}
}
void Read(string k ,int * ar)
{
	ar[0]=k.length();
	for (int i = 1; i <=ar[0]; ++i) {
		ar[ar[0]-i+1]=k[i-1]-48;
	}
}
void Multiply(int * ar,int digit)
{
	int c=0;
   	for(int i = 1 ; i <= ar[0];i++)
   	{
   		ar[i]=ar[i]*digit+c;
   		c=ar[i]/10;
   		ar[i]=ar[i]%10;
   	}
   	while(c>0)
   	{
   		ar[0]=ar[0]+1;
   		ar[ar[0]]=c%10;
   		c=c/10;
   	}
}
void Factorial(int count,int * ar)
{
	;
	long fac=1;
	for (int i = 1; i <= count; ++i) {

		Multiply(ar, i);
	}
	 Show(ar);
}
int main() {
	int count;
	int max=1000000;
	cin>>count;
	string kk="1";
	int * ar =new int[max];//55 fac
	Read(kk,ar);
//	Show(ar);
	Factorial(count,ar);

	return 0;
}
