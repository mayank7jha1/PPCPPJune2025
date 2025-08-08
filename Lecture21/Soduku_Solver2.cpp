#include<iostream>
#include <vector>
using namespace std;

bool IsPossible(vector<vector<char>>& board, int x, int y, char number) {

	//Check Row:
	for (int col = 0; col < 9; col++) {
		if (board[x][col] == number) {
			return false;
		}
	}

	//Check Column
	for (int row = 0; row < 9; row++) {
		if (board[row][y] == number) {
			return false;
		}
	}

	//Check Sub-Matrix
	int sx = (x / 3) * 3;
	int sy = (y / 3) * 3;

	for (int r = sx; r <= sx + 2; r++) {
		for (int c = sy; c <= sy + 2; c++) {
			if (board[r][c] == number) {
				return false;
			}
		}
	}

	return true;
}

bool F(vector<vector<char>>& board, int row, int col) {

	//Stopping Point:
	if (row == 9) {
		//We have found a solution
		return true;
	}

	if (col == 9) {
		//I have filled the current row.
		return F(board, row + 1, 0);
	}

	//Skip the boxes where there are numbers.
	if (board[row][col] != '.') {
		return F(board, row, col + 1);
	}

	for (char number = '1'; number <= '9'; number++) {

		if (IsPossible(board, row, col, number) == true) {
			board[row][col] = number;
			int smalluseful = F(board, row, col + 1);

			if (smalluseful == 1) {
				return true;
			}

			board[row][col] = '.';
		}
	}
	return false;

}

void solveSudoku(vector<vector<char>>& board) {
	bool useless = F(board, 0, 0);
	return;
}


int main() {


}



