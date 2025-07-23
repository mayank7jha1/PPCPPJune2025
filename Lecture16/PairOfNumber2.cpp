#include<iostream>
using namespace std;

/*
	F(x,y,count): Min Steps from x,y to 1,1 where
	the current path has taken count number of
	steps.

	count: Current Path me kitne steps lage hain.

	Min_steps: Min steps across all the path jo
	mujhe lage hain.
*/

int Min_Steps = INT_MAX;

void F(int x, int y, int count) {

	if (x == 1 and y == 1) {
		Min_Steps = min(count, Min_Steps);
		return;
	}

	if (x - y > 0) {
		F(x - y, y, count + 1);
	}

	if (y - x > 0) {
		F(x, y - x, count + 1);
	}
	return;
}

void Solve(int tar) {

	for (int i = 1; i <= (tar - 1); i++) {
		F(i, tar - i, 1);
	}

	return;
}

int main() {
	int tar;
	cin >> tar;
	Solve(tar);
	cout << Min_Steps << endl;
}


