#include<iostream>
#include<cstdlib>
#include<ctime>
#include<iomanip>
using namespace std;
void paixv(int a[],int l,int rm,int r)
{
	while(l<=rm-1&&rm<=r)
	{
		if(a[l]<=a[rm])
		l++;
		else
		{
			int temp=a[rm];
			for(int i=rm;i>=l&&i!=0;i--)
			a[i]=a[i-1];
			a[l]=temp;
			l++;
			rm++;
		}
	}
}
void caozuo(int a[],int l,int r)
{
	if(l==r)
	return;
	int mid=(l+r)/2;
	caozuo(a,l,mid);
	caozuo(a,mid+1,r);
	paixv(a,l,mid+1,r);
}
void statisyics(const int pdata[],int n,int result[])
{
	for(int i=0;i<n;i++)
	result[i]=pdata[i];
	double sum=0.0,zws,zs;
	for(int i=0;i<n;i++)
	{
		sum+=pdata[i];
	}
	double av=sum/n;
	caozuo(result,0,n-1);
	if(n%2==0)
	{
		zws=(result[n/2-1]+result[n/2])/2;
	}
	else
	{
		zws=result[(n-1)/2];
	}
	int mode=result[0],co=1,mco=1;
	for(int i=1;i<n;i++)
	{
		co = result[i]==result[i-1] ? co+1 : 1;
		if(co>mco)
		{
			mco=co;
			mode=result[i];
		}
		zs=mode;
	}
	cout<<"平均数为："<<av<<endl;
	cout<<"中位数为："<<zws<<endl;
	cout<<"众数为  ："<<zs;
}
int main()
{
	int a[100]={0};
	srand(time(0));
	for(int i=0;i<100;i++)
	a[i]=rand()%100;
	cout<<"无序数组为:\n";
	for(int i=0;i<100;i++)
	{
		cout<<left<<setw(4)<<a[i]<<" ";
		if((i+1)%10==0)
		cout<<"\n";
	}
	int result[100];
	statisyics(a,100,result);
	return 0;
}
