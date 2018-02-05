#include "Solver.h"
using namespace std;
void change(Student* students, Ski* skis,int low,int height)
{
	Student pivot=students[low];
	Student temp;
	Ski tempSki;
	int i=low;
	int j=height;
	while(true)
	{
		while(students[i].id < pivot.id)
			i++;
		while(students[j].id > pivot.id)
			j--;
		if(i<=j)
		{
			//swap
			temp=students[i];
			students[i]=students[j];
			students[j]=temp;

			//swap
			tempSki=skis[i];
			skis[i]=skis[j];
			skis[j]=tempSki;
			i++;
			j--;
		}
		if(i>j)
			break;
	}

	if(low<j)
		change(students, skis, low, j);
	if(i<height)
		change(students, skis, i, height);

}
void quickSortForStudent(Student * students,Ski* skis,int low,int height)
{
	Student pivotStudent;
	Ski pivotSkies = skis[low];
	for (int m = low; m <= height; ++m)
	{
		if(compare(students[m], pivotSkies)==0)
		{
			pivotStudent=students[m];
			swap(students[m],students[low]);
			break;
		}
	}
	int i = low+1;
	int j = height;
	while(true)
	{
		while(compare(pivotStudent,skis[i])==-1)
		{
			if(i <= height)
				i++;
			else
				break;
		}

		while(compare(pivotStudent,skis[j])==1)
		{
			if(j >= (low+1))
				j--;
			else
				break;
		}
		if(i <= j)
		{
			swap(skis[i],skis[j]);
			i++;
			j--;
		}
		if(i>j)
			break;
	}
	swap(skis[low],skis[j]);
	i =low+1;
	j = height;
	while(true)
	{
		while(compare(students[i],pivotSkies)==1)
		{
			if(i<=height)
				i++;
			else
				break;
		}

		while(compare(students[j],pivotSkies)==-1)
		{
			if(j>=(low+1))
				j--;
			else
				break;
		}
		if(i <= j)
		{
			swap(students[i],students[j]);
			i++;
			j--;
		}
		if(i>j)
			break;
	}
	swap(students[low],students[j]);
	if(low<j)
		quickSortForStudent(students, skis, low, j);
	if(height>i)
		quickSortForStudent(students, skis, i, height);
}
int main()
{
    ReadWriter rw;

    int n;

    //Read n from file
    n = rw.readInt();

    //Create arrays
    Student* students = new Student[n];
    Ski* skis = new Ski[n];

    //read Students and Skis from file
    rw.readStudents(students, n);
    rw.readSkis(skis, n);

    //Find pairs
    Solver s;
    s.findPairs(students, skis, n);

    //Write answer to file
    rw.writeStudentsAndSkis(students, skis, n);

    delete[] students;
    delete[] skis;
    return 0;
}
void Solver::findPairs(Student* students, Ski* skis, int n)
{
	quickSortForStudent(students, skis, 0, n-1);
	change(students, skis,0,n-1);
}
