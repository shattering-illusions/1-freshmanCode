#pragma once

#include<iostream>

using namespace std;

enum error_code1 { success, overflow, underflow, rangeerror };
typedef int elementtype;

struct node
{
    elementtype data;
    node* next;
};

class Queue
{
public:
    Queue();
    ~Queue();
    bool Empty()const;
    
    error_code1 Get_front(elementtype& x)const;
    error_code1 Append(const elementtype x);
    error_code1 Serve();

    void input(int x);
    void display() const;
    void split(Queue& S1, Queue& S2);
    void getTheSame(Queue& S1, Queue& S2);
    void deleteTheSame();
    void mergeUnique(Queue& L2);
    int findLastKNode(int k);
private:
    int  count;
    node* front, * rear;
};

Queue::Queue()
{
    front = new node;
    rear = front;
    front->next = NULL;
    count = 0;
}

bool    Queue::Empty() const
{
    return front == rear;
}


error_code1 Queue::Get_front(elementtype& x) const
{
    if (Empty()) 
        return underflow;
    x = front->next->data;
    return success;
}
error_code1 Queue::Append(const elementtype x)
{
    node* s;
    s = new node;
    s->data = x;
    s->next = NULL;
    rear->next = s;
    rear = s;
    count++;
    return success;
}
error_code1 Queue::Serve()
{
    if (Empty())    
        return underflow;
    node* u;
    u = front->next;
    front->next = u->next;
    delete u;
    count--;
    if (front->next == NULL) 
        rear = front;
    return success;
}
 
Queue::~Queue()
{
    while (!Empty()) 
        Serve();
    delete front;
}

void Queue::input(int x)
{
    elementtype p;
    for (int i = 0; i < x; i++)
    {
        cin >> p;
        Append(p);
    }
}

void Queue::display() const  //打印队列
{
    cout << endl;
    if (Empty())
        cout << "NULL" ;
    node* p = front->next;
    while (p != NULL)
    {
        cout << p->data<<" ";
        p = p->next;
    }
    cout << endl;
}
void Queue::split(Queue& S1, Queue& S2)     //T1- 分离奇偶
{
    node* p = front->next;
    while (p != NULL)
    {
        if (p->data % 2 == 0)
        {
            S2.Append(p->data);
        }
        else if (p->data % 2 != 0)
        {
            S1.Append(p->data);
        }
        p = p->next;
    }
}
void Queue::getTheSame(Queue& S1, Queue& S2)        //T2-找相同元素，并存储到新表中
{
    node* p = front->next; 
    node* q = S1.front->next; 

    while (p != NULL && q != NULL) 
    {
        if (p->data == q->data) 
        {
            S2.Append(p->data);
            p = p->next;  
            q = q->next;
        }
        else if (p->data < q->data) 
        {
            p = p->next;
        }
        else 
        {
            q = q->next;
        }
    }
}


void Queue::deleteTheSame()
{
    if (Empty() || front->next->next == nullptr) 
    {
        return;
    }
    node* p = front->next; 
    while (p != nullptr && p->next != nullptr)
    {
        if (p->data == p->next->data)
        {
            node* temp = p->next;
            p->next = temp->next;
            delete temp;           
            count--;               
            if (p->next == NULL) 
            {
                rear = p;
            }
        }
        else 
        {
            p = p->next;
        }
    }
}

void Queue::mergeUnique(Queue& L2) 
{
    deleteTheSame();
    L2.deleteTheSame();

    node* p = this->front->next;  // L1
    node* q = L2.front->next;     // L2
    node* tail = this->front;     
    tail->next = nullptr;

    
    while (p != nullptr && q != nullptr)//双指针合并
    {
        if (p->data < q->data)
        {
            tail->next = p;
            tail = p;
            p = p->next;
        }
        else if (p->data > q->data)
        {
            tail->next = q;
            tail = q;
            q = q->next;
        }
        else // 相等，保留一个
        {
            tail->next = p;
            tail = p;

            node* temp = q;
            q = q->next;
            delete temp;                // 删除重复节点

            p = p->next;
        }
    }

    if (p != nullptr)       //拼接剩下的表
        tail->next = p;
    if (q != nullptr) 
        tail->next = q;

    this->rear = tail; // 再更新尾指针
    while (this->rear && this->rear->next != nullptr)
        this->rear = this->rear->next;

    //  重新计数
    this->count = 0;
    node* cnt = this->front->next;
    while (cnt != nullptr)
    {
        count++;
        cnt = cnt->next;
    }

   
    delete L2.front;
    L2.front = L2.rear = nullptr;
    L2.count = 0;
}

int Queue::findLastKNode(int k)
{
    node* head = front;
    if (k <= 0 || head->next == nullptr) 
    {
        delete head;
        return 0; 
    }
    node* fast = head->next; 
    node* slow = head->next;
    for (int i = 0; i < k; i++) //快指针先走k步
    {
        if (fast == nullptr) //快指针没触底
        {
            return 0;
        }
        fast = fast->next;
    }
    while (fast != nullptr) //然后同时走
    {
        fast = fast->next;
        slow = slow->next;
    }
    cout << "倒数第" << k << "个节点的值为：" << slow->data << endl;
    return 1;
}