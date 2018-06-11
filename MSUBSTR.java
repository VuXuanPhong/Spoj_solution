import java.util.*;
import java.lang.*;

class Main
{
	public static void main (String[] args) throws java.lang.Exception
	{
		Scanner sc = new Scanner(System.in);
        int t;
        t = sc.nextInt();
        sc.nextLine();
        for(int i=0; i<t; i++){
            String str = sc.nextLine();
            int sz = str.length();
            int []d = new int[sz];
            for(int j=0; j<sz;j++){
                d[j] = 0;
            }
            d[0] +=2;
            for(int j = 1; j<sz-1;j++){
                int a = j-1;
                int b = j +1;
                int dem = 1;
                while(str.charAt(a) == str.charAt(b)){
                    dem += 2;
                    a--;
                    b++;
                    if(a < 0 || b >= sz) break;
                }
                d[dem-1] ++;
            }

            for(int j=0; j<sz-1; j++){
                if(str.charAt(j) == str.charAt(j+1)){
                    if(j == 0 || j== sz-2) d[1]++;
                    else {
                        int a = j - 1;
                        int b = j + 2;
                        int dem = 2;
                        while(str.charAt(a) == str.charAt(b)){
                            dem += 2;
                            a --;
                            b ++;
                            if(a <0 || b>= sz) break;
                        }
                        d[dem-1]++;
                    }
                }
            }

            for(int j = sz-1;j>=0;j--){
                if(d[j]!=0) {
                    System.out.println((j+1) +" " + d[j]);
                    break;
                }
            }

	}
	}
}