//LinkStack.cpp
#include <iostream>
using namespace std;
enum error_code1{success,overflow,underflow,rangeerror};
typedef int elementtype ;
struct node
 {  elementtype data;     
    node *next;             
 }; 
class Stack{
public:
	Stack();
	~Stack();
	bool        Empty()const;
	bool        Full() const;
	error_code1         Get_top(elementtype &x)const;
	error_code1         Push(const elementtype x);
	error_code1         Pop();
private:
	int         count;
	node *top;
};
Stack::Stack( )
   { count = 0; top = NULL; }
bool    Stack::Empty( ) const
{ return  top == NULL;  //return  count == 0;
}  
bool    Stack::Full( ) const
{ return false; } 
error_code1    Stack::Get_top(elementtype &x) const
{
    if ( Empty() ) return underflow;
    x = top->data;
    return success;
}
error_code1 Stack::Push(const elementtype x )
{   node *s;
    s = new node;   s -> data = x;   
    s -> next = top;     top = s;        
    count ++;                                   
    return success;                          
}
error_code1 Stack::Pop( )
{   node *u;
    if ( Empty() ) return underflow;
    u = top;   top = top -> next;
    delete u;
    count --;
    return success;
}
Stack::~Stack( )
{ 
    while ( !Empty() )  Pop( );
}
void Dec_to_Ocx(int N, int d)
{  
    Stack S;
    int Mod,x;
    while(N!=0)
    {   Mod=N%d;
        S.Push(Mod);
        N=N/d;
    }
    while(!S.Empty())
    {   S.Get_top(x);
        S.Pop();
        cout<<x;
    }
	cout<<endl;
}
int main()
{
    /*
	Stack s; elementtype x; int i;
    for (i=0;i<5;i++)
    {    cin>>x;  s.Push(x);
    }
    while (!s.Empty()) 
    {    s.Get_top(x);  cout<<x<<"   ";  s.Pop();
    }
    cout<<endl;
	*/
    Dec_to_Ocx(1357,8);
    Dec_to_Ocx(1357,2); 
}  

