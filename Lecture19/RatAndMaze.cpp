#include<iostream>
using namespace std;
int n, m;
char maze[1001][1001];
bool visited[1001][1001] {{0}};
bool solution[1001][1001] {{0}};

//visited[i][j]=1 that means I cannot visit i,j.

bool F(int i, int j) {

	//Stopping Point:
	if (i == n - 1 and j == m - 1) {
		//You have found a path.
		solution[i][j] = 1;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cout << solution[i][j] << " ";
			}
			cout << endl;
		}
		return true;
	}


	//Currently I am at i,j.
	if (visited[i][j] == 1) {
		return false;
	}

	//If I am standing here this is a unvisited box.
	visited[i][j] = 1;
	solution[i][j] = 1;


	//I will try to find the right path first.
	if (j + 1 <= m - 1 and visited[i][j + 1] == 0) {
		bool rightans = F(i, j + 1);
		if (rightans == 1) {
			return true;
		}
	}

	//If I am standing here.
	//I will try to find the down path now.
	if (i + 1 <= n - 1 and visited[i + 1][j] == 0) {
		bool downans = F(i + 1, j);
		if (downans == 1) {
			return true;
		}
	}

	//If you are standing here this means right and
	//down from i,j doesn't exist.
	solution[i][j] = 0;//backtracking
	return false;
}




int main() {

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> maze[i][j];

			if (maze[i][j] == 'X') {
				visited[i][j] = 1;
			}
		}
	}

	bool ans = F(0, 0);

	if (ans == 0) {
		cout << "-1" << endl;
	}

}