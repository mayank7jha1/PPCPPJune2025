#include<iostream>
using namespace std;


int main() {



	int n;
	cin >> n;

	//this is an array of string.
	string s[n];
	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}

	//sort(s, s + n);

	//This is string
	for (int i = 0; i < n; i++) {
		// cout << s[i] << " ";
		sort(s[i].begin(), s[i].end());
	}

	for (int i = 0; i < n; i++) {
		cout << s[i] << " ";
	}






}