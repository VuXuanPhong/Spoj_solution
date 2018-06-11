#include <iostream>
#include <string>
#include <vector>
#include <math.h>
using namespace std;

vector<string> solution;
vector<string> strs;

bool UCV(string str){
	if(solution.size()==0) return true;
	for(int i=0; i<solution.size();i++){
		if(str==solution[i]) return false;
	}
	int sz1 = solution.size() -1;
	string s = solution[sz1];
	int count = 0;
	for(int i=0; i<s.size();i++){
		count+= abs(s[i]-str[i]);
	}
	if(count!=1) return false;
	return true;
}

bool TRY(int i){
	for(int j=0; j<strs.size();j++){
		if(UCV(strs[j])){
			solution.push_back(strs[j]);
			if(solution.size() == strs.size()) return true;
			else TRY(i+1);
		}
	}
}


int main(){
	string a;
	while(true){
		cin >> a;
		if(a=="_") break;
		strs.push_back(a);
	}
	cout << TRY(0) << endl;
	return 0;
}
