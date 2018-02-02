//============================================================================
// Name        : SumFactorial.cpp
// Author      : f
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <string>
#include <iostream>
void Sum(int * ar ,int * br);
using namespace std;

void Show(int * ar)
{
	for (int i = ar[0]; i >=1; --i) {
		cout<<ar[i];
	}
}
int* Read(string a, int max)
{
	int * ar= new int [max];
	ar[0]=a.length();
	for (int i = 1; i <= ar[0]; ++i)
	{
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
		c/=10;
	}
}
void Sum(int * ar ,int * br)
{
	int c=0;
	if(ar[0]<br[0])
	 ar[0]=br[0];

	for (int i = 1; i <= ar[0]; ++i)
	{
	   ar[i]=ar[i]+br[i] +c;
	   c=ar[i]/10;
	   ar[i]=ar[i]%10;
	}
	if(c>0)
	{
		ar[0]=ar[0]+1;
		ar[ar[0]]=c;
	}

}
void SumFactorial(int * ar,int * br,int count)
{
	for (int i = 1; i <=count; ++i) {
		Multiply(ar, i);
		Sum(br, ar);
	}
	Show(br);
}
int main() {

	int a;
	int max=10000;
	cin>>a;
	int * ar =Read("1",max);
	int * sum = Read("0",max);
	SumFactorial(ar, sum, a);
	delete[] ar;
	delete[] sum;
	return 0;
}
