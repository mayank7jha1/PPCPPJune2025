#include<iostream>
#include<vector>
using namespace std;
int n;

bool IsPossible(int x, int y, int n, vector<string>&solution) {

	//Row Wise Check (Useless)
	for (int col = 0; col < y; col++) {
		if (solution[x][col] == 'Q') {
			return false;
		}
	}

	//Column Wise check
	for (int row = 0; row < x; row++) {
		if (solution[row][y] == 'Q') {
			return false;
		}
	}

	//Main Diagonal Check
	int i = x, j = y;
	while (i >= 0 and j >= 0) {
		if (solution[i][j] == 'Q') {
			return false;
		}
		i--, j--;
	}

	// or : ||

	//Secondary Diagonal Check
	i = x, j = y;
	while (i >= 0 and j < n) {
		if (solution[i][j] == 'Q') {
			return false;
		}
		i--, j++;
	}

	return true;
}


bool F(int row, vector<string>&solution, vector<vector<string>>&ans, int n) {

	if (row == n) {
		ans.push_back(solution);
		return false;//Change
	}

	for (int col = 0; col < n; col++) {
		if (IsPossible(row, col, n, solution) == true) {
			solution[row][col] = 'Q';
			bool smalluseless = F(row + 1, solution, ans, n);
			if (smalluseless == 1) {
				return true;
			}

			solution[row][col] = '.';

		}
	}

	return false;
}


/*
	void F(int row, vector<string>&solution, vector<vector<string>>&ans, int n) {

		if (row == n) {
			ans.push_back(solution);
			return;
		}

		for (int col = 0; col < n; col++) {
			if (IsPossible(row, col, n, solution) == true) {
				solution[row][col] = 'Q';
				F(row + 1, solution, ans, n);
				solution[row][col] = '.';

			}
		}

		return;
	}

*/

vector<vector<string>> solveNQueens(int n) {

	vector<vector<string>>ans;
	vector<string>solution(n);
	string s(n, '.');

	for (int i = 0; i < n; i++) {
		solution[i] = s;
	}

	int useless = F(0, solution, ans, n);
	return ans;
}


int main() {
	cin >> n;
	vector<vector<string>>ans = solveNQueens(n);

	for (int i = 0; i < ans.size(); i++) {
		for (int j = 0; j < ans[i].size(); j++) {
			cout << ans[i][j] << endl;
		}
		cout << "-------" << endl;
	}

}


