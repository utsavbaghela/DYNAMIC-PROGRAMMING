
public class LCSUB 
{
	static int max(int a, int b) { return (a > b)? a : b; }
	//Recursion
	/*
	static int max=Integer.MIN_VALUE;
	static int  LCSUB(char s1[], char s2[], int n, int m)
	{
		if(m==0 || n==0)
			return 0;
		else if(s1[n-1]==s2[m-1])
		{
			int x=1+LCSUB(s1,s2,n-1,m-1);
			if(x>max)
				max=x;
			return x;
		}
		else
		{
			return max(LCSUB(s1,s2,n-1,m),LCSUB(s1,s2,n,m-1));
		}
	}
	*/
	
	
	//Dynamic
	static int  LCSUB(char s1[], char s2[], int n, int m)
	{
		int table[][]=new int [n+1][m+1];
		int max=Integer.MIN_VALUE;
		for(int i=0;i<=n;i++)
		{
			for(int j=0;j<=m;j++)
			{
				if(i==0|| j==0)
					table[i][j]=0;
				
				else if(s1[i-1]==s2[j-1])
				{
					table[i][j]=table[i-1][j-1]+1;
					if(table[i][j]>max)
						max=table[i][j];
				}
				else
					table[i][j]=0;
			}
		}
		return max;
	}

	public static void main (String[] args) 
    {
		 	String s1 = "utsav45XY";
	        String s2 = "XYutsav45";
	        int n = s1.length();
	        int m = s2.length();
	 
	        System.out.println("Longest Common Substring length\n"
	                + LCSUB(s1.toCharArray(), s2.toCharArray(), n, m));
    }

}
