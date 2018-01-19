
public class twostringinterleaving 
{
	public boolean stringinterleave(char s1[], char s2[], char s3[])
	{
		boolean table[][]=new boolean[s1.length+1][s2.length+1];
		
		if(s1.length+s2.length!=s3.length){
			return false;
		}
		for(int i=0;i<=s1.length;i++)
		{
			for(int j=0;j<=s2.length;j++)
			{
				int l=i+j-1;
				if(i==0 && j==0)
				{
					table[i][j]=true;
				}
				else if(i==0)
				{
					if(s3[l]==s1[j-1])
						table[i][j]=table[i][j-1];
				}
				else if(j==0)
				{
					if(s3[l]==s2[i-1])
						table[i][j]=table[i-1][j];
				}
				else
				{
					if(s3[l]==s2[i-1] && table[i-1][j]==true)
						table[i][j]=true;
					else if(s3[l]==s1[j-1] && table[i][j-1]==true)
						table[i][j]=true;
					else
						table[i][j]=false;
				}
			}
		}
		for(int i=0;i<=s1.length;i++)
		{
			for(int j=0;j<=s2.length;j++)
			{
			 System.out.print(table[i][j]+" ");	
			}
			System.out.println();
		}
		return table[s1.length][s2.length];
		
		
	}
	public static void main(String args[]){
        String str1 = "aab";
        String str2 = "axy";
        String str3 = "aaxaby";
        
       twostringinterleaving obj =new twostringinterleaving();
       boolean ans=obj.stringinterleave(str1.toCharArray(),str2.toCharArray(),str3.toCharArray());
       System.out.println(ans);
        
    }

}
