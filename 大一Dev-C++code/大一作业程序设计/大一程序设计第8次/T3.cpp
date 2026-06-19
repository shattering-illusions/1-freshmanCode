# include <iostream>
using namespace std;
const int SIZE = 4;
void find(int a[][SIZE],int rowSize);
void row(int a[][SIZE],int rowSize,int &pdd);
void column(int a[][SIZE],int rowSize,int &pdd);
void diagonal(int a[][SIZE],int rowSize,int &pdd1,int &pdd2);
int main()
{
    int array[4][4];
    for(int i=0;i<4;i++)
        for(int z=0;z<4;z++)
            cin>>array[i][z];
    find(array,4);
    return 0;
}
void find(int a[][SIZE],int rowSize)
{
    int pdRow=0,pdcolumn=0,pdDia1=0,pdDia2=0;
    row(a,rowSize,pdRow);
    column(a,rowSize,pdcolumn);
    diagonal(a,rowSize,pdDia1,pdDia2);
if(pdRow!=0)
    cout<<"No same numbers on the same row"<<endl;
if(pdcolumn!=0)
    cout<<"No same numbers on the same column"<<endl;
if(pdDia1!=0)
    cout<<"No same numbers on the same diagonal"<<endl;
if(pdDia2!=0)
    cout<<"No same numbers on the same subdiagonal"<<endl;
}
void row(int a[][SIZE],int rowSize,int &pdd)
{
	int pd1=0;
    for(int i=0;i<rowSize;i++)
    {
        int pd=0;
        for(int cs=a[i][0],z=0;z<SIZE;z++)
        {
            if(cs!=a[i][z])
                pd++;
        }
        if(pd==0)
        {
        	pd1++;
            cout<<"All "<<a[i][0]<<"'s on row "<<i<<endl;
        }
    }
    
    if(pd1==0)
    	pdd++;
}
void column(int a[][SIZE],int rowSize,int &pdd)
{
	int pd1=0;
    for(int i=0;i<SIZE;i++)
    {
        int pd=0;
        for(int cs=a[0][i],z=0;z<rowSize;z++)
        {
            if(cs!=a[z][i])
                pd++;
        }
        if(pd==0)
        {
        	pd1++;
            cout<<"All "<<a[0][i]<<"'s on column "<<i<<endl;
        }
    }
    
    if(pd1==0)
    	pdd++;
}
void diagonal(int a[][SIZE],int rowSize,int &pdd1,int &pdd2)
{
    int pd=0,pd1=0;
    for(int i=0;i<rowSize;i++)
    {
        if(a[0][0]!=a[i][i])
            pd++;
    }
    if(pd==0)
    {
        cout<<"All "<<a[0][0]<<"'s on major diagonal"<<endl;
    }
    else
    {
        pdd1++;
    }
    for(int i=0;i<rowSize;i++)
    { 
        if(a[0][4]!=a[i][4-i])
            pd1++;
    }
    if(pd1==0)
    {
        cout<<"All "<<a[0][4]<<"'s on sub-diagonal"<<endl;
    }
    else
    {
        pdd2++;
    }
}  
