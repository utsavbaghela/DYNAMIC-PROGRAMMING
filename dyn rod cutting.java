
public class rodcutting {

	//Recursion
	/*static int cutRod(int price[], int n)
	{
		if(n==0)
			return 0;
		int q=Integer.MIN_VALUE;
		for(int i=0;i<n;i++)
		{
			q=Math.max(q,price[i]+cutRod(price,n-i-1));
		}
		return q;
		
	}*/
	
	//DYNAMIC
	static int cutRod(int price[], int n)
	{
		int table[]=new int[n+1];
		table[0]=0;
		for(int i=1;i<=n;i++)
		{
			int q=Integer.MIN_VALUE;
			int number=0;
			for(int j=0;j<i;j++)
			{
				q=Math.max(q,price[j]+table[i-j-1]);
			}
			table[i]=q;
			
			System.out.println("Select : "+number);
		}
		return table[n];
	}
	
	public static void main(String args[])
	{
		int arr[] = {1, 5, 8, 9};
	    int size = arr.length;
	    System.out.println("MAX PROFIT : "+cutRod(arr,size));
	    
	}

}
