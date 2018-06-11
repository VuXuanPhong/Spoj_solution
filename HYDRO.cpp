#include <iostream>
using namespace std;

int main(){
	int t;
	cin >> t;
	for(int i =0; i< t; i++){
		int N;
		cin >> N;
		int a[N];
		int idMax = 0;
		for(int j=0; j< N;j++){
			cin >> a[j];
			if(a[j] > a[idMax]) idMax = j;
		} 
		int sum = 0;
		int max = 0;
		for(int i=0; i<idMax;i++){
			if(a[i] > max) max = a[i];
			else sum += max - a[i];
		}
		max = 0;
		for(int i= N-1; i>idMax; i--){
			if(a[i] > max) max = a[i];
			else sum += max - a[i];
		}
		cout << sum << endl;
	}
}