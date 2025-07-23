#include<iostream>
using namespace std;
int x, y;


/*
	F(i): I want to multiply x, i se y tak and return its value.
	Here y can only be positive.
*/


int F(int i) {

	//Currently I am solving for F(i) state

	//Ending Point:Base Condition
	if (i == y) {
		//I am calculating for F(y) state.
		//I am directly returning the value for F(y).
		return x;
	}

	//Task and Next State.
	//This variable answer is for calculating F(i) only.

	//I am first calculating answer and then returning it.
	int ans = x * F(i + 1);


	return ans;
}



int main() {

	cin >> x >> y;
	cout << F(1) << endl;
	int ans1 = F(1); //Starting Point
	cout << ans1 << endl;
}