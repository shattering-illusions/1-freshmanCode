#include<iostream>
using namespace std;
void f() 
{
for(int i=1,m,n,z=0;z==0;i++)
	{
	m=i*10+8;
	for(int zzz=10,pd=0;pd==0;zzz*=10)
	{
		if(i<zzz)
		{
			pd++;
			n=8*zzz+i;
		}
	}
	if(n==m*4)
	{
		cout<<m<<"·ûºÏÌõ¼þ";
		z++;
	}
	else 
 		continue;
	
}	
}
int main() {
	f();
	return 0;
}

