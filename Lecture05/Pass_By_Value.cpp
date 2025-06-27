#include<iostream>
using namespace std;


//Pass By Value.
void Sum(int a, int b) {
	a += 10;
	b += 15;

	cout << "Values in My Sum Function " << endl;
	cout << a << " " << b << endl;
	cout << "--------------------" << endl;
}


int main() {

	int a = 10, b = 15;

	cout << "Values in My Main Function " << endl;
	cout << a << " " << b << endl;
	cout << "--------------------" << endl;
	Sum(a, b);

	cout << "Values in My Main Function " << endl;
	cout << a << " " << b << endl;
	cout << "--------------------" << endl;


}