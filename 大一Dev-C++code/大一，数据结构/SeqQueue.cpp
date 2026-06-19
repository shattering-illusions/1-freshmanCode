//SeqQueue.cpp
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
enum error_code1{success,overflow,underflow,rangeerror};
typedef int elementtype ;
const int maxlen=15;
class Queue{
public:
	Queue();
	bool        Empty()const;
	bool        Full()const;
	error_code1         Get_front(elementtype &x)const;
	error_code1         Append(const elementtype x);
	error_code1         Serve();
private:
	int         count,front,rear;
	elementtype       data[maxlen];	
};
Queue::Queue( )     
   { count = 0;  front = rear = 0; }

bool     Queue::Empty( ) const
{
    return front == rear; //return  count == 0;
}
bool    Queue::Full( ) const
{
    return ( rear + 1 ) % maxlen == front ; //return count == maxlen-1;
}
error_code1    Queue::Get_front(elementtype &x) const
{
        if ( Empty() )      return underflow;
        x = data[ (front + 1 ) % maxlen ];
        return success;
}
error_code1   Queue::Append(const elementtype x)
{
  if ( Full() )    return overflow;
  rear = ( rear + 1 ) % maxlen ;
  data[rear] = x;
  count ++;
  return   success;
}
error_code1   Queue::Serve( )
{
if ( Empty() )    return underflow;
front = ( front + 1 ) % maxlen;
count --;
return  success;
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
    while (!q.Full())
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
