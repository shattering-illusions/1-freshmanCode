#include<iostream>
using namespace std;
void xianshi(int a1[],int a2[])
{
	int pd[10],pd1=0;
	for(int i=0;i<10;++i)
	{
		for(int z=0;z<10;++z)
		{
			int pd2=0;
			for(int k=0;k<pd1;k++)
				if(pd[k]==a1[i])
					pd2++;
			if(a1[i]==a2[z]&&pd2==0)
			{
			pd[pd1++]=a1[i];
			}	
		}
	}
	for(int i=0;i<pd1;++i)
		cout<<pd[i]<<" ";
}
int main()
{
	int a1[10],a2[10];
	for(int i=0;i<10;++i)
		cin>>a1[i];
	for(int i=0;i<10;++i)
		cin>>a2[i];
	xianshi(a1,a2);
	return 0;
}

