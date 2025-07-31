#include<iostream>
using namespace std;
char input[100];
char output[100];
int count1 = 0;


void F(int i, int j) {

	if (input[i] == '\0') {
		output[j] = '\0';
		cout << output << endl;
		count1++;
		return;
	}


	//Op1: You take the current character.
	output[j] = input[i];
	F(i + 1, j + 1);

	//Op2: You don't take the current character.
	F(i + 1, j);

	return;
}


int main() {
	cin >> input;
	F(0, 0);

	cout << count1 << endl;
}



