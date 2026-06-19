#include<iostream>
using namespace std;
void displaySortedNumbers(double n1,  double n2, double n3)
{
	if(n1>n2)
	swap(n1,n2); 
	if(n2>n3)
	swap(n2,n3);
	if(n1>n2)
	swap(n1,n2);
	cout<<n1<<" "<<n2<<" "<<n3;
}
int main()
{
	int n1,n2,n3;
	cin>>n1>>n2>>n3;
	displaySortedNumbers(n1,n2,n3);
	return 0;
}
