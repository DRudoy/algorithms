#include <iostream>
#include <sstream>

using namespace std;
string NumberToString ( int number )
  {
     std::ostringstream ss;
     ss << number;
     return ss.str();
  }
void ShowArray(int* ar)
{

	int l=0;
	for (int i = ar[0]; i>=1; --i) {
		if(ar[i]!=(int)'0'-48)
		{
			l=1;
			break;
		}

	}
	if(l==0)
	{
		cout<<"0";
		return;
	}
	for (int i = ar[0]; i>=1; --i) {

		cout<<ar[i];


	}
}
int* Readdigit(string a,int maxSize)
{
	int * ar =new int[maxSize];

	ar[0]=a.length();
	for (int i = 1; i <=ar[0]; ++i)
	{
		ar[ar[0]-i+1]=(int)a[i-1]-48;
	}
//  4 1 2 3 4
	return ar;
}

void multiplt(int * ar , int b)
{
	int c=0;
	for (int i = 1; i <= ar[0]; ++i) {
		ar[i]=ar[i]*b+c;
		c=ar[i]/10;
		ar[i]=ar[i]%10;
	}
	while(c>0)
	{
		ar[0]=ar[0]+1;
		ar[ar[0]]=c%10;
		c=c/10;
	}
	ShowArray(ar);
}
int main() {
	string a;
      int b;
	cin>>a>>b;
	int maxSize=100000;
	int * ar = Readdigit(a, maxSize);
	multiplt(ar,b);
	delete[] ar;
	return 0;
}
