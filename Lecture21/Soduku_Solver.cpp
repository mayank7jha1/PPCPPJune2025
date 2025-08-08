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

	//Currently We are solving for the state F(row,col):
	//Try putting numbers from 1 to 9 in board of row,col

	for (char number = '1'; number <= '9'; number++) {

		if (IsPossible(board, row, col, number) == true) {
			board[row][col] = number;
			int smalluseful = F(board, row, col + 1);

			if (smalluseful == 1) {
				return true;
			}

			//If I am Standing Here: I asked recursion to
			//solve the rest of the soduku by putting a
			//number at board[row][col] and recursion is
			//saying I am not able to solve soduku using
			//the current number at board[row][col].

			//backtracking
			board[row][col] = '.';
		}
	}


	//If I am standing here that means for board[row][col]
	//I tried putting numbers from 1 to 9 and I was not
	//able to put any number why because I had I would
	//have returned true from line 35 and never reach her.
	return false;

}

void solveSudoku(vector<vector<char>>& board) {
	bool useless = F(board, 0, 0);
	return;
}


int main() {









}