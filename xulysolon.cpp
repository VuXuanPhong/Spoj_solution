#include <iostream>
#include <string>
using namespace std;



int main(){
	string a, b;
	cin >> a >> b;
	int i = a.size() -1;
	int j = b.size() -1;
	string str ="";
	int c = 0;
	while(i>=0 && j>= 0){
		int x = a[i] + b[j] - 96 + c;
		if(x>=10){
			c = x/10;
			x = x%10;
		}else c = 0;
		char ch = x + 48;
		str += ch;
		i--;
		j--;
	}
	if(i>=0){
		while(i>=0){
			int x = a[i] + c - 48;
			if(x >=10){
				c = x/10;
				x = x%10;
			}
			char ch = x + 48;
			str += ch;
			i--;
		}
	}
	
	if(j>=0){
		while(j>=0){
			int x = b[j] + c - 48;
			if(x >=10){
				c = x/10;
				x = x%10;
			}
			char ch = x + 48;
			str += ch;
			j--;
		}
	}
	int temp = str.size() -1;
	for(int k=0; k< str.size()/2;k++){
		char ch = str[k];
		str[k] = str[temp];
		str[temp] = ch;
		temp--;
	}
	i = 0;
	while(str[i] == 48) i++;
	for(;i<str.size();i++) cout << str[i];
}
