#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>
using namespace std;
int sum(vector<int> list,int& minIndex,int& maxIndex);
vector<int> split(string ar){
	vector<int> lists;
	string word="";
	for (int i = 0; i < ar.length(); ++i) {
		if(ar[i]==' ')
		{
			lists.push_back(atoi(word.c_str()));
			word="";
			continue;
		}
		word+=ar[i];
		if(i==ar.length()-1)
		{
			lists.push_back(atoi(word.c_str()));
			break;
		}
	}
	return lists;
}
int sum(vector<int> list,int &minIndex,int &maxIndex)
{
	int a=3*1000000 +1;
	int b=-3*1000000 -1;
	int sum=0;
	for (int i = 0; i < list.size(); ++i) {
		if(list[i]>0)
		sum+=list[i];
		if(list[i]<a)
		{
			a=list[i];
			minIndex=i;
		}
		if(list[i]>b)
		{
			b=list[i];
			maxIndex=i;
		}
	}
	return sum;
}
int multiply(vector<int> list,int min,int max)
{
	int mult=1;
	if(min>max)
	{
		int temp = max;
		max=min;
		min=temp;
	}
	for (int i = min+1; i < max; ++i) {
		mult*=list[i];
	}
	return mult;
}
int main() {
	int count;
	(cin>>count).get();
	string k;
	getline(cin,k);
	vector<int> lists=split(k);
	int min,max;
	int sums=sum(lists,min,max);
	int mult=multiply(lists, min, max);
	cout<<sums<<" "<<mult;

	return 0;
}
