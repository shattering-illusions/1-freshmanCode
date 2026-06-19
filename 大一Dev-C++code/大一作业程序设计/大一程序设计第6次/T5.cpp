#include<iostream>
#include<cstdlib>
#include<ctime> 
using namespace std;
void printMatrix(int i)
{
	srand(time(0));
	for(int m=i;m>0;m--)
	{
		for(int n=i;n>0;n--)
		{
			cout<<rand()%2<<" ";
		}
		cout<<endl;
	} 
	
}
int main()
{
	int n;
	cin>>n;
	printMatrix(n) ;
	return 0;
}
