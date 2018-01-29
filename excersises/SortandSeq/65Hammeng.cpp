#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>

using namespace std;
vector<string> split(string ar){
	vector<string> lists;
	string word="";
	for (int i = 0; i < ar.length(); ++i) {
		if(ar[i]==' ')
		{
			lists.push_back(word);
			word="";
			continue;
		}
		word+=ar[i];
		if(i==ar.length()-1)
		{
			lists.push_back(word);
			break;
		}
	}
	return lists;
}
vector<int> Hammeng(string current, vector<string> lists){
	int countMistake=0;
	int min=0;
	string index="";
	vector<int> str;

	for (int i = 0; i < lists.size(); ++i) {
		countMistake=0;
		for (int j = 0; j < current.length(); ++j) {
			if(current[j]!=lists[i][j])
			{
				countMistake++;
			}
			if(j==current.length()-1)
			{
				if(min>countMistake)
				{
					str.clear();
					min=countMistake;
					str.push_back(i+1);
					break;
				}
				if(min==countMistake)
				{
					str.push_back(i+1);
					break;
				}
				if(i==0)
				{
					min=countMistake;

					str.push_back(i+1);
				}
			}
		}
	}
	return str;
}
void show(vector<int> k )
{
	for (int i = 0; i < k.size(); ++i) {
			cout<<k[i]<<"  ";
	}
}
int main() {
	int count;
	string value;
		(cin>>value>>count).get();
		string k;
		int i=0;
		vector<string> array;
		while(i<count)
		{
			getline(cin,k);
			array.push_back(k);
			i++;
		}
		vector<int> res=Hammeng(value, array);
		cout<<res.size()<<endl;
		show(res);


	return 0;
}
