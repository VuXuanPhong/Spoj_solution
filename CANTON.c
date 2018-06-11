#include <stdio.h>

int findRow(int n){
	int i = 1;
	while(1){
		int x = i*(i+1)/2;
		if(x >= n) break;
		i++;
	}
	return i;
}


int main(){
	int t;
	scanf("%d",&t);
	int i =0;
	for(i=0; i<t;i++){
		int number;
		scanf("%d",&number);
		int a = findRow(number);
		int row = a;
		int begin = ((a-1)*a/2) +1;
		int b = 1;
		
		while(begin != number){
			a--;
			b++;
			begin++;
		}
		if(row%2 == 0){
			printf("TERM %d IS %d/%d\n",number,b,a);
		}
		else printf("TERM %d IS %d/%d\n",number,a,b);
	}
	
	return 0;
}