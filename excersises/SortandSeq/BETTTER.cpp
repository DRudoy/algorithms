//============================================================================
// Name        : BETTTER.cpp
// Author      : f
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <sstream>
using namespace std;
string NumberToString ( int Number )
  {
     std::ostringstream ss;
     ss << Number;
     return ss.str();
  }
int betterDivision(int count)
{
	int k=1;
	int check=count;
	int m=0;
	int res=0;
	while(check>0)
	{
		m+=check%10;
		check/=10;
	}
	int betterdigit=0;
	while(k<=count)
	{
		if(count%k==0)
		{
			int z=k;
			int sum=0;
			while(z>0)
			{
				sum+=z%10;
				z/=10;
			}
			if(sum>=m)
			{
				if(betterdigit<=sum)
				{
					if(sum==betterdigit)
					{
						if(NumberToString(sum).length()>=NumberToString(betterdigit).length())
						{
							k++;
							continue;
						}
						betterdigit=sum;
						res=k;
					}
					res=k;
					betterdigit=sum;
				}
			}
		}
		k++;
	}
	return res;
}
int main() {
	int count;
	cin>>count;
	cout<<betterDivision(count);
	return 0;
}
