#include<iostream>
using namespace std;
const int N = 200001;

int main() {

	char s[N];
	cin >> s;

	int len = 0;
	for (int i = 0; s[i] != '\0'; i++) {
		len++;
	}

	int m;
	cin >> m;

	int i = 1;
	while (i <= m) {

		//For my current day find segment SP,EP;
		int SP;
		cin >> SP;
		SP--;

		int EP = len - SP - 1;

		//Now Reverse the current String from
		//SP to EP.

		while (SP < EP) {

			//Swap them:
			char temp = s[SP];
			s[SP] = s[EP];
			s[EP] = temp;

			SP++, EP--;
		}

		i++;
	}

	cout << s << endl;








}