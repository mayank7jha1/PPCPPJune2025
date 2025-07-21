#include<iostream>
#include<vector>
#include<string>
using namespace std;


int main() {

	//Vector of String:
	vector<string>v;

	//Every index of this dynamic array/vector
	//will be a string.

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string x;
		cin >> x;
		v.push_back(x);
		// cin >> v[i];
	}

	cout << v[2][1] << endl;



}








