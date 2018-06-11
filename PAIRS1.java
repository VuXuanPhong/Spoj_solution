import java.util.*;
 
class Main {
 
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int k = sc.nextInt();
		long[] a = new long[n];
		for(int i = 0; i < n; i++)
		{
			a[i] = sc.nextInt();
		}
		Arrays.sort(a);
		int count = 0;
		int l = 0;
	    int r = 0;
	    while(r < n)
	    {
			if(a[r] - a[l] == k)
			{
				count++;
				l++;
				r++;
			}
			else if(a[r] - a[l] > k)
			{
				l++;
			}
			else
	    	{
				r++;
	    	}
	    }
		System.out.print(count);
		System.out.println();
	}
 
}