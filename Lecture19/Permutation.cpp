#include<iostream>
#include<cstring>
using namespace std;
char input[100];
string s;

/*
	F(i): Permutations from i index to n-1 index of
	the input array.

	F(i) : (Swap input[i],input[j]) + F(i+1)
	where j goes from i to n-1 index in input array.

	Base Condition:
	input[k]= '\0';
	F(k)= Nothing:

*/

void F(int i) {
	//Currently We are solving for state F(i).
	//Stopping Point:
	if (input[i] == '\0') {
		cout << input << endl;
		return;
	}

	//Task:
	for (int j = i; input[j] != '\0'; j++) {
		swap(input[i], input[j]);
		F(i + 1);
		swap(input[i], input[j]);;//Backtracking
	}

}

void F1(int i) {
	//Currently We are solving for state F(i).
	//Stopping Point:
	if (i == s.length()) {
		cout << s << endl;
		return;
	}


	//Task:
	for (int j = i; j < s.length(); j++) {
		swap(s[i], s[j]);
		F1(i + 1);
		swap(s[i], s[j]);//Backtracking
	}

}

void F2(string str, int i) {
	//Currently We are solving for state F(i).
	//Stopping Point:
	if (i == str.length()) {
		//cout << str << endl;
		return;
	}


	//Task:
	for (int j = i; j < str.length(); j++) {
		swap(str[i], str[j]);
		cout << str << endl;
		F2(str, i + 1);
	}

}

int main() {
	// cin >> input;
	// cin >> s;
	string str;
	cin >> str;
	// //cout << input << endl;
	// F(0);//Starting Point
	// cout << "--------------------" << endl;
	// F1(0);//Starting Point
	//cout << "--------------------" << endl;
	F2(str, 0); //Starting Point

}