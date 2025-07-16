#include<iostream>
using namespace std;


int main() {

	string s{"Mayank"};

	//begin(): It returns the address of the first block of the container.
	//end() : It returns the address of the last block + 1 of the container.

	sort(s.begin(), s.end());
	reverse(s.begin(), s.end());
	cout << s << endl;

	cout << *max_element(s.begin(), s.end()) << endl;

	//auto *p = max_element(s.begin(), s.end());




}