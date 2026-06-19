#include<iostream>
using namespace std;
bool find(int a[],int num,int low,int high);
int main()
{
	cout<<"输入数组\n"; 
	int array[10];
	for(int i=0;i<10;i++)
		cin>>array[i];
	cout<<"输入要找的数."<<endl;
	int num;
	cin>>num;
	if(find(array,num,0,9))
		cout<<"Yes";
	else
		cout<<"No";
	return 0;
}
bool find(int a[],int num,int low,int high)
{
	int mid=low+(high-low)/2,pd=0;
	if(a[mid]==num)
		pd=1;
	else if(mid-1>=low||high>=mid+1)
	{
		if(find(a,num,low,mid-1)&&mid-1>=low)
			pd=1;
		if(find(a,num,mid+1,high)&&high>=mid+1)
			pd=1;
	}
	return pd;
}
