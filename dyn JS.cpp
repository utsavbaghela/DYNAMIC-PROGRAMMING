
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
    Job arr[] = {{6, 19, 100},{1, 2, 50}, {1,2, 70}, {2, 100, 200}};
    int n = sizeof(arr)/sizeof(arr[0]);
    sort(arr, arr+n, jobComparataor);
    cout << "The optimal profit is " << JS(arr, n-1);
    return 0;
}
