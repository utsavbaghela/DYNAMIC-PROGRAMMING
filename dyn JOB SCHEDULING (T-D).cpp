//============================================================================
// Name        : dyn.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
struct Job
{
    int start, finish, profit;
};

int JS(struct Job arr[],int n)
{
	if(n<0)
		return 0;
	int current=arr[n].profit;
	for(int i=0;i<n;i++)
	{
		int z=JS(arr,i);
		if(arr[n].start >= arr[i].finish && arr[n].profit+z>current)
		{
			current=arr[n].profit+z;
		}				
	}
	return current;
	
}
int main()
{
    Job arr[] = {{1, 2, 50}, {3,5, 20}, {6, 19, 100}, {2, 100, 200}};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "The optimal profit is " << JS(arr, n-1);
    return 0;
}