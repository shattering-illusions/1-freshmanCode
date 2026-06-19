 #include<iostream>
using namespace std;
struct information
{
	string name;
	string phonenums;
	int years;	
};
int main()
{
	int n;
	cin>>n;
	information people[n];
	int ar[n],a[n];
	string arr[n]; 
	for(int i=0;i<n;i++)
	{
		cin>>people[i].name>>people[i].phonenums>>people[i].years;
	}
	for(int i=0;i<n;++i)
	{
		a[i]=i;
		ar[i]=people[i].years;
	}
	for(int i=0;i<n;++i)
	{
		arr[i]=people[i].name;
	}
	for(int i=0;i<n;i++)
	{
		int max1=ar[i],maxnum=a[i],zz=i+1;
		string max2=arr[i];
		for(;zz<n;zz++)
		{
			if(ar[zz]>max1)
			{
				max1=ar[zz];
				ar[zz]=ar[i];
				ar[i]=max1;
				maxnum=a[zz];
				a[zz]=a[i];
				a[i]=maxnum;
				max2=arr[zz];
				arr[zz]=arr[i];
				arr[i]=max2;
			}
			else if(ar[zz]==max1)
			{
				if(people[zz].name<max2)
				{
					
					max1=ar[zz];
					ar[zz]=ar[i];
					ar[i]=max1;
					maxnum=a[zz];
					a[zz]=a[i];
					a[i]=maxnum;
					max2=arr[zz];
					arr[zz]=arr[i];
					arr[i]=max2;
				}
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		cout<<people[a[i]].name<<", "<<people[a[i]].phonenums<<", "<<people[a[i]].years<<endl;
	}
	return 0; 
}