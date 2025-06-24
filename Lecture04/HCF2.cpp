#include<iostream>
using namespace std;


int main() {

	int a, b;
	cin >> a >> b;

	int i = 1;
	int ans = 0;


	while (i <= b) {

		if ((a % i) == 0 and (b % i) == 0) {
			//This is a Potential ans.
			ans = i;
		}

		i = i + 1;
	}


	cout << ans << endl;







}