//============================================================================
// Name        : 2degreeN.cpp
// Author      : f
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <string>
#include <iostream>
using namespace std;
void Mul(int* ar,int digit);
void Show(int * ar)
{
	for (int i = ar[0]; i >=1; --i) {
		cout<<ar[i];
	}
}
int* Read(string count,int max)
{
	int * ar =new int [max];
	ar[0]=count.length();
	for (int i = 1; i <= ar[0]; ++i) {
		ar[ar[0]-i+1]=count[i-1]-48;
	}
	return ar;
}
void Multiply(int count,int * ar)
{
	for (int i = 1; i <=count; ++i) {
		Mul(ar,2);

	}
	Show(ar);
}
void Mul(int* ar,int digit)
{
	int c=0;
	for (int i = 1; i <=ar[0]; ++i)
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
int main() {
	int max=100000;
	int count;
	string k="1";
	cin>>count;
	int * ar= Read(k,max);
	Multiply(count,ar);
	delete [] ar;
	return 0;
}
