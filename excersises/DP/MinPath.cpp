#include <iostream>
using namespace std;

void Show(int ** ar,int countX,int countY)
{
	for (int i = 0; i <countX ; ++i) {
		for (int j = 0; j < countY; ++j) {
			cout<<ar[i][j]<<" ";
		}
		cout<<endl;
	}
}
void Function(int ** ar,int countX,int countY)
{

	for (int j = 1; j < countY; ++j) {
		ar[0][j]=ar[0][j]+ar[0][j-1];

	}
	for (int i = 1; i < countX; ++i) {
		ar[i][0]=ar[i][0]+ar[i-1][0];
	}
}
void Podschet(int ** ar,int x,int y)
{
	int min;
	if(ar[x][y-1]>ar[x-1][y])
		min=ar[x-1][y];
	else
		min=ar[x][y-1];
	ar[x][y]=ar[x][y]+min;
}
int main() {
	int countX;
	cin >> countX;
	int countY;
	cin>>countY;
	int ** ar =new int * [countX];
	for (int i = 0; i < countX; ++i) {
		ar[i]=new int [countY];
	for (int j = 0; j < countY; ++j) {
		cin>>ar[i][j];
	}
	}
	Function(ar,countX,countY);

	for (int k = 1; k < countX; ++k) {
		for (int j = 1; j < countY; ++j) {
			Podschet(ar, k, j);
		}
	}
	cout<<ar[countX-1][countY-1];
	for (int i  = 0; i < countX; ++i) {
		delete[] ar[i];

	}
}
