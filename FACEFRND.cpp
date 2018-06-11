#include <iostream>
#include <map>
using namespace std;

int main(){
	int N;
	cin >> N;
	map<int, int> mymap;
	for (int i = 0; i<N; i++){
		int idfr;
		cin >> idfr;
		mymap[idfr] = -1;
		int m;
		cin >> m;
		for (int j = 0; j<m; j++){
			int idfrOffr;
			cin >> idfrOffr;
			if (mymap[idfrOffr] != -1) mymap[idfrOffr] = 1;
		}
	}
	int count = 0;
	map<int, int>::iterator it;
	for (it = mymap.begin(); it != mymap.end(); it++){
		if (it->second == 1) count++;
	}
	cout << count << endl;

	return 0;
}
