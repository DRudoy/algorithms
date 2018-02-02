//============================================================================
// Name        : AdegreeN.cpp
// Author      : f
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <string>
#include <iostream>
#include <sstream>
using namespace std;

void Show(int * ar)
{
	for (int i = ar[0]; i >=1; --i) {
		cout<<ar[i];
	}
}
int * Read (string a,int max)
{
	int * ar =new int [max];
	ar[0]=a.length();
	for (int i = 1; i <=ar[0]; ++i) {
		ar[ar[0]-i+1]=a[i-1]-48;
	}
	return ar;
}
void Multiply(int * ar ,int digit)
{
	int c=0;
	for (int i = 1; i <= ar[0]; ++i) {
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
void Result(int * ar,int b,int a)
{
	for (int i = 1; i <b; ++i)
	{
		Multiply(ar, a);
	}
	Show(ar);
}
int main() {
	int max=100000;
	string a;
	int b;
	cin>>a>>b;
	int degree =a[0]-48;
	int * ar =Read(a,max);
	Result(ar,b,degree);
	return 0;
}
