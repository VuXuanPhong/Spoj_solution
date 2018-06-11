#include <stdio.h>
#include <stdlib.h>
int* arr = NULL;
int main(){
	arr = (int*) malloc(10000005*sizeof(int));
	if(arr==NULL) exit(0);
	for(int i=0;i<10000005;i++){
		arr[i] = 0;
	}
	int t;
	scanf("%d",&t);
	for(int i=0; i<t;i++){
		int n;
		scanf("%d",&n);
		int ma = -1;
		int mi = 10000001;
		for(int j=0; j<n; j++){
			int start,end;
			scanf("%d %d",&start,&end);
			if(start < mi) mi = start;
			if(end > ma) ma = end;
			for(int k=start;k<=end;k++){
				arr[k]++;
			}
		}
		int max1 = arr[mi];
		for(int j= mi+1; j<= ma;j++){
			if(arr[j] > max1) max1 = arr[j];
		}
		printf("%d\n",max1);
		for(int j= mi; j<= ma;j++){
			arr[j] = 0;
		}
	}
	return 0;
}
