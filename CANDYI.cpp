#include <iostream>
using namespace std;

int main(){
	while(true){
		int N;
		cin >> N;
		if(N == -1) break;
		int a[N];
		int sum =0;
		for(int i=0; i<N;i++){
			cin >> a[i];
			sum += a[i];
		}
		if(sum%N!=0) {
			cout << -1 << endl;
			continue;
		}
		int tb = sum/N;
		int move = 0;
		for(int i=0; i<N;i++){
			if(a[i]<tb) move += tb-a[i];
		}
		cout << move << endl;
	}
	return 0;
}
