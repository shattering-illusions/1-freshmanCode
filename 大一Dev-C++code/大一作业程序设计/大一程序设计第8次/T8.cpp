#include<iostream>
using namespace std;
bool isConsecutiveFour(int values[ ][7]);
int main()
{
    int values[6][7];
    for(int i=0;i<6;++i)
        for(int zz=0;zz<7;zz++)
            cin>>values[i][zz];
    if(isConsecutiveFour(values))
        cout<<"true";
    else 
        cout<<"false";
}
bool isConsecutiveFour(int values[ ][7])
{
    int pd=0;
    //≈–∂œ––
    for(int i=0;i<6;++i)
    {
        int rowMode=values[i][0],jishuqi=1;
        for(int zz=1;zz<7;zz++)
        {
            if(values[i][zz]==rowMode)
                jishuqi++;
            else
            {
                jishuqi=1;
                rowMode=values[i][zz];
            }
        }
        if(jishuqi>=4)
            pd++;
    }
    //≈–∂œ¡–
    for(int i=0;i<7;++i)
    {
        int columnMode=values[0][i],jishuqi=1;
        for(int zz=1;zz<6;zz++)
        {
            if(values[zz][i]==columnMode)
                jishuqi++;
            else
            {
                jishuqi=1;
                columnMode=values[zz][i];
            }
        }
        if(jishuqi>=4)
            pd++;
    }
    //≈–∂œ◊Û…œµΩ”“œ¬°£
    for(int m=0,n=1;n<4;n++)
    {
        int i=m,zz=n;
        int mode=values[i][zz],jsq=0;
        for(;i<6&&zz<7;i++,zz++)
        {
            if(values[i][zz]==mode)
                jsq++;
            else
            {
                jsq=0;
                mode=values[i][zz];
            }
        }
        if(jsq>=4)
            pd++;
    }
    for(int m=0,n=0;m<3;m++)
    {
        int i=m,zz=n;
        int mode=values[i][zz],jsq=0;
        for(;i<6&&zz<7;i++,zz++)
        {
            if(values[i][zz]==mode)
                jsq++;
            else
            {
                jsq=0;
                mode=values[i][zz];
            }
        }
        if(jsq>=4)
            pd++;
    }
    //≈–∂œ°£
    for(int m=3,n=0;m<6;m++)
    {
        int i=m,zz=n;
        int mode=values[i][zz],jsq=0;
        for(;i<6&&zz<7;i--,zz++)
        {
            if(values[i][zz]==mode)
                jsq++;
            else
            {
                jsq=0;
                mode=values[i][zz];
            }
        }
        if(jsq>=4)
            pd++;
    }
    for(int m=5,n=1;n<4;n++)
    {
        int i=m,zz=n;
        int mode=values[i][zz],jsq=0;
        for(;i<6&&zz<7;i--,zz++)
        {
            if(values[i][zz]==mode)
                jsq++;
            else
            {
                jsq=0;
                mode=values[i][zz];
            }
        }
        if(jsq>=4)
            pd++;
    }
    return pd!=0;
}