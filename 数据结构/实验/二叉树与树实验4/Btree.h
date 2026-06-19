#pragma once
#include <iostream>
#include <cmath>

using namespace std;
typedef char elementType;
struct btNode
{
    elementType  data;
    btNode *lChild, *rChild;
}; 

void CreateBitree(btNode*& T)
{
    char ch;
    cin >> ch;
    if (ch == '#')
        T = NULL;
    else
    {
        T = new btNode;
        T->data = ch;
        CreateBitree(T->lChild);
        CreateBitree(T->rChild);
    }
}
void Visit(btNode* t)
{
    cout << t->data;
}
void  Preorder(btNode* t)
{
    if (t != NULL)
    {
        Visit(t);
        Preorder(t->lChild);
        Preorder(t->rChild);
    }
}
void  Inorder(btNode* t)
{
    if (t != NULL)
    {
        Inorder(t->lChild);
        Visit(t);
        Inorder(t->rChild);
    }
}
void  Postorder(btNode* t)
{
    if (t != NULL)
    {
        Postorder(t->lChild);
        Postorder(t->rChild);
        Visit(t);
    }
}

void destroy(btNode*& T)        //释放二叉树，没用到
{
    if (T == NULL) 
        return;
    destroy(T->lChild);
    destroy(T->rChild);
    delete T;
    T = NULL;
}

int getDepth(btNode* T)                //求二叉树深度
{
    if (T == NULL) 
        return 0;
    int leftDepth = getDepth(T->lChild);
    int rightDepth = getDepth(T->rChild);

    return max(leftDepth, rightDepth) + 1;
}

int getSize(btNode* T)                  //依据深度求完全二叉树最大元素个数
{
    int deep = getDepth(T);
    int size = pow(deep, 2) + 1;
    return size;
}

void transToSeq(btNode* T, char a[], int i)//转换为顺序存储，T1
{

    if (T == NULL)
        return;
    a[i] = T->data;
    transToSeq(T->lChild, a, 2 * i);
    transToSeq(T->rChild, a, 2 * i+1);
}

elementType visit(btNode* T)//返回节点值
{
    return T->data;
}

bool  find(btNode* t,elementType ch,elementType father='#', elementType brother = '#', bool LorR=0)
{

    if (t == NULL)      //空
    {
        return false;
    }

        elementType f = t->data,L='#',R='#';
        
        if (visit(t) == ch)     //找到了
        {
            if (father == '#')
                cout << "它是根节点." << endl;
            else
                cout << "它的父节点值为:" << father <<  endl;
            if (brother == '#')
                cout << "它没有兄弟节点." << endl;
            else if (LorR && brother != '#')
                cout << "它的右兄弟节点为:" << brother << endl;
            else if (brother != '#')
                cout << "它的左兄弟节点为:" << brother << endl;

            if (t->lChild == NULL)
                cout << "它没有左孩子." <<  endl;
            else
                cout << "它的左孩子节点值为:" << t->lChild->data << endl;
            if (t->rChild == NULL)
                cout << "它没有右孩子." << endl;
            else
                cout << "它的右孩子节点值为:" << t->rChild->data << endl;
            return 1;
        }
    if (t->lChild != NULL)
    {
    L = t->lChild->data;
    }
    if (t->rChild != NULL)
    {
    R = t->rChild->data;
    }

    if (find(t->lChild, ch, f, R, 1))//递归
        return true;
    if (find(t->rChild, ch, f, L, 0))
        return true;
    return false;
}
void found(btNode* t, elementType ch)
{
    if (!find(t, ch))
    {
        cout << "没找到！!" << endl;
    }
}

bool isExist(btNode* t, elementType ch)//判断元素是否存在
{
    if (t == NULL) 
        return false;//空，不存在
    if (t->data == ch) 
        return true;
    return isExist(t->lChild, ch) || isExist(t->rChild, ch);
}


btNode* findCommonAN(btNode* root, elementType p, elementType q)//找公共祖先，T3
{
    
    if (root == NULL || root->data == p || root->data == q)//空节点或找到自己，直接返回root
    {
        return root;
    }

    
    btNode* left = findCommonAN(root->lChild, p, q);// 递归查找
    btNode* right = findCommonAN(root->rChild, p, q);

    
    if (left != NULL && right != NULL)
    {
        return root;
    }
    else if (left == NULL)// 在右子树
    {
        return right;
    }
    else                //在左子树              
    {
        return left;
    }
}

void leafToRoot(btNode* node, char path[], int length) //T4
{
    if (node == NULL) 
        return;

    path[length] = node->data;// 暂存节点
    length++;

    if (node->lChild == NULL && node->rChild == NULL)  // 判断是否为叶子节点
    {
        cout << "叶子节点'" << node->data << "'到根的路径为：";
        for (int i = length - 1; i >= 0; i--) //输出路径
        {
            cout << path[i];
            if (i > 0) 
            {
                cout << "->";
            }
        }
        cout << endl;
    }
    else 
    {
        leafToRoot(node->lChild, path, length);  // 递归
        leafToRoot(node->rChild, path, length);
    }
}

void displayT4(btNode* root)   //输出T4
{
    char* path = new char[getDepth(root)];
    leafToRoot(root, path, 0);
    delete[]path;
}

