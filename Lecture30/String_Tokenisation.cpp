#include<iostream>
#include<cstring>
#include<string>
#include<vector>

using namespace std;


int main() {

	// char ch[100];
	// cin.getline(ch, 50, '\n');
	// cout << ch << endl << endl;

	// char *token = strtok(ch, " ");
	// cout << token << endl;
	// // cout << token << endl;
	// // cout << token << endl;

	// // token = strtok(ch, " ");
	// // cout << token << endl;

	// token = strtok(NULL, " ");
	// cout << token << endl;

	// while (token != NULL) {
	// 	cout << token << endl;
	// 	token = strtok(NULL, " ");
	// }

	string s;
	getline(cin, s);
	cout << s << endl;

	// (char*)s.c_str() : THis is how you convert your string to
	//character array.
	char *token = strtok((char*)s.c_str(), " ");
	while (token != NULL) {
		cout << token << endl;
		token = strtok(NULL, " ");
	}

	cout << endl << "---------------------" << endl;
	vector<vector<char>>ans;
	vector<char>current;

	for (int i = 0; i < s.length(); i++) {
		int flag = 1;
		if ((s[i] >= 'a' and s[i] <= 'z') or (s[i] >= 'A' and s[i] <= 'Z') or
		        (s[i] >= '0' and s[i] <= '9')) {
			current.push_back(s[i]);
		} else if (flag == 1) {

			ans.push_back(current);
			current.clear();
			flag = 0;
		}

	}

	for (vector<char>x : ans) {
		for (char y : x) {
			cout << y;
		}
		cout << endl;
	}

}