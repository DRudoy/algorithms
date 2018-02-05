//============================================================================
// Name        : amodB.cpp
// Author      : f
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <string>
#include <iostream>
using namespace std;
int * Read(string k ,int max)
{
	int * ar =new int [max];
	ar[0]=k.length();
	for (int i = 1; i <=ar[0]; ++i) {
		ar[ar[0]-i+1] = k[i-1]-48;
	}
	return ar;
}
void Mod(int * ar ,long long b)
{
	long long x=0;
	for (int i = ar[0]; i >=1; --i)
	{
		x=(x*10+ar[i])%b;
	}
	cout << x;
}
int main() {
	string a;
	cin>>a;
	long long b;
	cin>>b;
	int * ar = Read(a, 100000);
	Mod(ar,b);
	delete[] ar;
	return 0;
}
