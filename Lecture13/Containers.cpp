#include<iostream>
#include<string>
using namespace std;



int main() {
	// int x;
	// char ch[100];
	// string st;
	// cin >> st;

	// string p = "Mayank";
	// string s{"Samyak"};

	// string gh = "s";
	// string pr = 's';

	// int a[] {4, 3, 2, 15};
	// cout << a << endl;
	// int *ptr = a;

	// string st1 = "Mayank";
	// string *ptr = st1;

	string s = "Mayank";
	string p = s;

	int n = 10, m = 25;
	cout << n + m << endl;

	s = s + p;
	s = s + "Rahul";
	s = s + "M";
	s = s + 'a';

	cout << s[0] << endl;
	cout << s.length() << endl;
	cout << s[s.length() - 1] << endl;

	s.push_back('a');
	s.pop_back();//Removes the last character.
	cout << s.back() << endl;//returns a element.
	cout << s.front() << endl;//return a element






}