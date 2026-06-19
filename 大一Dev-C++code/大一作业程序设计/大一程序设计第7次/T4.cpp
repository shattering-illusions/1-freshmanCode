#include<iostream>
#include<vector>
using namespace std;
int indexOfSmallestElement(int array[], int size)
{
	int m=0,araym=array[0];
	for(int i=1;i<size;i++)
	{
		if(array[i]<array[m])
		{
			m=i;
		}
	}
	return m;
}
int main()
{
	int array[10],size=10;
	for(int i=0;i<size;i++)
	{
		cin>>array[i];
	}
	cout<<indexOfSmallestElement(array,size);
	return 0;
}

