
public class subsetsum 
{
	//RECURSION
	/*static boolean subsetsum(int set[],int n,int sum)
	{
		if(sum==0)
			return true;
		if(n==0 && sum!=0)
			return false;
		if (set[n-1] > sum)
	         return subsetsum(set, n-1, sum);
		
		return subsetsum(set,n-1,sum) || subsetsum(set,n-1,sum-set[n-1]);
  		//          dont include              include
		
	}*/
	//DYNNAMIC 
	static boolean subsetsum1(int set[],int n,int sum)
	{
		boolean table[][]=new boolean[n+1][sum+1];
		for(int i=1;i<=sum;i++)
		{
			table[0][i]=false;
		}
		for(int i=0;i<=n;i++)
		{
			table[i][0]=true;
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=sum;j++)
			{
				if(j>=set[i-1])
				table[i][j]=table[i-1][j] || table[i - 1][j-set[i-1]];
				else
					table[i][j]=table[i-1][j];
			}
		}
		
		return table[n][sum];
		
		
	}
	public static void main(String args[])
	{
		int set[] = {3, 34, 4, 12, 5, 2};
		  int sum = 9;
		  int n = set.length;
		  if (subsetsum1(set, n, sum))
		     System.out.println("FOUND");
		  else
		    System.out.println("Not FOUND");
	}

}
