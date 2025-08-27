#include<iostream>
#include<map>
#include<set>
using namespace std;


int main() {

	multimap<string, int>mp;
	multiset<int>ms;

	// //pair<index,string>
	// //pair<string,index>

	// map<pair<int, string>, int>mp1;
	// map<pair<string, int>, int>mp2;


	// map<vector<string>, int>mp3;
	// map<string, vector<int>>mp;

	// map<int, map<string, int> >> mp4;

	map<pair<int, string>, int>mp1;
	map<int, string>mp6;

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		int x;
		cin >> s;
		cin >> x;
		mp6.insert({x, s});
		mp1.insert({i, x})

		// mp2.insert({{s, i}, x});
		// mp.insert({s, x});
	}

	for (pair<int, string> x : mp6) {
		cout << x.first << " " << x.second << endl;
	}


	// cout << mp["Mayank"] << endl;

	// //Range Iteration

	// if (mp.count("Mayank") > 0) {
	// 	cout << "Yes" << endl;
	// } else {
	// 	cout << "No" << endl;
	// }

	// if (mp.find("Mayank") != mp.end()) {
	// 	cout << "Yes";
	// }


	// for (pair<pair<string, int>, int> x : mp2) {
	// 	cout << x.first.first << " " << x.second << endl;
	// }


}

