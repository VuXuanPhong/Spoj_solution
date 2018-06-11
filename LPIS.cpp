#include <iostream>
#include <map>
#include <algorithm>
#include <stdlib.h>
using namespace std;

int* arr0 = NULL;

int main(){
	long n;
	cin >> n;
	std::multimap<int, int> arr;
	std::multimap<int, int>::iterator it = arr.begin();
	arr0 = new int[1000005];
	for (int i = 0; i < 1000005; i++) arr0[i] = 0;
	int x;
	for (long i = 0; i<n; i++){
		cin >> x;
		arr.insert(std::pair<int, int>(x, i));
		arr0[x]++;
	}
	int max = 1;
	it = arr.begin();
	int preValue = (it->first) - 1;
	int preId = (it->second) - 1;
	int count = 0;
	for (it = arr.begin(); it != arr.end(); it++){
		int value = it->first;
		int id = it->second;
		if (value - preValue == 1){
			bool is = false;
			while (true){
				if (it->second > preId){
					is = true;
					arr0[value]--;
					break;
				}
				arr0[value]--;
				if (arr0[value] == 0) break;
				it++;
			}
			if (is){
 				count++;
				preValue = value;
				preId = it->second;
			}
			else{
				if (count > max) max = count;
				preValue = value;
				preId = id;
				count = 1;
			}
			while(arr0[value] != 0){
				it++;
				arr0[value]--;
			}
		}
		else{
			if (count > max) max = count;
			preValue = value;
			preId = id;
			count = 1;
		}
		
	}
	if (count > max) max = count;
	cout << max;
	cout << endl;
	return 0;
}
