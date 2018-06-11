#include <iostream>
using namespace std;

int a[1000005];
int main(){
	int n,q;
	cin >> n >> q;
	for(int i=0; i<n; i++) a[i] = 0;
	for(int i=0; i<q; i++){
		int type, yk;
		cin >> type >> yk;
		if(type == 1){
			a[yk-1] = -1;
		}
		else if(type == 2){
			int b = yk-1;
			bool bb = false;
			while(b < n){
				if(a[b] == -1) {
					cout << b + 1 << endl;
					bb = true;
					break;
				}
				b++;
			}
			if(!bb) cout << -1 << endl;
		}
		
	}
	
	return 0;
}
