#include <fstream>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <vector>
using namespace std;
void heapify(int * numbers, int array_size, int i);
void buildHeap(int * numbers, int array_size);
void heapSort(int * numbers, int array_size)
{
	buildHeap(numbers, array_size);
	array_size--;

	//Циклично заменяет 0 элемент с последним элементом массива,затем
	//уменьшает массив и поддерживает условие кучи
	while (array_size >= 0)
	{
		int temp = numbers[0];
		numbers[0] = numbers[array_size];
		numbers[array_size] = temp;
		heapify(numbers, array_size, 0);
		array_size--;
	}
}
void buildHeap(int * numbers, int array_size)
{
	for (int i =(array_size>>1) - 1; i >=0; i--)// array_size>>1 -это array_size/2, только работает быстрее
	{
		heapify(numbers, array_size, i);
	}
}
void heapify(int * numbers, int array_size, int i)
{
	int left = (i << 1) + 1; // i<<1 - это i*2 , только работает быстрее
	int right = left + 1;
	int largest;

	//Сравниваем левого ребенка и отца на наибольшее значение
	if (left < array_size && numbers[left] > numbers[i])
	{
		largest = left;
	}
	else
	{
		largest = i;
	}

	//Сравниваем правого ребенка с отцом или левый ребенком на наибольшее значение
	if (right < array_size && numbers[right] > numbers[largest])
	{
		largest = right;
	}

	//Если индекс наибольшего элемент не родитель,
	//то значение родителя меняется со значеним наибольшего элемента ребенка
	if (largest != i)
	{
		int temp = numbers[i];
		numbers[i] = numbers[largest];
		numbers[largest] = temp;
		heapify(numbers, array_size, largest);
	}
}

int main()
{
	int *brr;
	int n;

	fstream fin;
	fin.open("input.txt", ios::in);
	if (fin.is_open()) {
		fin >> n;
		brr = new int[n];
		for (int i = 0; i < n; i++)
		{
			fin >> brr[i];
		}

		fin.close();
	}
	heapSort(brr, n);
	fstream fout;
	fout.open("output.txt", ios::out);
	for (int i = 0; i < n; i++)
		fout << brr[i] << " ";

	fout.close();
	delete[] brr;
	return 0;
}
