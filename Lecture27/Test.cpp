#include<iostream>
using namespace std;
// int temp = 50;

// void F(int x, int &temp) {

// 	//This line will always run at the start.


// 	if (x == 11) {
// 		cout << temp << endl;
// 		return;
// 	}

// 	temp++;

// 	cout << x << " ";

// 	F(x + 1, temp++);


// }


void F(int x) {

	//This line will always run at the start.
	static int temp = 50;

	if (x == 11) {
		cout << temp << endl;
		return;
	}

	//temp++;


	temp++;

	cout << x << " ";

	F(x + 1);


}


int main() {

	int temp = 50;

	F(1);

}