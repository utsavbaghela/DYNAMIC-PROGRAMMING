//============================================================================
// Name        : .cpp
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
bool jobComparataor(Job s1, Job s2)
{
    return (s1.finish < s2.finish);
}
int binarySearch(Job arr[], int index)
{
    int low = 0, high = index - 1;
    while(high>=low)
    {
    	int mid=(low+high)/2;
    		if(arr[mid].finish <= arr[index].start)
    		{
    			if(arr[mid+1].finish<=arr[index].start)
    				low=mid+1;
    			else
    			return mid;
    		}
    		else
    			high=mid-1;
    		}
    return -1;
}

int findMaxProfit(Job arr[],int n)
{
	sort(arr, arr+n, jobComparataor);
	int table[n];
	for(int i=0;i<n;i++)
		{
			table[i]=arr[i].profit;
		}
	for(int i=1;i<n;i++)
	{
		int j= binarySearch(arr,i);
		if(j== -1)
		{
			 continue;
		}
		else
			table[i]=max(table[i],table[j]+arr[i].profit);


	}
	for (int i = 0; i < n; i++ )
		cout<<table[i]<< " ";
	cout<<endl;

	int max=0;
	for (int i = 0; i < n; i++ )
	        if (max < table[i])
	            max = table[i];

	return max;
}
int main() {
	Job arr[] = {{1, 3, 5}, {2, 5, 6}, {4, 6, 5}, {6, 7, 4},{5, 8, 11},{7, 9, 2}};
	    int n = sizeof(arr)/sizeof(arr[0]);
	    cout << "The optimal profit is\n" << findMaxProfit(arr, n);
	    return 0;
	return 0;
}
