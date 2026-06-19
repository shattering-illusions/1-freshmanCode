#include<iostream>
using namespace std;
void px(int a[]);
int main()
{
	int array[10];
	for(int i=0;i<10;i++)
		cin>>array[i];
	px(array);
	for(int i=0;i<10;i++)
		cout<<array[i]<<" ";
	return 0;
}
void px(int a[])
{
	for(int i=1;i<10;i++)
	{
		int j=i-1;
		int key= a[i];
		while(a[j]>key&&j>=0)
		{
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=key;
	}
}
