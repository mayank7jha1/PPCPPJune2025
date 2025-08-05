#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int directions[4][2] {{ -1, 0}, {1, 0}, {0, 1}, {0, -1}};
char directionLabel[] {'U', 'D', 'R', 'L'};

int n;
char maze[1001][1001];
vector<string>paths;
bool visited[1001][1001] {{0}};


/*
	F(0,0,""):paths from 0,0 where the current path
	is "".

*/

void F(int x, int y, string currentPath) {

	if (x == n - 1 and y == n - 1) {
		paths.push_back(currentPath);
		return;
	}

	if (visited[x][y] == 1) {
		return;
	}

	visited[x][y] = 1;
	for (int i = 0; i < 4; i++) {
		/*
			You are at x, y and you are trying to find
			the new x and y.
		*/
		int nx = x + directions[i][0];
		int ny = y + directions[i][1];

		/*

			x,y :

			1. x+1,y+0   {1,0}
			2. x-1,y+0   (-1,0}
			3. x+0,y+1   {0,1}
			4. x+0,y-1   {0,-1}

		*/

		if (nx >= 0 and ny >= 0 and nx < n and ny < n and
		        visited[nx][ny] == 0) {
			F(nx, ny, currentPath + directionLabel[i]);
			//visited[x][y]=0;
		}
	}

	visited[x][y] = 0;//Backtracking
	return;
}





int main() {

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> maze[i][j];
			if (maze[i][j] == '0') {
				visited[i][j] = 1;
			}
		}
	}

	if (maze[0][0] == '0' or maze[n - 1][n - 1] == '0') {
		cout << "";
		return 0;
	}


	F(0, 0, "");
	sort(paths.begin(), paths.end());

	for (int i = 0; i < paths.size(); i++) {
		cout << paths[i] << " ";
	}
	cout << endl;



}