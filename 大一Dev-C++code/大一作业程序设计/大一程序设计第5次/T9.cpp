#include<iostream>
#include<string> 
using namespace std;
int dxzm(string i){
int n=(i.length()-1),sum=0;
for(;n>=0;n--){
char Wa=i.at(n);
if(int(Wa)>=65&&int(Wa)<=90)
sum++;
}
return sum;	
}
int main() {
	string eg;
	getline(cin,eg);
    cout<<dxzm(eg);
	return 0;
}
