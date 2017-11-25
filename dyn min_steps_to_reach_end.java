import java.util.Arrays;

public class min_steps 
{
	//recursion with memoization
	/*static int minsteps(int a[],int current,int last,int table[])
	{
		if(table[current]!=-1)
			return table[current];

		if(current==last) 
			return 0;
		
		if(a[current]==0)
			return Integer.MAX_VALUE;
		
		int q=Integer.MAX_VALUE;
		for(int i=current+1;i<=current+a[current] && i<=last  ;i++)
		{
			   int jumps = minsteps(a,i,last,table);
		       if(jumps != Integer.MAX_VALUE && jumps + 1 < q)
		           q = jumps + 1;
		}
		table[current]=q;
	//	System.out.println(current+" " +table[current]+" ");
		return table[current];
	}*/
	
	//dynamic
	static int minsteps(int a[],int last,int table[])
	{
		table[last]=0;
		for(int i=last;i>=0;i--)
		{
			for(int j=i-1;j>=0;j--)
			{
				if(i<=j+a[j])
				{
					table[j]=Math.min(table[j], table[i]+1);
				}
			}
		}
		
		return table[0];
		
		/*
		 * OR
		 * 
		 
	table[0] = 0;

    for (int i = 1; i < n; i++)
    {
        table[i] = Integer.MAX_VALUE;
         for (int j = 0; j < i; j++)
         {
              if (i <= j + a[j] && table[j] != Integer.MAX_VALUE)
              {
                  table[i] = Math.min(table[i], table[j] + 1);
                  break;
              }
          }
    }
        return table[n-1];
		 */
				
	}
	
	public static void main(String args[])
	{
		
		  int a[] = {2, 3, 2,8,9,5};
		  int n = a.length;
		  int table[]=new int[n+1];
		  Arrays.fill(table, Integer.MAX_VALUE);//for dynamic
		//  Arrays.fill(table, -1);//for recursion memoization
		  System.out.println(minsteps(a,n-1,table));
	}

}
