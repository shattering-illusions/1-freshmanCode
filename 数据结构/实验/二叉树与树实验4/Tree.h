#pragma once
#include<iostream>


using namespace std;
typedef char elementype;
struct Node
{
    elementype  data;
    Node* first, * next;
};

void destroyTree(Node* root)
{
    if (!root) 
        return;
    destroyTree(root->first);
    destroyTree(root->next);
    delete root;
}
void createTree(Node*& T)   //创建树或森林
{
    elementType ch;
    cin >> ch;
    if (ch == '#')
    {
        T = NULL;
        return;
    }

    
    T = new Node;
    T->data = ch;
    createTree(T->first);
    createTree(T->next);
}

int countChildren(Node* node)//计算节点的度
{
    int n = 0;
    if (!node) 
        return 0;
    for (Node* i = node->first; i; i = i->next)
        n++;
    return n;
}


int getTreeDegree(Node* root)
{
    if (root==NULL) 
        return 0;
    int du = countChildren(root);       // 自己的度
    int c = getTreeDegree(root->first); //孩子链的度
    int b = getTreeDegree(root->next);//兄弟链的度
    int m = c > b ? c : b;
    return du > m ? du : m;
}

//void visitTree(Node* node)//普通的遍历
//{
//    if (node == NULL)
//        return;
//    cout << node->data;
//}
//void preOrder(Node* node)
//{
//    if (node == NULL)
//        return;
//    visitTree(node);
//    if (node->first != NULL)
//        cout << "(";
//    
//    preOrder(node->first);
//    preOrder(node->next);
//}

void visitTree(Node* node)
{
    if (!node)                  //空指针，返回
        return;

    cout << node->data;         //打印该节点的值

    if (node->first)            //第一个孩子存在
    {
        cout << "(";            //先输出 （
        Node* child = node->first;      
        bool firstChild = true;             //判断是否为循环第一次调用
        for (; child; child = child->next) //child不空就一直循环，每次循环使child等于它的第一个孩子
        {
            if (!firstChild)        //不是第一次就输出 ,
                cout << ",";
            visitTree(child);       //递归
            firstChild = false;
        }
        cout << ")";
    }
}

void preOrder(Node* node)           //  T6  加括号的遍历
{
    if (!node) 
        return;
    Node* t = node;
    bool first = true;
    for (; t; t = t->next) 
    {
        if (!first) 
            cout << ", ";           //输出树之间的逗号，只有一棵树就不会输出这个逗号
        visitTree(t);
        first = false;
    }
}

