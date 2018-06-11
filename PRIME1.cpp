#include <iostream>
using namespace std;

int main(){
	int t;
	cin >> t;
	for(int i=0; i<t;i++){
		int m,n;
		cin >> m >> n;
		bool isPrime[n+1];
		for(int j=0; j<= n; j++) isPrime[j] = true;
		isPrime[0] = false;
		isPrime[1] = false;
		for(int j=2; j*j < n; j++){
			if(isPrime[j]){
				for(int k = j*j; k<= n; k+= j){
					isPrime[k] = false;
				}
			}
		}
		for(int j =m; j<=n; j++){
			if(isPrime[j]) cout << j << endl;
		}
	}
	return 0;
}
