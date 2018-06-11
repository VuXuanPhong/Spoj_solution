import java.util.*;
import java.lang.*;

class Main
{
	public static void main (String[] args) throws java.lang.Exception
	{
		Scanner sc = new Scanner(System.in);
		int n;
		String str;
		while(true){
			n = sc.nextInt();
			if(n == 0) break;
			if(n<2 || n > 20) break;
			sc.nextLine();
			str = sc.nextLine();
			int length = str.length();
			String[] arrs = new String[length/n];
			for(int i=0; i<length/n;i++){
				if(i%2 ==0){
					arrs[i] = str.substring(i*n, i*n + n);
				}
				else{
					arrs[i] =  new StringBuffer(str.substring(i*n, i*n + n)).reverse().toString();
				}
			}
			
			String s = "";
			for(int i =0; i<n;i++){
				for(int j =0; j<arrs.length;j++){
					s += arrs[j].charAt(i);
				}
				
			}
			System.out.println(s);
		}
	}
}