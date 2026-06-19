#include<iostream>
using namespace std;
void js(int a[]);
int main()
{
	int a[100]={0};
	for(int i=0,zz;i<100;i++)
	{
		cin>>zz;
		if(zz!=0)
			a[i]=zz;
		else if(zz==0)
			break;
	}
	js(a); 
	return 0;
}
void js(int a[])
{
	int b[101]={0};
	for(int i=0;i<100;++i)
		if(a[i]!=0)
			b[a[i]]++;
	for(int i=1;i<101;i++)//occurs 1 time.
	{
		if(b[i]==1)
			cout<<i<<" "<<"occurs "<<b[i] <<" time.\n";
		else if(b[i]>1)
			cout<<i<<" "<<"occurs "<<b[i]<<" times.\n";
	}	
}
