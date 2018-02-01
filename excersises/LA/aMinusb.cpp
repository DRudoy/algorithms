//============================================================================
// Name        : aMinusb.cpp
// Author      : f
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <string>
#include <iostream>
using namespace std;
void Minus(int * ar,int * br,bool k);
void Show(int * ar)
{
	int temp=ar[0];
	for (int i = temp; i >=1; --i)
	{
		cout<<ar[i];
	}
}
int* Read(string line,int max)
{
	int * ar =new int[max];
	ar[0]=line.length();
	for (int i = 1; i <=ar[0]; ++i)
	{
		ar[ar[0]-i+1]=line[i-1]-48;
	}
	return ar;
}
bool CompareArray(int * ar ,int * br)
{
	int countA = ar[0];
	int countB = br[0];
	if(countA>countB)
		return true;
	if(countB>countA)
		return false;
	for (int i = ar[0]; i >=1 ; --i) {
		if(ar[i]>br[i])
			return true;
		if(br[i]>ar[i])
			return false;
	}
	return true;
}
void Result(int* ar,int* br)
{
	bool k = CompareArray(ar,br);
	if(k)
		Minus(ar,br,k);
	else
		Minus(br,ar,k);
}
void Minus(int * ar,int * br,bool k)
{
	int c=0;
	for (int i = 1; i <= ar[0]; ++i) {
		c = c+ar[i]-br[i]+10;
		ar[i]=c%10;
		if(c<10)
			c=-1;
		else c=0;
	}
	while(ar[0]>1 &&ar[ar[0]]==0)
	{
			ar[0]=ar[0]-1;
	}
	if(k)
		Show(ar);
	else
	{
		cout<<"-";
		Show(ar);
	}
}
int main() {
	string a,b;
	int maxSize=10000;
	cin>>a>>b;
	int * ar=Read(a,maxSize);
	int * br=Read(b,maxSize);
	Result(ar,br);


	return 0;
}
