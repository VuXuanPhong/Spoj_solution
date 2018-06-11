#include <iostream>
#include <string>
using namespace std;

int main(){
	while(true){
		string str;
		cin >> str;
		if(str.compare("*") == 0) break;
		int n = str.size();
		int sz = 1;
		for(int i=1;i<= n; i++){
			if(n%i !=0) continue;
			if(i==n) continue;
			int k = n/i;
			string s = ""; 
			string s1 = "";
			for(int j=0; j<i;j++){
				s.push_back(str[j]);
			}
			for(int j=0; j<k;j++){
				s1 += s;
			}
			if(s1.compare(str) == 0){
				sz = k;
				break;
			}
		}
		
		cout << sz << endl;
	}
	
	return 0;
}