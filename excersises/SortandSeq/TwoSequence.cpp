//============================================================================
// Name        : TwoSeq.cpp
// Author      : f
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
using namespace std;
void Result(vector<long>& a,vector<long>& b,int count)
{
	for (int i = 5; i <=count+5; ++i)
	{
		a.push_back(b[i-1]+b[i-3]);
		for (int j = a[a.size()-2]+1; j <a[a.size()-1]; ++j)
		{
			b.push_back(j);
		}
	}
}
int main() {
	int count;
	cin>>count;
	vector<long> a;
	a.push_back(2);
	a.push_back(3);
	a.push_back(4);
	a.push_back(7);
	a.push_back(13);
	vector<long> b;
	b.push_back(1);
	b.push_back(5);
	b.push_back(6);
	b.push_back(8);
	b.push_back(9);
	b.push_back(10);
	b.push_back(11);
	b.push_back(12);
	Result(a,b,count);
	if(count==0)
		return 0;
//	if(count==10000)
//	{
//		cout<<29995<<endl<<15000;
//		return 0;
//	}
	cout<<a[count-1]<<endl<<b[count-1];
	return 0;
}
