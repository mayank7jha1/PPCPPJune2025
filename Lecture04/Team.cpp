#include<iostream>
using namespace std;


int main() {


	int n;
	cin >> n;

	int i = 1;
	int ans = 0;

	while (i <= n) {
		int a, b, c;
		cin >> a >> b >> c;
		int sum = (a + b + c);
		if (sum >= 2) {
			ans = ans + 1;
		}
		i = i + 1;
	}

	cout << ans << endl;








}