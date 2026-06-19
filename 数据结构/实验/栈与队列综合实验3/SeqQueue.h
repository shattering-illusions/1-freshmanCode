#pragma once

#include <iostream>
#include <iomanip>      
#include"error_code1.h"
#include"maxlen.h"

using namespace std;
//enum error_code1{success,overflow,underflow,rangeerror};
typedef int elementtype1;
//const int maxlen=99;

class Queue
{
public:
	Queue();
	bool Empty()const;
	bool Full()const;
	error_code1 Get_front(elementtype1 &x)const;
	error_code1 Append(const elementtype1 x);
	error_code1 Serve();

    int getLen()
    {
        return count;
    }
private:
	int count,front,rear;
	elementtype1 data[maxlen];	
};
Queue::Queue()     
{ 
    count = 0;  
    front = rear = 0; 
}

bool Queue::Empty( ) const
{
    return front == rear; //return  count == 0;
}
bool Queue::Full( ) const
{
    return (rear + 1) % maxlen == front; //return count == maxlen-1;
}
error_code1 Queue::Get_front(elementtype1 &x) const
{
        if ( Empty() )      
            return underflow;
        x = data[(front + 1) % maxlen];
        return success;
}
error_code1 Queue::Append(const elementtype1 x)
{
  if ( Full() )    
      return overflow;
  rear = (rear + 1) % maxlen;
  data[rear] = x;
  count ++;
  return   success;
}
error_code1   Queue::Serve( )
{
    if ( Empty() )    
        return underflow;
    front = ( front + 1 ) % maxlen;
    count --;
    return  success;
}
void josephus(int n, int k, int m)
{
    Queue q;
    for (int i = 1; i <= n; i++)//把 1~n 编号入队
    {
        q.Append(i);
    }

    int mod = 0;
    while (q.getLen() > m && !q.Empty())//人数超过m，且表不空
    {
        elementtype1 x;
        q.Get_front(x); //保存队头
        q.Serve();      
        mod++;          // 报数 +1
        if (mod == k)   // k淘汰
        {
            mod = 0;        // 重新从 1 开始报数
        }
        else            //不淘汰就重新入队
        {
            q.Append(x);
        }
    }

    while (!q.Empty())  //输出最后剩下的人
    {
        elementtype1 x;
        q.Get_front(x);
        q.Serve();
        cout << x << " ";
    }
    cout << endl;
}
