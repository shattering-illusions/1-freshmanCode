#include<iostream>
#include<iomanip>
using namespace std;
void f() {
for(int i=6;i>=1;i--){
   for(int n=1;n<=7-i;n++)
   cout<<setw(4)<<" ";	
   for(int n=1;n<=i;n++)
   cout<<left<<setw(4)<<n;
cout<<endl;
}
}
int main() {
	f();
	return 0;
}
