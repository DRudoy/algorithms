#include <iostream>
#include <iomanip>
#include <locale>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
void maxSort(vector<long >& d);
void minSort(vector<long >& d);
string NumberToString ( long  Number )
  {
     ostringstream ss;
     ss << Number;
     return ss.str();
  }
long  StringToNumber ( string &Text )
{
     istringstream ss(Text);
     long result;
     return ss >> result ? result : 0;
}
long  digitMin(long  a)
{
	if(a<0)
	{
		a=a*(-1);
	}
	string k = NumberToString(a);
	vector<long > vec;
	for (int i = 0; i < k.length(); ++i) {
		vec.push_back(((int)k[i]-48));
	}
	minSort(vec);
	for (int i = vec.size()-2; i >= 0; --i) {
		if(vec[vec.size()-1]==0)
		{
			swap(vec[vec.size()-1],vec[i]);
		}
		else{
			break;
		}
	}
	string line="";
	for (int i = vec.size()-1; i >=0; --i) {
		line+=((char)(vec[i]+48));
	}
	return StringToNumber(line);
}
void minSort(vector<long >& d)
{
	for (int i = 0; i < d.size(); ++i) {
		for (int j = 0; j < d.size(); ++j) {
			if(d[i]>d[j])
			{
				swap(d[i],d[j]);
			}
		}
	}
}
int digitMax(long  a)
{
	if(a<0)
	{
		a=a*(-1);
	}
	string k = NumberToString(a);
	vector<long> vec;
	for (int i = 0; i < k.length(); ++i) {
		vec.push_back(((int)k[i]-48));
	}
	maxSort(vec);
	string line="";
	for (int i = vec.size()-1; i >= 0; --i) {
		line+=((char)(vec[i]+48));
	}
	return StringToNumber(line);

}
void maxSort(vector<long >& d)
{
	for (int i = 0; i < d.size(); ++i) {
		for (int j = 0; j < d.size(); ++j) {
			if(d[i]<d[j])
			{
				swap(d[i],d[j]);
			}
		}
	}
}
int Result(long  a ,long  b)
{

	if(a>=0 && b<=0)
	{

		a=digitMax(a);
		b=digitMax(b);
		return a+b;

	}
	if(a>=0 && b>=0)
	{
		a=digitMax(a);
		b=digitMin(b);
		return a-b;
	}
	if(a<=0 && b<=0)
	{
		a=digitMin(a);
		b=digitMax(b);
		return -a+b;
	}
	if(a<=0&&b>=0)
	{
		a=digitMin(a);
		b=digitMin(b);
		return -a-b;
	}
	return 0;
}
int main() {
	long a,b;
	cin>>a>>b;
	cout<<Result(a, b);
	return 0;
}

