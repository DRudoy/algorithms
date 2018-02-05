//============================================================================
// Name        : AdevisionB.cpp
// Author      : f
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <string>
#include <iostream>
using namespace std;
int* ReadLine(string ar,int max)
{
	int * arr = new int[max];
	arr[0]=ar.length();
	for (int i = 1; i <=arr[0]; ++i)
	{
		arr[arr[0]-i+1]=ar[i-1]-48;
	}
	return arr;

}
void Division(int * ar ,int b)//100 10
{
	int k=0,x=0;
	for (int i =ar[0]; i >=1; --i) {
		x=x*10+ar[i];
		if(k!=1&& x<b && i >1)
		{
			continue;
		}
		k=1;
		cout<<x/b;
		x=x%b;
	}
}
int main()
{
	string ar;
	cin>>ar;
	int b;
	cin>>b;
	int max=100000;
	int * arr=ReadLine(ar, max);
	Division(arr, b);
	return 0;
}
