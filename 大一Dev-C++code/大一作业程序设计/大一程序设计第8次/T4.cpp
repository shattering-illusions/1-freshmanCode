#include<iostream>
using namespace std;
void outputWorkTime(int work[8][7]);
int main()
{
    int work[8][7];
    for(int r0w=0;r0w<8;r0w++)
        for(int column=0;column<7;column++)
            cin>>work[r0w][column];
    outputWorkTime(work);
    return 0;
}
void outputWorkTime(int work[8][7])
{
    int sum[8]={0};
    for(int jsi=0;jsi<8;jsi++)
        for(int jsz=0;jsz<7;jsz++)
            sum[jsi]+=work[jsi][jsz];
    int sum2[2][8];
    for(int i=0;i<8;i++)
    {
        sum2[0][i]=sum[i];
        sum2[1][i]=i;
    }
    for(int i=0;i<7;i++)
    {
        int min=i;
        for(int zz=i+1;zz<8;zz++)
        {
            if(sum2[0][zz]<sum2[0][min])
            {
                min=zz;
            }
        }
        int temp1=sum2[0][min],temp2=sum2[1][min];
        sum2[0][min]=sum2[0][i];
        sum2[1][min]=sum2[1][i];
        sum2[0][i]=temp1;
        sum2[1][i]=temp2;
    }
    for(int i=7;i>=0;i--)//Employee 7: 41
    {
        cout<<"Employee "<<sum2[1][i]<<": "<<sum2[0][i]<<endl;
    }
}