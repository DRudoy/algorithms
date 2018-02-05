#include "ReadWriter.h"
#include "MergeSort.h"

using namespace std;

int main()
{
    ReadWriter rw;


    int length;

    //Read length from file
    length = rw.readInt();

    int* brr = new int[length];
    rw.readArray(brr, length);

    //Start sorting
    MergeSort s;

    s.sort(brr, length);

    //Write answer to file
    rw.writeArray(brr, length);

    delete[] brr;

    return 0;
}

void MergeSort::sort(int *arr, int length)
{
	divide_and_merge(arr, 0, (length-1));
}


void MergeSort::merge(int* arr, int first, int second, int end)
{

   int brr[end];
   int startA=first;
   int startB=second+1;
   for (int i = first; i <=end; ++i)
   {
	   brr[i]=arr[i];
   }
   for (int i = startA; i <=end; ++i)
   {
	   if((startA > second) || (startB > end))
	   {
		   if(startB > end)
		   {
			   arr[i] = brr[startA];
			   startA++;
		   }
		   else
		   {
			   arr[i] = brr[startB];
			   startB++;
		   }
	   }
	   else
	   {
		   if(brr[startA] <= brr[startB])
		   {
			   arr[i] = brr[startA];
			   startA++;
		   }
		   else
		   {
			   arr[i] = brr[startB];
			   startB++;
		   }
	   }

   }
}


void MergeSort::divide_and_merge(int *arr, int left, int right)
{
	int middle;
	if(left<right)
	{
		middle=(left+right)/2;
		divide_and_merge(arr, left, middle);
		divide_and_merge(arr, (middle+1), right);
		merge(arr,left,middle,right);
	}
}
