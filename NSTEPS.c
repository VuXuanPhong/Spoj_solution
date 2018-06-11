#include <iostream>
using namespace std;

int main(){
	int t;
	cin >> t;
	for(int i=0; i<t;i++){
		int m, n;
		cin >> m >> n;
		if(m%2==0&&n%2==0&&(m-n==2||m-n==0)){
			cout << m+n << endl;
		}
		else if(m%2!=0&&n%2!=0&&(m-n==2||m-n==0)){
			cout << m+n-1 << endl;
		}
		else cout << "No Number" << endl;
	}
}