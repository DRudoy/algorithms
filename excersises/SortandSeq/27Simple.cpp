#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
#include <locale>
#include <sstream>
using namespace std;

string NumberToString ( int Number )
 {
    ostringstream ss;
    ss << Number;
    return ss.str();
 }
bool Simple(int a)
{
	string line;
	int i=2;
	int st=sqrt(a);
	while(st>=i)
	{
		if(a%i==0)
			return false;
		i++;
	}
	return true;
}
int Sort(int * ar,int count)
{
	int temp = -1;
	for (int i = 0; i < count; ++i) {
		if(ar[i]>temp)
			temp=ar[i];
	}
	return temp;
}
string Count(int* ar,int count)
{

	int indexSize=Sort(ar,count);
	string line="23";
	int j = 4;
	while(true)
	{
		if(Simple(j))
		{
			line+=NumberToString(j);
			if(line.size()>(indexSize+2))
				return line;
		}
		j++;
	}
	return line;
}

int main() {
	int count;
	cin>>count;
	int * ar =new int [count];
	for (int i = 0; i < count; ++i) {
		cin>>ar[i];
	}
	string k = Count(ar,count);
	for (int i = 0; i < count; ++i) {
		cout<<k[ar[i]-1];
	}
	return 0;
}

