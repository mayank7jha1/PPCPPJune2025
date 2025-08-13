#include<iostream>
#include<vector>
using namespace std;


bool compare(pair<string, int>p1, pair<string, int>p2) {

	if (p1.second > p2.second) {
		return true;
	} else {
		return false;
	}

}

int main() {

	int n;
	cin >> n;
	vector<pair<string, int>>v;
	for (int i = 0; i < n; i++) {
		string s;
		int m;
		cin >> s >> m;
		// pair <string, int>p = make_pair(s, m);
		// v.push_back(p);
		v.push_back({s, m});
	}


	//Iteration using an iterator
	for (vector < pair<string, int>::iterator it = v.begin(); it != v.end(); it ++) {
		cout << (*it).first << " " << it->second << endl;
	}

	//Using For each loop

	/*
		For Every element of this container v that is going to be represented
		as x do this task:
	*/
	for (pair<string, int> x : v) {
		cout << x.first << " " << x.second << endl;
	}


	//Asc. Order:
	// sort(v.begin(), v.end(), compare);

	// //This is an array of pair type.
	// //Every a[i] will again be a pair.
	// pair<string, int>ps[10];

	// for (int i = 0; i < n; i++) {
	// 	cin >> a[i].first >> a[i].second;
	// }

	// sort(a, a + n);



}
