//LinkQueue.cpp
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
enum error_code1{success,overflow,underflow,rangeerror};
typedef int elementtype;
struct node
 {  elementtype data;     
    node *next;             
 }; 
class Queue{
public:
	Queue();
	~Queue();
	bool        Empty()const;
	bool        Full()const;
	error_code1         Get_front(elementtype &x)const;
	error_code1         Append(const elementtype x);
	error_code1         Serve();
private:
	int  count;
	node *front,*rear;	
}; 
Queue::Queue()
{ 
    front = new node;          
    rear = front;                  
    front->next = NULL; 
    count = 0;
}        
bool    Queue::Empty( ) const
{   return front == rear;        
    //return front->next == NULL;
    //return  count == 0; 
}
bool    Queue::Full() const 
{ return false; } 
error_code1     Queue::Get_front(elementtype &x) const
{   if ( Empty() ) return underflow;
    x = front -> next -> data;
    return success;
}
error_code1     Queue::Append(const elementtype x )
{   node *s;
    s = new node; 
    s -> data = x; 
    s -> next = NULL;
    rear -> next = s;
    rear = s;
    count ++;
    return success;
}
error_code1     Queue::Serve()
{   node *u;
    if ( Empty() )    return underflow;
    u = front -> next;
    front -> next = u -> next;
    delete u;
    count --;
    if ( front -> next == NULL ) rear = front;
    return success;
}
Queue::~Queue()
{
    while ( !Empty() ) Serve();
    delete front;       
}
void  Out_Number(int n)                                 
{  int s1, s2;  Queue Q;  int N = n-1;                                     
   error_code1 Ec;  cout<<string(N,' ');                                             
   cout<<setw(2)<<1<<endl;                                             
   Ec=Q.Append(1);                                          
     for(int i = 2; i<= n; i++ )                              
      {  s1 =0;   N--; cout<<string(N,' ');                                                     
         for(int j = 1; j <= i-1; j++ )                     
         {  Ec= Q.Get_front(s2);  Ec=Q.Serve( ); 
             cout<<setw(2)<< s1 + s2<<" ";                                       
             Ec=Q.Append(s1 + s2);                        
             s1 = s2;                                                  
          }
        cout<<setw(2)<<1<<endl;                                       
        Ec=Q.Append(1);                                     
     }
}
int main()
{
    /*
	Queue q; elementtype x;
    for (int i=0;i<5;i++)
    {   cin>>x; q.Append(x);
    }
    while (!q.Empty()) 
    {   q.Get_front(x); cout<<x<<"   "; q.Serve();
    }
    cout<<endl;
	*/
    Out_Number(8); 
    return 0;
}


      
