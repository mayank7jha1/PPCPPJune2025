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
		//You have found a solution and put this current configuration of solution in ans.
		ans.push_back(solution);
		return false;//Change
	}

	//Current We are at F(row) state:
	//For the current row go to every col

	for (int col = 0; col < n; col++) {
		if (IsPossible(row, col, n, solution) == true) {

			/*
				If I can put the queen here I will put it
				and ask recursion to do the rest.
			*/
			solution[row][col] = 'Q';
			bool smalluseless = F(row + 1, solution, ans, n);

			if (smalluseless == 1) {
				return true;
			}

			//When Will I reach here.
			//backtracking
			solution[row][col] = '.';

		}
	}

	//When I am here: If you have iterated over all the columns of the current row you are saying return false to your previous call and asking it to put queen on a diffent column and try to find the solution.
	return false;
}


vector<vector<string>> solveNQueens(int n) {

	vector<vector<string>>ans;//Current we don't have its size why? because we don't knoe for the current n how many possible combinations of board where n queens are there exits.
	vector<string>solution(n);//configuration of the current board.

	//I want to Initialise this solution board with
	//all the values as n.
	string s(n, '.');//Initialise my string with n dots.

	for (int i = 0; i < n; i++) {
		solution[i] = s;
		//when size of solution is not given this use below represention.
		//solution.push_back(s);
	}

	int useless = F(0, solution, ans, n);
	return ans;
}


int main() {
	cin >> n;
	vector<vector<string>>ans = solveNQueens(n);

	for (int i = 0; i < ans.size(); i++) {
		//ans[i]: this is a vector<string>
		for (int j = 0; j < ans[i].size(); j++) {
			//ans[i][j] : this is a string
			cout << ans[i][j] << endl;
		}
		cout << "-------" << endl;
	}

}

/*
	vector<char>v; 1 - D Array hain jisme har index ek char hai.

	vector<string>v: 1 - D Array hain jisme har index ek string hain.
	and kyuki main string par individually iterate kar sakta hu
	I can treat the above as a 2-D Array.

	vector<vector<char>>v: 1 - D Array hain jisme har index ek
	vector hain of char type and this again can be treated as a 2-D Array.

	vector<vector<string>>v: 1-D Array hain jisme har index ek
	vector hai of string type and this can be treated as a 3-D Array.
*/



