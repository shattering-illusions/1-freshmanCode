#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int a[10];
	for(int i=0,x;i<10;++i)
	{
		cin>>x;
		a[i]=x;
	}
	vector<int> b;
	for(int i=0;i<10;++i)
	{
		int pd =0;
		for(int js=0,len=b.size();js<len;js++)
		{
			if(a[i]==b[js])
			{
				pd++;
				break;
			}
		}
		if(pd==0)
			b.push_back(a[i]);
	}
	for(int i=0,len=b.size();i<len;i++)
	{
		cout<<b[i]<<" ";
	}
	return 0;
}

