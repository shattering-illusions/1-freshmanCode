#include<iostream> 

using namespace std;
double js(int i) {
	double n,sum=0; 
	for(;i!=0;i--) 
	{n=(2.0*i-1)/(2.0*i+1);
	sum+=n;
	}
	return sum;	
}

int main()
{int i=49;
cout<<js(i);
return 0; 
}
	
