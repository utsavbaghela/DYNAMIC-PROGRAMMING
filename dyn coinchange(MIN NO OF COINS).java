

public class coinchange
{
	//recursion
	
	/*static int mincoins(int a[],int m,int n)
	{
		if(n==0)
			return 0;
		if(n<0)
			return Integer.MAX_VALUE-1;
		if(n>=1 && m<=0)
			return Integer.MAX_VALUE-1;
		else
		{
			return Math.min(mincoins(a,m-1,n),1+mincoins(a,m,n-a[m-1]));
		}
	}*/
	
	//DYNAMIC
	static int mincoins(int a[],int m,int n)
	{
		int table[][]=new int [m+1][n+1];
		for(int i=0;i<=m;i++)
		{
			table[i][0]=0;
		}
		for(int i=1;i<=n;i++)
		{
			if(i%a[0]==0)
			    table[0][i]=1;
			else
				table[0][i]=Integer.MAX_VALUE-1;
		}
		for(int i=1;i<=m;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(j-a[i]<0)
				{
					table[i][j]=table[i-1][j];
					continue;
				}
				table[i][j]=Math.min(table[i-1][j],1+table[i][j-a[i]]);
			}
		}
		for(int i=0;i<=m;i++)
		{
			for(int j=0;j<=n;j++)
			{
				System.out.print(table[i][j]+" ");
			}
			System.out.println();
		}
		return table[m][n];
	}

	public static void main(String args[])
	{
		int n=17;
		int a[]=new int [] {9,5,3,8};
		int length=a.length;
		System.out.println("Min coins req : " +mincoins(a,length-1,n));
		
	}

}

