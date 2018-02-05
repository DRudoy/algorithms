#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;
void quickSort(int *numbers,int array_size,int low,int height)
{
	int pivot = numbers[low + rand() % (height - low + 1)];
	int temp;
	int i = low;
	int j = height;
	while(true)
	{
		while(numbers[i] < pivot)
			i++;
		while(numbers[j] > pivot)
			j--;
		if(i <= j)
		{
			temp=numbers[i];
			numbers[i]=numbers[j];
			numbers[j]=temp;
			i++;
			j--;
		}
		if(i>j)
			break;
	}
	if(j > low)
		quickSort(numbers,array_size,low,j);
	if(height > i)
		quickSort(numbers,array_size,i,height);
}
void quickSort(int *numbers,int array_size)
{
   quickSort(numbers,array_size,0,(array_size-1));
}
int main()
{
    int *brr;
    int n;

    fstream fin;
    fin.open("input.txt",ios::in);
    if (fin.is_open())
	{
        fin >> n;
        brr = new int[n];
        for (int i = 0; i < n; i++)
            fin >> brr[i];

        fin.close();
    }
	quickSort(brr, n);
    fstream fout;
    fout.open("output.txt",ios::out);
    for (int i = 0; i < n; i++)
        fout << brr[i] << " ";

    fout.close();
    delete[] brr;
    return 0;
}
