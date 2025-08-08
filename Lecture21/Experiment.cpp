#include<iostream>
#include<vector>
#include<string>
using namespace std;


int main() {

	int n;
	cin >> n;
	vector<string>v;

	// v[0]: It is a string:

	for (int i = 0; i < n; i++) {
		string s = "";
		for (int j = 0; j < n; j++) {
			s.push_back('.');
		}
		v.push_back(s);
	}

	for (int i = 0; i < n; i++) {
		cout << v[i] << endl;
	}


}

