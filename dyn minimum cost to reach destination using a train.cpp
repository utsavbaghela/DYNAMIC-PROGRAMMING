//============================================================================
// Name        : dyn.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#define N 4
#define INF INT_MAX
int minCost(int cost[][N])
{
	int table[N];
	for(int i=0;i<N;i++)
			{
			   table[i]=INF;
			}
	table[0]=0;
	table[1]=cost[0][1];

	for(int i=2;i<N;i++)
	{
		for(int j=1;j<i;j++)
		{
			int minimum = min(cost[0][i],table[j]+cost[j][i]	);
			if(minimum<table[i])
				table[i]=minimum;
		}
	}
	for(int i=0;i<N;i++)
		{  cout<<table[i]<<" ";
		}
	cout<<endl;

	return table[N-1];
}

int main()
{
    int cost[N][N] = { {0, 15, 80, 90},
                      {INF, 0, 40, 50},
                      {INF, INF, 0, 70},
                      {INF, INF, INF, 0}
                    };
    cout << "The Minimum cost to\nreach station"
          << N << " is \n" << minCost(cost);
    return 0;
}
