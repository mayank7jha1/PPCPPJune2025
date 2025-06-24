#include<iostream>
using namespace std;


int main() {


	//while: Jab tak.

	int n;
	cin >> n;

	int i = 1, ans = 0;

	while (i <= n) {

		int a, b, c;
		cin >> a >> b >> c;


		int sum = a + b + c;

		if (sum >= 2) {
			//This is the problem that you can solve.
			ans = ans + 1;
		}

		i = i + 1;

	}

	cout << ans << endl;








}