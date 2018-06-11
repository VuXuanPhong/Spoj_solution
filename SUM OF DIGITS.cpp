#include <iostream>
#include <string>
using namespace std;

int main(){
	int t;
	cin >> t;
	for(int i=0; i<t;i++){
		string str = "";
		cin >> str;
		int sum = 0;
		for(int i=0; i<str.size(); i++){
			sum += str[i] - 48;
		}		
		cout << sum << endl;
	}
	return 0;
}
