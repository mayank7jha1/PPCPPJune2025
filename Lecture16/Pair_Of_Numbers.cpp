#include<iostream>
using namespace std;
int target;

/*
	F(x,y): Min Steps from x,y to target.

*/

int F(int x, int y) {
	//Currently We are Solving for F(x,y);

	//Stoping Point:
	if (x > target or y > target) {
		return 1e8;
	}

	if (x == target or y == target) {
		return 0;
	}
	int Op1 = F(x + y, y);
	int Op2 = F(x, y + x);
	int ans = 1 + min(Op1, Op2);
	return ans;
}

int main() {

	cin >> target;
	cout << F(1, 1); //Starting point.
}