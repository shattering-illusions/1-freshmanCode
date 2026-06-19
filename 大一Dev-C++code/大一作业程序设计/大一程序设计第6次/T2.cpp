#include<iostream>
using namespace std;
void reverse(int nb)
{
	int bnb=0; 
	for(;nb>0;nb/=10)
	bnb=bnb*10+nb%10;			
    cout<<bnb;  
}
int main()
{
	int n;
	cin>>n;
	reverse(n);
	return 0;
}
