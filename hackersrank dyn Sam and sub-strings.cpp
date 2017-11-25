
#include <bits/stdc++.h>
#define FOR(i, a, b) for(long long i = (a); i < (b); i++)
#define FORREV(i, a, b) for(long long i = (a); i >= (b); i--)
using namespace std;
#define mod 1000000007

int main() {
	string s;
	cin>>s;
	long long  sum=0;
	long long f=1;
	FORREV(i,s.length()-1,0)
	{
		sum=(sum+(s[i]-'0')*f*(i+1))%mod;
		f=(f*10+1)%mod;
	}
	cout<<sum%mod<<endl;
	return 0;
}


