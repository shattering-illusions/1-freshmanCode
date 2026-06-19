#ifndef SEQLIST// Ë³Ðò±í
#define SEQLIST
#include <iostream>
#include"maxlen.h"
using namespace std;

enum errorCode {success_code,overflow_code,underflow_code,rangeError_code};
typedef int elementType;
//const int maxlen = 99;
class seqList 
{
public:
	seqList();
	int length() const;
	errorCode getElement(const int i, elementType& x);
	int locate(const elementType x);
	errorCode insert(const int i, const elementType x);
	errorCode deleteElement(const int i);
	
	errorCode inPut(const int x);
	void display();

private:
	int count;
	elementType data[maxlen];
};
void josephusLoop(int n, int k, int m);
#endif 

