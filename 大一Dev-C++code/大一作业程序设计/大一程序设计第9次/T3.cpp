#include<iostream>
using namespace std;
void maopao(int *arr,int size);
void xuanze(int *arr,int size);
void mergeSort(int *ar,int left,int right );
void merge(int ar[],int left,int rmin,int rmax);
int main()
{
	int size;
	cin>>size;
	int *p=new int[size];
	for(int i=0;i<size;i++)
		cin>>p[i];
	cout<<"冒泡排序结果"<<endl; 
	maopao(p,size);
	cout<<"选择排序结果"<<endl;
	xuanze(p,size);
	cout<<"归并排序结果"<<endl;
	mergeSort(p,0,size-1);
	for(int i = 0;i<size;i++)
		cout<<p[i]<<" ";
	delete []p;
	return 0;
}
void maopao(int *arr,int size)
{
	int *ar= new int [size];
	for(int i =0;i<size;i++)
		*(ar+i)=*(arr+i);
	int temp;
	for(int i=0;i<size-1;i++)
		for(int z=0;z<size-1;z++)
		{
			if(ar[z+1]<ar[z])
			{
				temp=ar[z+1];
				ar[z+1]=ar[z];
				ar[z]=temp;
			}
		}
	for(int i = 0;i<size;i++)
		cout<<ar[i]<<" ";
	delete [] ar;
	cout<<endl;
}
void xuanze(int *arr,int size)
{
	int *ar= new int [size];
	for(int i =0;i<size;i++)
		*(ar+i)=*(arr+i);
	
	for(int i=0;i<size-1;i++)
	{
		int min=i;
		for(int z=i+1;z<size;z++)
		{
			if(*(ar+min)>*(ar+z))
			{
				min=z;
			}
		}
		int temp=*(ar+min);
		*(ar+min)=*(ar+i);
		*(ar+i)=temp;
	}
	for(int i = 0;i<size;i++)
		cout<<ar[i]<<" ";
	delete [] ar;
	cout<<endl;
}
void mergeSort(int *ar,int left,int right)
{
	if(left==right)
		return; 
	int mid=left+(right-left)/2;
	mergeSort(ar,left,mid);
	mergeSort(ar,mid+1,right);
	merge(ar,left,mid+1,right);
}
void merge(int ar[],int left,int rmin,int rmax)
{
	int temp;
	while(left<=rmin-1&&rmin<=rmax)
	{
		if(ar[left] <= ar[rmin])
			left++;
		else
		{
			temp=ar[rmin];
			for(int i=rmin;i>=left;i--)
				ar[i]=ar[i-1];
			ar[left++]=temp;
			rmin++; 
		}
	}
}
