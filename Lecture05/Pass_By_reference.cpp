#include<iostream>
using namespace std;


//Pass By Reference.
//Since a and b are passed by reference p,q are
// alias of a, b hence no new two variables are created
// we are just using another name p for a only and
// q for b only.
void Sum(int &p, int &q) {
	(p) = (p) + 10;
	(q) = (q) + 15;

	cout << "Values in My Sum Function " << endl;
	cout << p << " " << q << endl;
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