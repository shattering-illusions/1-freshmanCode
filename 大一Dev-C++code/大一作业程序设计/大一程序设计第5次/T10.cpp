#include<iostream>
#include<string> 
using namespace std;
void Turn(string i){ 
int n=i.length()-1;
for(;n>=0;n--){
char zzz=i.at(n);
cout<<zzz; 
}
}
int main() {
	string eg;
	getline(cin,eg);
    Turn(eg);
	return 0;
}
