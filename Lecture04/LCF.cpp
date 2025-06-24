#include<iostream>
using namespace std;


int main() {


	int a, b;//Variable Definition.
	cin >> a >> b;

	int c = a, d = b;


	if (a < b) {
		//Swap a,b
		int temp = a;
		a = b;
		b = temp;
	}

	while (b != 0) {
		int temp = b;
		b = (a % b);
		a = temp;
	}



	cout << (c * d) / a << endl;


}