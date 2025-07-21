#include<iostream>
#include<vector>
using namespace std;


int main() {

	// int a[10];
	//Array of vector
	//vector<int>b[10];

	//b[i]: It is a vector


	//vector<int>a[10] {{1, 2, 5}, {2, 3, 4, 5, 5, 5, 6, 6, 6},};

	int n, m;
	cin >> n >> m;

	//Array of vector: you can use variable length columns.
	vector<int>b[10];

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < m; j++) {
			// cin >> b[i][j];
			int x;
			cin >> x;
			b[i].push_back(x);
		}
	}

	// vector<string>b[10];







}