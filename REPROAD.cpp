#include <iostream>
using namespace std;

int road[10002];

int main(){
	int t;
	cin >> t;
	for(int i=0;i <t;i++){
		int n,k;
		cin >> n >> k;
		if(n<5 || n>10000) break;
		for(int i=0; i<n; i++){
			cin >> road[i];
		}
		int left = 0;
		int right = 0;
		int dem = 0;
		int length = 0;
		while (right < n)
		{
			if(road[right] ==0){
				if(dem == k){
					int max = right - left;
					if(max > length) length = max;
					while(dem == k){
						if(road[left] == 0) dem--;
						left++;
					}
				}
				dem++;
			}
			if(right == n -1){
					int max = right - left+1;
					if(max > length) length = max;
			}
			right++;
		}
		cout << length << endl;
	}

	return 0;
}