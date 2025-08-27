#include<iostream>
#include<set>
#include<unordered_set>
using namespace std;

int main() {

	set<int>s;
	unordered_set<int>us;

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		s.insert(x);
		us.insert(x);
	}



	for (set<int>::iterator it = s.begin(); it != s.end(); it++) {
		cout << (*it) << " " << (*it) << endl;
	}

	cout << endl << "---------------------" << endl;

	for (int x : ump) {
		cout << x << endl;
	}


	if (s.count("Mayank") == 1) {
		cout << "yes" << endl;
	} else {
		cout << "no" << endl;
	}


	if (s.find("Mayank") != s.end()) {
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}

	// s.lower_bound();
	//s.upper_bound();

}


// 1 1 1 1 2 2 3 2 2 1 2 3 4 5 5 6 1 2 4 5

// sort();//nlogn
// unique find karte: //n



