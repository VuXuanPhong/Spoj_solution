#include <stdio.h>
#include <string.h>
char ch[1000005];

int main(){
	while(1){
		int m;
		scanf("%d",&m);
		if(m == 0) break;
		getchar();	
		gets(ch);
		int n = strlen(ch);
		int dem = 0;
		int left = 0;
		int right = 0;
		int max = 0;
		int a[256];
		int i =0;
		for( i =0; i< 256; i++) a[i] = 0;
		
		while(right < n){
			if(a[ch[right]] == 0){
				if(dem == m){
					int t_max = right - left;
					if(t_max > max) max = t_max;
					while(dem == m){
						a[ch[left]]--;
						if(a[ch[left]] == 0) dem --;
						left++;
					}
				}
				a[ch[right]] = 1;
				dem++;
			}
			else{
				a[ch[right]]++;
			}
			if(right == n -1){
				int t_max = right - left + 1;
				if(t_max > max) max = t_max;
				break;	
			}
			right++;
		}
		printf("%d\n",max);
	}
	return 0;
}