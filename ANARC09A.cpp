#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(){
	int t = 1;
	while (true){
		string str;
		cin >> str;
		bool b = false;
		for (int i = 0; i< str.size(); i++){
			if (str[i] == '-') {
				b = true;
				break;
			}
		}
		if (b) break;
		stack<char> st;
		int n = str.size();
		int dem = 0;
		for (int i = 0; i < n; i++){
			if (str[i] == '}'){
				if (st.empty()){	
					st.push('{');
					if (i == n - 1) break;
					dem++;
				}
				else if (st.top() == '{') st.pop();
			}
			else{
				st.push('{');
			}
		}
		if (st.size() % 2 == 0){
			dem += st.size() / 2;
		}
		else{
			dem += ((st.size()-1) / 2) + 1;
		}
		cout << t << ". " <<  dem << endl;
		t++;
	}

	return 0;
}