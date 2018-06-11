#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

char toanTu[] = { '+', '-', '*', '/', '^','\0' };

int doUuTien(char c){
	for (int i = 0; i < 5; i++){
		if (c == toanTu[i]) return i;
	}
	return -1;
}
 
vector<char> onp(string s){
	stack<char> st;
	vector<char> forReturn;
	for (int i = 0; i < s.length(); i++){
		char c = s[i];
		if (c == '(') {
			st.push(c);
			continue;
		}
		if (c >= 'a' && c <= 'z'){
			forReturn.push_back(c);
			continue;
		}
		if (c == ')'){
			while (st.top() != '('){
				forReturn.push_back(st.top());
				st.pop();
			}
			st.pop();
			continue;
		}

		if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^'){
			if (st.top() == '(') st.push(c);
			else{
				int x = doUuTien(c);
				int y = doUuTien(st.top());
				if (x <= y){
					while (x <= y){
						forReturn.push_back(c);
						st.pop();
						y = doUuTien(st.top());
					}
				}
				if (x > y) st.push(c);
			}
			continue;
		}
		if (i == s.length() - 1){
			while (!st.empty()){
				forReturn.push_back(st.top());
				st.pop();
			}
		}
	}
	return forReturn;
}

void printVector(vector<char> c){
	for (int i = 0; i < c.size(); i++){
		cout << c.at(i);
	}
	cout << endl;
}

int main(){
	int testCase = 1;
	cin >> testCase;
	vector<string> listString;
	for (int i = 0; i < testCase; i++){
		string s;
		cin >> s;
		listString.push_back(s);
	}

	for (int i = 0; i < testCase; i++){
		printVector(onp(listString.at(i)));
	}

	return 0;
}