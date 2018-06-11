#include <iostream>
#include <map>
#include <vector>
using namespace std;

int frds[8];

int main(){
	for(int i=0; i<8; i++){
		cin >> frds[i];
	}
	int p;
	cin >> p;
	vector< pair<int,int> > relate;
	for(int i=0; i<p ;i++){
		int m,n;
		cin >> m >> n;
		relate.push_back(std::make_pair(m-1,n-1));
	}
	int max = 0;
	for(int i=255; i>=0;i--){
		int bits[8];
		int id = 0;
		int x = i;
		while(id < 8){
			int b = x%2;
			x = x/2;
			bits[id] = b;
			id++;
		}
		bool good = true;
		for(int j =0; j<relate.size();j++){ 
			if(bits[relate[j].first] == bits[relate[j].second]){
				good = false;
				break;
			}
		}
		if(good){
			int m = bits[0]*frds[0] + bits[1]*frds[1] + bits[2]*frds[2] + bits[3]*frds[3]
			+ bits[4]*frds[4] + bits[5]*frds[5] + bits[6]*frds[6] + bits[7]*frds[7];
			if(m > max) max = m;
		}
	}
	cout << max << endl;
	return 0;
}
