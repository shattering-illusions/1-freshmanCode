#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	int sj[10][10];
	for(int i=0;i<10;i++)
	{
		sj[i][0]=1;
		sj[i][i]=1;
	}	
	for(int i = 1;i<10;i++)
	{
		for(int z=1;z<i;z++)
		{
				sj[i][z]=sj[i-1][z]+sj[i-1][z-1];	
		}
	}
	for(int i=0;i<10;i++)
	{
		for(int m=i;m<10;m++)
		{
			cout<<"  ";
		}
		for(int z=0;z<=i;z++)
		{
			cout<<setw(4)<<sj[i][z];
		}
		cout<<endl;
	}
	return 0;
}
