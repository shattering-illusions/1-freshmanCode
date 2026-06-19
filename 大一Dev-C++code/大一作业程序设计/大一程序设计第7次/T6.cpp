#include<iostream>
using namespace std;
bool isConsecutiveFour(const int values[ ], int size)
{
	int mode=values[0],pd=0;
	for(int i=0;i<size;++i)
	{
		if(values[i]==mode)
		{
			if(pd<4)
				pd++;
			else if(pd>=4)
				break;
		}
		else if(values[i]!=mode)
		{
			if(pd<4)
				{
					pd=1;
					mode=values[i]; 
				}	
			else if(pd=4)
				break;	
		}
	} 
	return pd==4;
}
int main()
{
	int size,a[80];
	cin>>size;
	for(int i=0;i<size;++i)
	{
		cin>>a[i];
	}
	if(isConsecutiveFour(a,size))
		cout<<"сп";
	else
		cout<<"нч"; 
	return 0;
}

