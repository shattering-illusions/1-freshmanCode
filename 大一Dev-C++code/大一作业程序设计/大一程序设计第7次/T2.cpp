#include<iostream>
#include<vector>
using namespace std;
int main()
{
	vector<int> score;
	for(int i;;)
	{
		cin>>i;
		if(i>=0)
			score.push_back(i);
		else if(i<0)
			break;
	}
	int length=score.size(),dy=0,xy=0,ey=0,sum=0;
	double ad;
	for(int i=0;i<length;++i)
	{
		sum+=score[i];
	}
	ad=sum/length;
	for(int i=0;i<length;i++)
	{
		if(score[i]>ad)
			dy++;
		else if(score[i]==ad)
			ey++;
		else if(score[i]<ad)
			xy++;
	}
	cout<<"平均分"<<ad<<endl;
	cout<<"高于平均分"<<dy<<endl;
	cout<<"等于平均分"<<ey<<endl;
	cout<<"低于平均分"<<xy<<endl;
	return 0;
}

