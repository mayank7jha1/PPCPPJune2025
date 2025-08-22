#include<iostream>
#include<forward_list>
#include<list>
using namespace std;


int main() {

	int n;
	cin >> n;

	forward_list<int>f;
	list<int>l;

	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;

		f.push_front(x);
		l.push_front(x);
		l.push_back(x);
	}


	f.pop_front();
	l.pop_front();
	l.pop_back();

	f.sort();

}