#include<iostream>
using namespace std;
const int N = 3;
void multiplyMatrix(const double a[][N],const double b[][N],double c[][N])
{
    for(int i=0;i<3;i++)
        for(int iz=0;iz<3;iz++)
            c[i][iz]=a[i][0]*b[0][iz]+a[i][1]*b[1][iz]+a[i][2]*b[2][iz];
}
int main()
{
    double a[3][3],b[3][3],c[3][3];
    for(int i=0;i<N;i++)
        for(int iz=0;iz<N;iz++)
            cin>>a[i][iz];
    for(int i=0;i<N;i++)
        for(int iz=0;iz<N;iz++)
            cin>>b[i][iz];
    multiplyMatrix(a,b,c);
    for(int zz=0;zz<N;zz++)
    {
        for(int i=0;i<N;i++)
            cout<<" "<<a[zz][i];
        if(zz!=1)
            cout<<"   ";
        else if(zz==1)
            cout<<" * ";
        for(int i=0;i<N;i++)
            cout<<" "<<b[zz][i];
        if(zz!=1)
            cout<<"   ";
        else if(zz==1)
            cout<<" = ";
        for(int i=0;i<N;i++)
            cout<<" "<<c[zz][i];
        cout<<endl;
    }
    return 0;
}