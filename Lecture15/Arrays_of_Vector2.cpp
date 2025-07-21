#include<iostream>
#include<vector>
using namespace std;


/*

	It is a array of vector<char>
	vector<char>b[10];

	Meaning: It is a vector.
	b[i]


	5
	Mayank
	Atul
	Aman
	Aditya
	Sarthak
*/




int main() {

	int n;
	cin >> n;
	vector<char>v[n];

	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < str.length(); j++) {
			v[i].push_back(str[j]);
		}
	}







}







