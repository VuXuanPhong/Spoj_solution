#include <iostream>
#include <string>

using namespace std;

int main(){
	string str = "";
	getline(std::cin, str);
	while (str != "") {
		if (str.size() == 1 && (str[0]==48||str[0]==49)) {
			cout << str[0] << endl;
			getline(std::cin, str);
			continue;
		}
		string x2 = "";
		int carry = 0;
		for (int i = str.size()-1; i >=0; i--){
			int a = str[i] + str[i] - 96 +carry;
			if (a >= 10){
				carry = a / 10;
				a = a % 10;
			}
			else carry = 0;
			char c = a + 48;
			x2 = c + x2;
		}
		if (carry > 0) x2 = (char)(carry + 48) + x2;
		int n = x2.size() - 1;
		if (x2[n] < 50) {
			x2[n] = x2[n] + 10 - 2;
			n--;
			while (x2[n] < 49){
				x2[n] = x2[n] + 10 - 1;
				n--;
			}
			x2[n] = x2[n]  - 1;
		}
		else x2[n] = x2[n] - 2;
		int i = 0;
		while (x2[i] == 48) i++;
		for (; i < x2.size(); i++) cout << x2[i];
		cout << endl;
		getline(std::cin, str);
	}
	return 0;
}
