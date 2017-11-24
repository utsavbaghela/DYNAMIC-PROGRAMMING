
#include <iostream>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		int table[n];
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
		}
		table[0]=a[0];
		int max=table[0];
		for(int i=1;i<n;i++)
		{
			if(a[i]>a[i]+table[i-1])
			    table[i]=a[i];
			else
				table[i]=a[i]+table[i-1];

			if(table[i]>max)
				max=table[i];
		}

		cout<<max<<" ";
		int max2=0;
		int flag=0;
		int max3=a[0];
		for(int i=0;i<n;i++)
		{
			if(a[i]>=0)
			{
				flag=1;
				max2+=a[i];
			}
			if(a[i]>max3)
				max3=a[i];
		}
		if(flag==1)
		cout<<max2<<endl;
		else
			cout<<max3<<endl;
	}
	return 0;
}
