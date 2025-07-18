#include<iostream>
using namespace std;


int main() {


	int a[5] {5, 1, 2, 3, 9};

	/*
		By definition:
		a is a address(Base) of array.

		a=8013;

		Meaning of this by definition.
		a[5]:*(a+5): value at (8013+4*5);

		(VALUE AT 8033)

	*/

	// int a[90];//This is not allowed.

	//Updation is allowed: But the block is not occupied.
	// a[90] = 87;
	// cout << a[90] << endl;

	// ..........


	// .....


	// int p = 12;
	// cout << a[90] << endl;

	// int x = 19;

	// a[90] = 12;

	int *b = new int[] {5, 3, 1, 9};
	cout << b[2] << endl;
	delete[]b;

	cout << b[2] << endl;





}







