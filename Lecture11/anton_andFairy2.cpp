#include<iostream>
using namespace std;


int main() {

	int n, m;
	cin >> n >> m;

	if (n <= m) {
		cout << n << endl;
		return 0;
	}
	int capacity = n;
	int cd = 1;

	while (n >= 0) {

		n -= cd;

		if (n <= 0) {
			break;
		}

		cd++;
		n += m;
		if (n > capacity) {
			n = capacity;
		}
	}

	cout << cd << endl;







}