/*The Lee algorithm is one possible solution for maze routing problems based on breadth-first search.
  It always gives an optimal solution, if one exists, but is slow and requires considerable memory.
  -"Wiki"
*/

#include <iostream>
#include <queue>
using namespace std;

int n, m,a[1001][1001],b[1001][1001];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

bool inmat(int i, int j) {
    return i >= 1 && i <= n && j >= 1 & j <= m;
}

void lee(int ist, int jst) {
	
	queue<pair<int, int>>Q;
	b[ist][jst] = 1;
	Q.push(make_pair(ist, jst));
	
	while (!Q.empty()) {
		
		pair<int ,int> P = Q.front();
		int x = P.first;
		int y = P.second;
		Q.pop();
		
		for (int i = 0; i <= 3; i++) {
			int inou = dx[i] + x;
			int jnou = dy[i] + y;
			
			if (inmat(inou, jnou) && a[inou][jnou] == 0 && b[inou][jnou] == 0) {
				b[inou][jnou] = b[x][y]+1;
				Q.push(make_pair(inou, jnou));
			}
		}
	}
}
int main(){

	cin >> n >> m; //n rows m columns
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; j++)
            cin >> a[i][j];         

    lee(1, 1);//any valid starting point
	
	for (int i = 1; i <= n; i++, cout << '\n')
		for (int j = 1; j <= m; j++)
            cout << b[i][j]-1 << ' ';
}
/*
    //1 = obstacle 0 = empty space;
    //The algorithm finds the shorthest path to every empty element in matrix from a starting point
Input:       
    4 5   
    0 0 0 0 1
    1 0 1 1 0
    0 0 0 1 0
    1 0 0 0 0
Output:     //-1 = obsacle
    0 1 2 3 -1 
    -1 2 -1 -1 9
    4 3 4 -1 8
    -1 4 5 6 7
*/