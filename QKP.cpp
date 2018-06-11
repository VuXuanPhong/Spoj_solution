#include <iostream>
#include <vector>
using namespace std;

struct point{
	int x;
	int y;
};

int broad[1001][1001];
int n,m;
int kx[8] ={-2,-1,1,2,2,1,-1,-2};
int ky[8] = {-1,-2,-2,-1,1,2,2,1};

int qx[8] ={-1,0,1,1,1,0,-1,-1};
int qy[8] ={-1,-1,-1,0,1,1,1,0};

int safe = 0;

void knightGo(int x, int y){
	for(int i=0; i<8;i++){
		int x1 = x + kx[i];
		int y1 = y + ky[i];
		if(x1 < 0 || x1 >= m || y1 <0 || y1 >= n) continue;
		if(broad[y1][x1]==0) {
			safe -= 1;
			broad[y1][x1] = 4;
		}
	}
}

void queenGo(int x, int y, int i){
		int x1 = x+qx[i];
		int y1 = y+qy[i];
		if(x1 < 0 || x1 >= m || y1 <0 || y1 >= n) return;
		if(broad[y1][x1] == 1 || broad[y1][x1] == 3 || broad[y1][x1] == 2) return;
		else if(broad[y1][x1] == 0){
			broad[y1][x1] = 5;
			safe -= 1;
			queenGo(x1,y1,i);
		}
		else if(broad[y1][x1] == 4|| broad[y1][x1] == 5) queenGo(x1,y1,i);
}
int main(){
	int t = 1;
	while (true)
	{
		cin >> n >> m;
		if(n==0|| m ==0) break;
		safe = n*m;
		int queens, knights, pawns;
		vector<point> queen,knight,pawn;
		cin >> queens;
		for(int i =0; i< queens; i++){
			int row, col;
			cin >> row >> col;
			point p;
			p.x = col -1;
			p.y = row -1;
			queen.push_back(p);
			broad[row-1][col-1] = 1;
		}
		cin >> knights;
		for(int i =0; i< knights; i++){
			int row, col;
			cin >> row >> col;
			point p;
			p.x = col -1;
			p.y = row - 1;
			knight.push_back(p);
			broad[row-1][col-1] = 2;
		}
		cin >> pawns;
		for(int i =0; i< pawns; i++){
			int row, col;
			cin >> row >> col;
			broad[row-1][col-1] = 3;
		}
		safe = safe - queens - knights - pawns;
		for(int i=0; i<knight.size();i++){
			knightGo(knight[i].x,knight[i].y);
		}
		for(int k =0; k<8; k++){
			for(int i=0;i<queen.size();i++){
				queenGo(queen[i].x,queen[i].y,k);
			}
		}
		cout << "Board " << t<<" has " << safe<< " safe squares." << endl;
		t++;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				broad[i][j] = 0;
			}
		}
	}
	return 0;
}