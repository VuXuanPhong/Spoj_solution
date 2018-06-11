#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main(){
	int t;
	cin >> t;
	for(int i=0; i<t;i++){
		int N,K;
		cin >> N >> K;
		vector<int> arr;
		int x;
		for(int j =0; j<N;j++){
			cin >> x;
			arr.push_back(x);
		}
		sort(arr.begin(),arr.end());
		if(K==1) {
			cout << 0 << endl;
			continue;
		}
		if(K==N){
			cout << arr[arr.size()-1] - arr[0] << endl;
			continue;
		}
		int min = arr[arr.size()-1] - arr[0];
		int left = 0;
		while(left <= N- K){
			if(arr[left+K-1] - arr[left] < min) min = arr[left+K-1] - arr[left];
			left++;
		}
		cout << min << endl;
	}
	return 0;
}
