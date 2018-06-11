#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
	int t;
	cin >> t;
	for (int i = 0; i < t; i++){
		int n;
		cin >> n;
		getchar();
		map<string, int> mymap;
		map<string, int>::iterator it;
		for (int j = 0; j < n; j++){
			string str = "";
			getline(std::cin,str);
			mymap[str]++;
		}
		
		for (it = mymap.begin(); it != mymap.end();it++){
			cout << it->first << " " << it->second;
			cout << endl;
		}
	}
	return 0;
}
