//============================================================================
// Name        : dyn.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <iomanip>
using namespace std;

int eggdrop(int e,int f)
{
	int t[e+1][f+1];
	 for (int i = 1; i <= e; i++)
	    {
	        t[i][1] = 1;
	        t[i][0] = 0;
	    }
	    for (int j = 1; j <= f; j++)
	        t[1][j] = j;



	for(int i=2;i<=e;i++)
	{
		for(int j=2;j<=f;j++)
		{
			 t[i][j]=INT_MAX;
			for(int k=1;k<=j;k++)
			{
				int q=1+max(t[i-1][k-1],t[i][j-k]);
						if(q<t[i][j])
							t[i][j]=q;
			}
		}
	}

	for(int i=1;i<=e;i++)
		{
		cout<<i<<" egg | ";
			for(int j=0;j<=f;j++)
			{
				cout<<setw(2)<<t[i][j]<<" ";
			}
			cout<<endl;
		}
	cout<<endl;
	cout<<"MIN NO OF Attemps : ";
	return t[e][f];

}

int main() {
	int e=2,f=6;
	cout<<"EGG DROP PROBLEM DYNAMIC APPROACH"<<endl<<endl;
	cout<<eggdrop(e,f);
	return 0;
}
