//============================================================================
// Name        : Floid.cpp
// Author      : f
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

void Show(int ** arr,int x)
{
	for (int i = 0; i < x; ++i) {
		for (int j = 0; j < x; ++j) {
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}
}
bool min(int a,int b)
{
	if(a<b)
		return true;
	else
		return false;
}
void Floid(int ** arr ,int x)
{

	for (int k = 0; k < x; ++k) {
		for (int i = 0; i < x; ++i) {
			for (int j = 0; j < x; ++j) {
				if(min(arr[i][k]+arr[k][j],arr[i][j]))
				{
					if(arr[i][k]+arr[k][j]>=10000)
						break;
					arr[i][j]=arr[i][k]+arr[k][j];
				}

			}
		}
	}
}
int FindMax(int ** arr ,int x)
{
	int max=-1;
	for (int i = 0; i < x; ++i) {
		for (int j = 0; j < x; ++j) {
			if(arr[i][j]>max&& arr[i][j]<=10000)
			max=arr[i][j];
		}

	}
	return max;
}
int main() {
	int x;
	cin>>x;
	int ** arr =new int * [x];
	for (int i = 0; i < x; ++i) {
		arr[i] =new int[x];
		for (int j = 0; j < x; ++j) {
			cin>>arr[i][j];
			if(arr[i][j]== -1)
				arr[i][j]=10001;
		}
	}
	Floid(arr,x);
	cout<<FindMax(arr, x);
	for (int i = 0; i < x; ++i) {
			delete[] arr[i];
	}
	delete [] arr;
	return 0;
}
