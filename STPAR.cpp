#include <iostream>
#include <stack>
using namespace std;

int a[1001];
int b[1001];
int main(){
	while (true){
		int n;
		cin >> n;
		if (n == 0) break;
		int min = 0;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			b[i] = a[i];
		}
		for (int i = 0; i < n - 1; i++){
			for (int j = i; j < n; j++){
				if (b[i] > b[j]){
					int temp = b[i];
					b[i] = b[j];
					b[j] = temp;
				}
			}
		}
		stack<int> st;
		int id = 0;
		bool sol = true;
		for (int i = 0; i < n; i++){
			if (!st.empty()){
				while (st.top() == b[id]){
					st.pop();
					id++;
					if (st.empty()) break;
				}
			}
			if (a[i] == b[id]){
				id++;
				continue;
			}
			else{
				if (st.empty()) st.push(a[i]);
				else{
					if (a[i] > st.top()) {
						sol = false;
						break;
					}
					st.push(a[i]);
				}
			}
		}
		if (sol) cout << "yes" << endl;
		else cout << "no" << endl;
	}

	return 0;
}