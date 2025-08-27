#include<iostream>
#include<map>
#include<unordered_map>
using namespace std;


int main() {

	map<string, int>mp;
	unordered_map<string, int>ump;

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {

		string s;
		int x;
		cin >> s >> x;

		pair<string, int>p{s, x};
		//pair<string, int>p1 = make_pair(s, x);

		//Insertion
		// mp.insert(p);
		// mp.insert(make_pair(s, x));
		// mp.insert({s, x});
		ump.insert({s, x});


		//Initially if a key is not present in map its default value in map will be 0.
		//Updation:
		mp[s] = x;
	}



	for (map<string, int>::iterator it = mp.begin(); it != mp.end(); it++) {
		cout << (*it).first << " " << it->second << endl;
	}

	cout << endl << "---------------------" << endl;

	for (pair<string, int> x : ump) {
		cout << x.first << " " << x.second << endl;
	}


	cout << mp["Mayank"] << endl;



	if (mp.count("Mayank") == 1) {
		cout << "yes" << endl;
	} else {
		cout << "no" << endl;
	}


	if (mp.find("Mayank") != mp.end()) {
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}

	mp.clear();




}