import java.io.*;
import java.util.*;
class GFG {
	public static void main (String[] args) {
		Scanner sc=new Scanner(System.in);
		int t=sc.nextInt();
		sc.nextLine();
		while(t-->0)
		{
		    int n;
		    n=sc.nextInt();
		    
		    int arr[]=new int[n];
	
		    
		    for(int i=0;i<n;i++)
		    {
		        arr[i]=sc.nextInt();
		    }

		    System.out.println(findSubarray(arr,n));
		}
		
	}

 // } Driver Code Ends


//User function Template for Java

public static int findSubarray(int[] arr ,int n) 
{
     int sum=0, counter=0; //variable sum=0
     HashMap<Integer,Integer>mp=new HashMap<>();
    
        for(int i=0;i<n;i++)
        {
            sum+=arr[i];  //sum stores prefix sum
            
            if(sum==0) //if prefix sum is zero that means we encounter a zero sum subarray
            {
                counter++; //hence we increment the counter
            }
            
            if(mp.containsKey(sum)) //If map contains the sum. This means we have previously seen the sum
            {
               counter+=mp.get(sum); //add the value of sum to counter
            }
            
            if(mp.containsKey(sum))
            {
                int k=mp.get(sum); //increment the key 
                k++;
                mp.put(sum,k);
                
            }
            else
             mp.put(sum,1);
        }
       
       
       return counter ; // answer 
    
}
    
