#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int main(){
	int t;
	cin >> t;
	vector<int> a;
	for (int i = 0; i<t; i++){
		int n;
		cin >> n;
		a.push_back(n);
	}
	int x = *max_element(a.begin(), a.end());
	bool isCubeFree[1000000];
	isCubeFree[0] = false;
	for (int i = 1; i <= x; i++) isCubeFree[i] = true;
	for (int i = 2; i*i*i <= x; i++){
		int a = i*i*i;
		int step = a;
		while (a <= x){
			isCubeFree[a] = false;
			a += step;
		}
	}
	map<int, int> mymap;
	int id = 1;
	for (int i = 1; i <= x; i++){
		if (isCubeFree[i]){
			mymap[i] = id;
			id++;
		}
		else{
			mymap[i] = -1;
		}
	}
	for (int i = 0; i < a.size(); i++){
		int c = mymap[a[i]];
		if (c!= -1){
			cout << "Case " << (i + 1) << ": " << c << endl;
		}
		else{
			cout << "Case " << (i + 1) << ": " << "Not Cube Free" << endl;
		}
	}

	return 0;
}
