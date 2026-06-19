#include<iostream>
#include<string> 
using namespace std;
void f(string x){ 
int n=x.length()-1,yy=0,fy=0;
for(;n>=0;n--){
char zzz=x.at(n);
int i=int(zzz);
if(i==65||i==69||i==73||i==79||i==85||i==97||i==99||i==105||i==111||i==117) 
yy++;
else if((i>=65&&i<=90||i>=97&&i<=122)&&(i!=65||i!=69||i!=73||i!=79||i!=85||i!=97||i!=99||i!=105||i!=111||i!=117))
fy++;
}
cout<<"元音个数"<<yy<<endl<<"辅音个数"<<fy;
}
int main() {
	string x;
	getline(cin,x);
    f(x);
	return 0;
}
