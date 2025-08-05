#include<iostream>
using namespace std;
const int N = 10;
int dx[] {1, 1, 2, 2, -1, -1, -2, -2};
int dy[] { -2, 2, 1, -1, 2, -2, -1, 1};
int n;
int grid[N][N] {{0}};
int Total_Boxes = 0;

void Input() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> grid[i][j];
			if (grid[i][j] == 1) {
				Total_Boxes++;
			}
		}
	}
}

int ans = -1;
void F(int x, int y, int count) {
	ans = max(count, ans);

	//grid[x][y] = 0;

	for (int i = 0; i < 8; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx >= 0 and nx<N and ny >= 0 and ny < N and
		        grid[nx][ny] == 1) {

			grid[nx][ny] = 0;//visited[nx][ny]=1
			F(nx, ny, count + 1);

			//when I am at line 37 that means F(nx,ny,count+1) is solved.
			//F(nx,ny,count)
			grid[nx][ny] = 1;//visited[ny][ny]=0;

		}
	}

	//grid[x][y] = 1;
	//If I am Standing here that means F(x,y,count) is Solved.
}


int main() {
	cin >> n;
	Input();

	if (grid[0][0] == 0) {
		cout << "No Solution Exists" << endl;
		return 0;
	}

	grid[0][0] = 0;
	F(0, 0, 1);
	cout << Total_Boxes - ans << endl;
}




