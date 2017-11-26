import java.lang.reflect.Array;
import java.util.Comparator;
import java.util.*;

class Pair
{
    int a;
    int b;
     
    public Pair(int a, int b) {
        this.a = a;
        this.b = b;
    }
}
    
class Sortbyfirst implements Comparator<Pair>
{

    public int compare(Pair a, Pair b)
    {
        return a.a - b.a;
    }
}

    
public class max_chain 
{
	static int maxchain(Pair a[],int n)
	{
		int table[]=new int[n+1];
		Arrays.fill(table,1);
		table[0]=1;
				
		for(int i=1;i<n;i++)
		{
			for(int j=0;j<i;j++)
			{
				if(a[i].a >= a[j].b && table[i]<table[j]+1 )
					table[i]=table[j]+1;
			}
		}
		
		int max=0;
		for ( int i = 0; i < n; i++ )
        if ( max < table[i] )
           max = table[i];
    
     return max;
	}
	public static int compare(Pair a, Pair b)
    {
        return a.a - b.a;
    }
	public static void main (String[] args) 
    {
        Pair arr[] = new Pair[] {new Pair(5,24), new Pair(15, 25),
                                  new Pair (27, 40), new Pair(50, 60)};
        int n=arr.length;
        Arrays.sort(arr, new Sortbyfirst());
        System.out.println("Length of maximum size chain is " +maxchain(arr, n));
    }

}
