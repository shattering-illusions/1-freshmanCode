#include<iostream>
#include<iomanip>
using namespace std;
double footToMeter(double foot)
{
	double meter=0.305*foot; 
	return meter;
}
double meterToFoot(double meter)
{
	double foot=meter/0.305;
	return foot; 
}
int main()
{
	cout<<left<<setw(8)<<"Foots"<<setw(8)<<"Meters"<<setw(8)<<"|"<<setw(8)<<"Meters"<<setw(8)<<"Foots"<<endl;
	for(double n=1;n<=10;n++)
	{
		cout<<fixed<<setprecision(1)<<setw(8)<<n<<setprecision(3)<<setw(8)<<footToMeter(n);
		cout<<setw(8)<<"|";
		cout<<fixed<<setprecision(1)<<setw(8)<<5*n+15<<setprecision(3)<<setw(8)<<meterToFoot(5*n+15);
		cout<<endl;
	} 	
	return 0;
}
