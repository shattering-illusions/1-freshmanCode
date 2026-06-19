#include<iostream>
using namespace std;
bool strictlyEqual(const int list1[ ], const int list2[ ], int size)
{
	int pd=0;
	for(int i=0;i<size;++i)
	{
		if(list1[i]!=list2[i])
		{
			pd+=1;
		}
	}
	return pd==0;
}
int main()
{
	int a1[20],a2[20];
	int li,lz;
	cin>>li;
	for(int i=0;i<li;++i)
		cin>>a1[i];
	cin>>lz;
	for(int i=0;i<lz;++i)
		cin>>a2[i];
	if(li!=lz)
		cout<<"非严格相同";
	else
		{
			if(strictlyEqual(a1,a2,li))
				cout<<"严格相同";
			else
				cout<<"非严格相同";
		}
	return 0;
}

