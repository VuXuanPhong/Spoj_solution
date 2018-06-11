#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<int> man;
		for(int i=0; i< n; i++){
			int x;
			cin >> x;
			man.push_back(x);
		}
		vector<int> woman;
		for(int i=0; i< n; i++){
			int x;
			cin >> x;
			woman.push_back(x);
		}
		std::sort(man.begin(),man.end());
		std::sort(woman.begin(),woman.end());
		int sum = 0;
		for(int i=0; i<n;i++){
			sum += man[i]*woman[i];
		}
		cout << sum << endl;
	}
	
	
	return 0;
}
