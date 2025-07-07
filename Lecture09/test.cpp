#include<iostream>
#include<set>
using namespace std;


int main() {

	srand(time(0));

	int n = 1 + rand() % 10001;
	//cout << n << endl;
	set<int>s;
	for (int i = 0; i < n; i++) {
		s.insert(2 + rand() % 10001);
	}
	cout << s.size() << endl;
	for (auto x : s) {
		cout << x << " ";
	}








}