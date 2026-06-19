//seqstack.cpp
//#include "stdafx.h"
#include <iostream>
using namespace std;
enum error_code {success,overflow,underflow,rangeerror};
typedef int elementtype ;
const int maxlen=15;
class stack{
public:
	stack();
	bool        empty()const;
	bool         full() const;
	error_code         get_top(elementtype &x)const;
	error_code         push(const elementtype x);
	error_code         pop();
private:
	int         count;
	elementtype       data[maxlen];
	//… …定义其它成员
};
stack::stack()        
{ count = 0; }

bool      stack::empty()const{
	if ( count == 0 )       return true;
	else          return false;
}
bool       stack::full()const{
	if ( count == maxlen ) return true;
	else return false; 
	//等价于：return count == maxlen;          
}
error_code stack::get_top(elementtype &x)const{
	if ( empty() ) return  underflow;
	else {
		x = data[count - 1];
		return success;}
}
error_code      stack::push(const elementtype x){
	if ( full() ) return  overflow;
	data[count] = x;
	count ++;
	return success;
}
error_code        stack::pop(){
	if ( empty() ) return underflow;
	count --;
	return success;
}
//十进制数N转换为其它d进制数
void Dec_to_Ocx(int N, int d)
       {  stack S;
           int Mod,x;
           while(N!=0)
            {  Mod=N%d;
                S.push(Mod);
                N=N/d;
             }
           while(!S.empty())
            { S.get_top(x);
               S.pop();
               cout<<x;
             }
		   cout<<endl;
         }

int main()
{/*stack s; elementtype x;
while (!s.full())
{cin>>x; s.push(x);
}
while (!s.empty()) 
{s.get_top(x);cout<<x<<"   ";s.pop();
}
cout<<endl;*/
 Dec_to_Ocx(1357,8);
 Dec_to_Ocx(1357,2); 
}

