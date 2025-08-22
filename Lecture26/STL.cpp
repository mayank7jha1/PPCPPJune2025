#include<iostream>
#include<forward_list>//Singly Linked List
#include<list>//Doubly Linked List
using namespace std;


void Solve(forward_list<int>&d) {

}

void Solve1(list<int>&p) {

}

forward_list<int>Solve2(int x) {

}

list<int>Solve3(int x) {

}




int main() {
	forward_list<int>f{1, 2, 3, 4, 5};
	list<int>l{5, 4, 1, 5, 6, 7};

	forward_list<int>f1 = f;
	list<int>l1 = l;

	Solve(f);
	Solve1(l);

	// vector<list<int>>v;
	// list<vector<int>>l5;



	for (forward_list<int>::iterator it = f.begin(); it != f.end(); it++) {
		cout << (*it) << " ";
	}

	cout << endl;

	for (list<int>::iterator it = l.begin(); it != l.end(); it++) {
		cout << (*it) << " ";
	}
	cout << endl;

	for (int x : f) {
		cout << x << " ";
	}

	cout << endl;
	for (int x : l) {
		cout << x << " ";
	}





}