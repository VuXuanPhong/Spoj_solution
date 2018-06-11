#include <iostream>
#include <queue>
using namespace std;

int front = 0;
int rear = 0;

struct _pair{
	int value;
	int pos;
};

typedef _pair cap;

cap queu[500];

void enqueue(cap x){
	queu[rear++] = x;
}

cap dequeue(){
	return queu[front++];
}


int maxQueue(){
	int max = queu[front].value;
	for(int i= front+1; i< rear; i++){
		if(queu[i].value > max) max = queu[i].value;
	}
	return max;
}
int main(){
	int t;
	cin >> t;
	for(int i=0; i<t;i++){
		int n,m;
		cin >> n >> m;
		int a;
		for(int i=0; i<n; i++){
			cin >> a;
			cap x;
			x.value = a;
			x.pos = i;
			enqueue(x);
		}
		int time = 0;
		
		int max = maxQueue();
		while(true){
			cap x = dequeue();
			if(x.value == max){
				time++;
				if(x.pos== m) break;
				else max = maxQueue();
			}
			else{
				enqueue(x);
			}
		}
		cout << time << endl;
		front = 0;
		rear = 0;
	}
	return 0;
}