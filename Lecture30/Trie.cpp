#include<iostream>
#include"../Header_Files/Trie.h"
using namespace std;


int main() {
	int n;
	cin >> n;
	Trie t;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		t.insert(s);
	}

	int q;
	cin >> q;



	while (q--) {
		string input;
		cin >> input;
		cout << t.search(input) << endl;
	}
	string str = "Maya";
	cout << t.shortestUniquePrefix(str) << endl;


}