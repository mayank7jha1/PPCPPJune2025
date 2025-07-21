#include<iostream>
using namespace std;

const int n = 3, m = 5;


void F(int (*a)[m]) {

	// for (int i = 0; i < n; i++) {
	// 	for (int j = 0; j < m; j++) {
	// 		cout << a[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }
}


int main() {

	int a[][5] {{1, 2, 3, 1}, {3, 42, 1, 3, 1}};
	F(a);
}