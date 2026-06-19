#include<iostream>
using namespace std;
int sumDigits(int n)
{   int sum=0;
	for(;n>0;n/=10)
	{
		sum+=n%10;
	}
	return sum;
}
int main()
{
	int n;
	cin>>n;
	cout<<sumDigits(n);
	return 0;
}
