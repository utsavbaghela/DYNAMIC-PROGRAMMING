//============================================================================
// Name        : dyn.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
void lps(char str[],int n)
{
	int t[n][n];
	for(int i=0;i<n;i++)
		          {
		         	 for(int j=0;j<n;j++)
		         	 {
		         		 t[i][j]=0;
		         	 }

		          }
	for(int i=0;i<n;i++)
			t[i][i]=1;

	for(int l=2;l<=n;l++)
	{
		for(int i=0;i<n-l+1;i++)
		{
			int j;
			j=i+l-1;
			if(str[i]==str[j] && l==2)
				t[i][j]=2;
			else if(str[i]==str[j])
				t[i][j]= 2 + t[i+1][j-1];
			else
			    t[i][j] = max(t[i][j-1], t[i+1][j]);
		}
	}
	for(int i=0;i<n;i++)
	          {
	    	 	 	 cout<<str[i]<<" | ";
	         	 for(int j=0;j<n;j++)
	         	 {
	         		 cout<<t[i][j]<<" ";
	         	 }
	         	 cout<<endl;
	          }

	cout<< t[0][n-1];
}



int main()
{
	int n;
	cin>>n;
	char str[n];
	cin>>str;
	lps(str,n);
	return 0;
}
