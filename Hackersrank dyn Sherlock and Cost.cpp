//recursion
/*#include <iostream>
using namespace std;
int dp[100001][2];
int rec(int arr[],int n,int x)
{
		return 0;

	return max(rec(arr,n-1,arr[n])+abs(arr[n]-x),  rec(arr,n-1,1) +abs(1-x)  );
}


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
			cin>>a[i];

	cout<<max(rec(a,n-2,a[n-1]),rec(a,n-2,1))<<endl;
	return 0;
	}
}*/


//memoization recursion
/*#include<bits/stdc++.h>
using namespace std;
int arr[100001];
int dp[100001][2];

int rec(int n,int x)
{
	if(n==-1)
		return 0;

	if(dp[n][0]!=-1 && arr[n+1]==x)
		return dp[n][0];

	else if(arr[n+1]!=x && dp[n][1]!=-1)
		return  dp[n][1];

	if(arr[n+1]==x)
		{
		dp[n][0]=max(  rec(n-1,arr[n])+abs(arr[n]-x)  , rec(n-1,1)+abs(1-x)    );
		return dp[n][0];
		}
	else
		{
		dp[n][1]=max(  rec(n-1,arr[n])+abs(arr[n]-x)  , rec(n-1,1)+abs(1-x)   );
		return dp[n][1];
		}


}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<n;i++)
            cin>>arr[i];
        if(n==1)
        {
            cout<<0<<endl;
            continue;
        }
       int  ans=max(rec(n-2,arr[n-1]),rec(n-2,1));
        cout<<ans<<endl;
        for(int i=0;i<n;i++)
        {
            dp[i][0]=-1;
			dp[i][1]=-1;
        }
    }
    return 0;
}*/

#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

int b[100000];
int dp[100000][2];

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		memset(dp, 0, sizeof(dp));
		int n;
		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> b[i];
		for (int i = 1; i < n; i++)
		{
			dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + abs(b[i-1] - 1));
			dp[i][1] = max(dp[i - 1][0] + abs(b[i] - 1), dp[i - 1][1]);
		}
		for (int i = 0; i < n; i++)
				{
			cout<<dp[i][0]<<" ";
			cout<<dp[i][1]<<" ";
			cout<<endl;
				}
		cout << max(dp[n - 1][0], dp[n - 1][1]) << endl;
	}
	return 0;
}
