#include <iostream>
using namespace std;
int CoutRow(int firstword,int secondword);
int CoutCeow(int firstword,int secondword);
int main() {
	int firstword,secondword;
	cin>>firstword>>secondword;
	cout<< CoutCeow(firstword,secondword)<<" "<<CoutRow(firstword,secondword);
	return 0;
}
int CoutRow(int firstword,int secondword)
{
	int count=0;
	int twoword=secondword;
	for(int i=0 ; i<4;i++)
	{
		int endfirst= firstword%10;
		firstword/=10;
		secondword=twoword;
		for(int j=0;j<4;j++)
		{
			int endsecondword=secondword%10;
			secondword/=10;
			if(i==j)
				continue;
			if(endsecondword==endfirst)
			{
				count++;
			}
		}
	}
	return count;
}
int CoutCeow(int firstword,int secondword)
{
	int count=0;
	for(int i =0 ; i <4;i++)
	{
		int endfirst= firstword%10;
		firstword/=10;
		int endsecondword=secondword%10;
		secondword/=10;
		if(endfirst==endsecondword)
		{
			count++;
		}

	}
	return count;
}
