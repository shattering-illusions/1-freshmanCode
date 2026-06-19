#include<iostream>
using namespace std;
int main()
{
	int size;
	cin>>size;
	int arr[size];
	for(int i=0;i<size;i++)
		cin>>arr[i];
	int *p[size];
	int n=1;
	p[0] = new int[n];
	p[0][0]=arr[0];
	for(int i=1;i<6;i++)
	{
		int pd=0;
		for(int z=0;z<i;z++)
		{
			if(arr[z]==arr[i])
				pd++;
		}
		if(pd==0)
		{
			n++;
			p[n-1]=new int[n];
			p[n-1][n-1]=arr[i];
			for(int z=0;z<n-1;z++)
				p[n-1][z]=p[n-2][z];
			delete []p[n-2];
		}
	}
	for(int i=0;i<n;i++)
		cout<<p[n-1][i]<<" ";
	delete[]p[n-1];
	return 0;
}
