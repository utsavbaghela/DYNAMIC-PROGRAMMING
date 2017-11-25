
public class knapsack
{
	//recursion method
	/*
	static int max(int a, int b) { return (a > b)? a : b; }
	static int knapsack(int profit[],int weight[],int w,int n)
	{
		if(n==0)
			return 0;
		if(w==0)
			return 0;
		
		if(weight[n-1]>w)
			return knapsack(profit,weight,w,n-1);
		
		
		return max( knapsack(profit,weight,w,n-1)  ,profit[n-1]+ knapsack(profit,weight,w-weight[n-1],n-1));
	}
	*/
	
	//dynamic method
	static int max(int a, int b) { return (a > b)? a : b; }
	static int knapsack(int profit[],int weight[],int w,int n)
	{
		//int table[n+1][w+1];
		int table[][] = new int[n+1][w+1];
		for(int i=0;i<=n;i++)
		{
			for(int j=0;j<=w;j++)
			{
				if(i==0 || j==0)
					table[i][j]=0;
				else if (weight[i-1] <= j)
					table[i][j]=max(table[i-1][j],profit[i-1]+table[i-1][j-weight[i-1]]);
				else
					table[i][j]=table[i-1][j];			
			}
		}
		return table[n][w];
	}
	
	public static void main(String args[])
	{
		int profit[] = new int[]{60, 100, 120};
        int weight[] = new int[]{10, 20, 30};
        int w=50;
        int n=profit.length;
        System.out.println(knapsack(profit,weight,w,n));
        
	}
	
	

}
