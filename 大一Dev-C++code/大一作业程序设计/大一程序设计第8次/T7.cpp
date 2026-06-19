#include<iostream>
using namespace std;
void sort(int m[ ][2], int n);
int main()
{
    int m[6][2];
    for(int i=0;i<6;i++)
        for(int z=0;z<2;z++)
            cin>>m[i][z];
    sort(m,6);
    return 0;
}
void sort(int m[][2],int n)
{
    for(int i=1;i<n;i++)
    {
        int j=i-1;
        int key=m[i][0],key2=m[i][1];
        while(j>=0&&m[j][0]>key)
            {
                m[j+1][0]=m[j][0];
                m[j+1][1]=m[j][1];
                j--;
            }
            m[j+1][0]=key;
            m[j+1][1]=key2;
    }
    for(int i=1;i<n;i++)
    {
        int j=i-1;
        int key=m[i][0],key2=m[i][1];
        while(j>=0&&m[j][0]==key&&m[j][1]>key2)
            {
                m[j+1][1]=m[j][1];
                j--;
            }
            m[j+1][1]=key2;
    }
    for(int i=0;i<n;i++)
        cout<<"("<<m[i][0]<<", "<<m[i][1]<<")"<<endl;
}