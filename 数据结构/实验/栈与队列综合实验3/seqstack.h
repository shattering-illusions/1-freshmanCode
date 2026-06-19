#pragma once  //Õ»
#include <iostream>
#include <cstring>
#include"error_code1.h"
#include"maxlen.h"

using namespace std;
//enum error_code1 {success,overflow,underflow,rangeerror};
typedef char elementtype ;
//const int maxlen=99;
class stack
{
public:
	stack();
	bool empty()const;
	bool full() const;
	error_code1 get_top(elementtype& x)const
	{
		if (empty())
			return  underflow;
		else
		{
			x = data[count - 1];
			return success;
		}
	}
	error_code1 push(const elementtype x)
	{
		if (full())
			return  overflow;
		data[count] = x;
		count++;
		return success;
	}
	error_code1 pop();

	void input(int x)
	{
		elementtype mode;
		for (int i = 0; i < x; i++)
		{
			cin >> mode;
			push(mode);
		}
	}
	
private:
	int         count;
	elementtype       data[maxlen];
	
};
stack::stack()        
{ 
	count = 0;
}

bool      stack::empty()const
{
	if ( count == 0 )       
		return true;
	else          
		return false;
}
bool       stack::full()const
{
	if ( count == maxlen ) 
		return true;
	else 
		return false; 
	//µÈ¼ÛÓÚ£ºreturn count == maxlen;          
}
error_code1 stack::pop()
{
	if ( empty() ) 
		return underflow;
	count --;
	return success;
}

bool whetherMatch(char S[])
{
	stack s;
	int len = (int)strlen(S);
	for (int i = 0; i < len; i++)
	{
		if (S[i] == '[' || S[i] == '{' || S[i] == '(')
			s.push(S[i]);
		else if (S[i] == ']' || S[i] == '}' || S[i] == ')')
		{
			char mod;
			s.get_top(mod);
			if (mod != '[' && S[i] == ']')
				return false;
			if (mod != '(' && S[i] == ')')
				return false;
			if (mod != '{' && S[i] == '}')
				return false;
			s.pop();
		}
	}
	return s.empty();
}
