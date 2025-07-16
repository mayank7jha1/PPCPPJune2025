#include<iostream>
using namespace std;


int main() {

	// string a[10];
	// //Every index of this array a will contain
	// // a string.

	// //This is a string.
	// cout << a[0] << endl;

	int n;
	cin >> n;

	//this is an array of string.
	string s[n];
	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}



	//This is string
	for (int i = 0; i < n; i++) {
		cout << s[i] << " ";
	}

	//Character
	cout << s[2][1] << endl;








}