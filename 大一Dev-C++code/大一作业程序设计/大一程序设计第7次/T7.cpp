#include<iostream>
using namespace std;
bool isSorted(const int list[], int size)
{
	int pd=0;
	for(int i=1;i<size;++i)
		if(list[i]<list[i-1])
			pd++;
	return pd==0;
}
int main()
{
	 int n,a[80];
	cin>>n;
	for(int i=0;i<n;++i)
	{
		cin>>a[i];
	}
	if(isSorted(a,n))
		cout<<"ÒÑÅÅÐò";
	else
		cout<<"Î´ÅÅÐò";
	return 0;
}

