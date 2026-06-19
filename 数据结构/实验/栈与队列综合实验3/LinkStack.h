#pragma once    //链栈
#include <iostream>
#include"error_code1.h"
#include<vector>
using namespace std;
//enum error_code1{success,overflow,underflow,rangeerror};
typedef int elementtype2 ;
struct node
{  
    elementtype2 data;     
    node *next;             
}; 
class Stack
{
public:
	Stack();
	~Stack();
	bool Empty()const;
	bool Full() const;
	error_code1 Get_top(elementtype1 &x)const;
	error_code1 Push(const elementtype1 x);
	error_code1  Pop();
    void clean();
    int length();
private:
	int count;
	node *top;
};
Stack::Stack( )
{ 
    count = 0; top = NULL; 
}
bool Stack::Empty( ) const
{ 
    return  top == NULL; //return  count == 0;
}  
bool Stack::Full() const
{ 
    return false; 
} 
error_code1 Stack::Get_top(elementtype1 &x) const
{
    if ( Empty() ) 
        return underflow;
    x = top->data;
    return success;
}
error_code1 Stack::Push(const elementtype1 x )
{   
    node *s;
    s = new node;  
    s -> data = x;   
    s -> next = top;     
    top = s;        
    count ++;                                   
    return success;                          
}
error_code1 Stack::Pop( )
{  
    node *u;
    if ( Empty() ) 
        return underflow;
    u = top;   top = top -> next;
    delete u;
    count --;
    return success;
}
Stack::~Stack( )
{ 
    while ( !Empty() )
        Pop( );
}

void Stack::clean()
{
    while (!Empty())
        Pop();

}
int Stack::length()
{
    return count;
}

Stack path;
int total = 0;         // 统计总数
void f(Stack& st, int n, int now)
{
    if (path.length() == n)//填满了就可能路径+1
    {
        total++;
        return;
    }

    if (!st.Empty())        //可以出栈就出栈
    {
        int top;
        st.Get_top(top);
        st.Pop();
        path.Push(top);
        f(st, n, now);  // 继续
        path.Pop();// 回溯
        st.Push(top);
    }
    
    if (now <= n)       //可以入栈就入栈
    {
        st.Push(now);
        f(st, n, now + 1);
        st.Pop();
    }
}
void findAll(int n)
{
    Stack st;
    path.clean();
    total = 0;
    f(st, n, 1);
    cout << endl << "总数：" << total << endl;
}