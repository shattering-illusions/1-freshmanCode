#include<iostream>
using namespace std;
bool isfriend(int i1,int i2)
{
	int sum1=0,sum2=0;
	for(int i=1;i<=i1/2;i++)
	{
		if(i1%i==0)
		{
			sum1+=i;
		}	
	}
	for(int i=1;i<=i2/2;i++)
	{
		if(i2%i==0)
		{
			sum2+=i;
		}	
	}
	return sum1==i2&&sum2==i1;
}
int main()
{
	int i,z;
	cin>>i>>z;
	if(isfriend(i,z))
	cout<<i<<" and "<<z<<"是友好数。";
	else
	cout<<i<<" and "<<z<<"不是友好数。";
  return 0;
}
