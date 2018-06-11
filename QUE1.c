#include <stdio.h>
void swap(int* a, int* b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

int main(){
	int t;
	scanf("%d",&t);
	int i =0;
	for(i= 0; i<t;i++){
		int n;
		scanf("%d",&n);
		int a[n];
		int b[n];
		int j,k;
		for(j=0;j<n;j++){
			scanf("%d",&a[j]);
		}
		for(j=0;j<n;j++){
			scanf("%d",&b[j]);
		}
		for(j=0; j<n-1; j++){
			for(k=j+1;k<n;k++){
				if(a[j] > a[k]) {
					swap(&a[j],&a[k]);
					swap(&b[j],&b[k]);
				}
			}
		}
		int c[n];
		for(j=0;j<n;j++){
			c[j] = 0;
		}
		for( j=0; j<n;j++){
			int l = 0;
			for(k =0; k<n;k++){
				if(l == b[j] && c[k] ==0) {
					break;
				}
				if(c[k] == 0) l++;
			}
			c[k] = a[j];
		}
		for(j=0;j<n;j++){
			printf("%d ",c[j]);
		}
	}
	return 0;
}