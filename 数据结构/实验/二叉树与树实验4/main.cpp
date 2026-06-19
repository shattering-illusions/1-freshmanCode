#include <iostream>
#include <cstdlib>

using namespace std;
#include "Btree.h"
#include "Tree.h"


int main()
{
    //T1
    cout << "1234##5##6#7##8##" << "abcd#e##fg#h###ijk##lmn######" << endl;
    cout << "请输入上方的第一题测试数据" << endl;


    btNode* t1, *t12;

    CreateBitree(t1);
    CreateBitree(t12);
    int sizeT1 = getSize(t1);
    int sizeT12 = getSize(t12);

    char* a1 = new char[sizeT1+1]();
    char* a12 = new char[sizeT12+1]();

    Preorder(t1); cout << endl;
    Preorder(t12); cout << endl;

    transToSeq(t1, a1, 1);
    transToSeq(t12, a12, 1);
    cout << "第一个顺序存储结果为：" << endl;
    for (int i = 1;i<sizeT1+1; i++)
    {
        cout << a1[i];
    }cout << endl;
    cout << "第 2 个顺序存储结果为：" << endl;
    for (int i = 1; i < sizeT12 + 1; i++)
    {
        cout << a12[i];
    }cout << endl;
    delete[]a1;
    delete[]a12;
    cout << "====================" << endl << endl;
    //T2
    cout << "abcde##f##gh##i##jkl##m##no##p##qrst##u##vw##x##yz1##2##34##5##"
        << "abcde##f##g##hi##j##klm##n##op#q##rs##tu###" << endl;
    cout << "请输入上方的第二题测试数据" << endl;
    btNode* t2, * t22;

    CreateBitree(t2);
    CreateBitree(t22);
    Preorder(t2); cout << endl;
    Preorder(t22); cout << endl;
    cout << "第一组数据：" << endl;
    found(t2, 'j');
    cout << "第二组数据：" << endl;
    found(t22, 'z');
    cout << "====================" << endl << endl;

    //T3
   cout << "abcd#ef#g##hi##j##kl##m##no##p##qr#st##u##vw#x##y#z##"
        << "abcde##f##g##hi##j##klm##n##op#q##rs##tu###" << endl;
    cout << "请输入上方的第三题测试数据" << endl;
    btNode* t3, * t32;

    CreateBitree(t3);
    CreateBitree(t32);
    Preorder(t3); cout << endl;
    Preorder(t32); cout << endl;
    //qsgq
   
    cout << findCommonAN(t3, 'q', 's')->data << endl;
    cout << findCommonAN(t32, 'g', 'q')->data << endl;
    cout << "====================" << endl << endl;

    //T4
    cout << "abcd#ef#g##hi##j##kl##m##no##p##qr#st##u##vw#x##y#z##"
        << "abcde##f##g##hi##j##klm##n##op#q##rs##tu###" << endl;
    cout << "请输入上方的第四题测试数据" << endl;
    btNode* t4, * t42;

    CreateBitree(t4);
    CreateBitree(t42);
    Preorder(t4); cout << endl;
    Preorder(t42); cout << endl;
    cout << "第一组数据：" << endl;
    displayT4(t4);
    cout << "第二组数据：" << endl;
    displayT4(t42);

    cout << "====================" << endl << endl;

    //T5
    cout << "ABEK##F##CG##DH#I#J####"
        << "ABE#F##CG##DH#I#J###KL#MN###OPQST####R###" << endl;
    cout << "请输入上方的第五题测试数据" << endl;
    Node* t5,*f5;
   
    createTree(t5);
    cout << "第一组数据度为" << getTreeDegree(t5) << endl;
    createTree(f5);
    cout << "第二组数据度为" << getTreeDegree(f5)<<endl;
    cout << "====================" << endl << endl;

    //T6
    cout << "ABEK##F##CG##DH#I#J####"
        << "ABE#F##CG##DH#I#J###KL#MN###OPQST####R###" << endl;
    cout << "请输入上方的第六题测试数据" << endl;
    Node* t6, *f6;
    createTree(t6);
    createTree(f6);
    preOrder(t6); cout << endl;
    preOrder(f6); cout << endl;


    return 0;
}
