#include<iostream>
#include<cmath>
using namespace std;
int bin2Dec(int x)
{
	int sum=0;
	for(int n=0;x>=1;x/=10,n++)
	{
		sum+=pow(2,n)*(x%10);
	}
	return sum;
}
int main()
{
	int n;
	cin>>n;
	cout<<bin2Dec(n);
	return 0; 
} 
