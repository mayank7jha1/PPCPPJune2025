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


/*
	F(0,0) : Maximum Boxes where the knight
	is able to move in a single path.
	This means F(0,0) would be returning a
	integer value to me.


	F(x,y,count): No of steps from 0,0 to
	x,y is count.
	This function doesn't need to return anything.

	I can just maintain a global answer
	to store the maximum count.

*/

int ans = -1;


void F(int x, int y, int count) {

	/*
		Currently We are at the point x,y
		and we have taken steps count to reach
		x,y.
	*/

	//Since we don't know the stopping point
	//we can just calculate my answer
	//as recursion will automatically stop
	// for x,y after 8 calls.
	ans = max(count, ans);


	//Check if the current x,y is valid or not.
	// if (grid[x][y] == 0) {
	// 	return;
	// }

	//You don't need to write the above
	//statement as you are only going to a
	//valid box.

	for (int i = 0; i < 8; i++) {

		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx >= 0 and nx<N and ny >= 0 and ny < N and
		        grid[nx][ny] == 1) {

			grid[nx][ny] = 0;
			F(nx, ny, count + 1);

			//Backtracking
			grid[nx][ny] = 1;//Why
			//Because I can revisit this
			//box again from a
			//different path.
		}
	}
}




int main() {
	cin >> n;
	Input();

	/*
		I am currently at 0,0 and mere har
		path me ye 0,0 as a point hoga and hence
		main is 0,0 ko dubara kabhi visit nahi
		kar sakta and ye count me bhi aayega.
	*/


	/*
		Recursion on Grid me you can maintain
		a visited array but you should avoid it
		because you can visualise your input
		array as your visited only.

		How:

		Input:
		grid[x][y]=1 that means I can visit this box.
		grid[x][y]=0 that means I cannot visit this box.

		since mujhe isse me visited maintain karna hain
		so main jaise hi kisi box par jaaunga
		main us box ko visited mark kardunga as
		in main us box par dubara visit nahi kar
		sakta in my current path and i can achieve this
		by making grid[x][y]=0;

	*/

	if (grid[0][0] == 0) {
		cout << "No Solution Exists" << endl;
		return 0;
	}

	//Preassuming there exists a solution.
	grid[0][0] = 0;
	F(0, 0, 1);

	// Above statement means my 0, 0 will always be part of
	// solution hence count's starting value is 1.
	cout << Total_Boxes - ans << endl;


}




