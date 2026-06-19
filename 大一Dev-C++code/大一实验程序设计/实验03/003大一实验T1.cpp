#include<iostream>
using namespace std;
bool isPalindromes(int i)
{
  int back=0,m=i;
  for(;i>=1;i/=10)
  {
    back=10*back+i%10;
  }
  return m==back;
}
int main()
{
  for(int i=1;i<=1000;i++)
  {
    if(isPalindromes(i))
    cout<<i<<"是1000以内的回文数。"<<endl;
  }
  return 0;
}  
