#include<iostream>
using namespace std;

//Function Prototype.
int Sum1(int, int);
void Sum2(int, int);


int main() {

	int a, b;
	cin >> a >> b;

	//Function Call
	int ans = Sum1(a, b);
	cout << a << endl;

	// cout << ans << endl;
	// cout << Sum1(13, 18) << endl;

	// //Function Call
	// Sum2(a, b);

}

//Function Definition
// void Sum2(int a, int b) {
// 	// int ans = a + b;
// 	// cout << ans << endl;

// 	cout << a + b << endl;
// 	return;
// }

//Function Definition
//Passing by Value.
int Sum1(int a, int b) {
	// return (a + b);
	a++;
	cout << a << endl;
	int ans = (a + b);
	//cout << ans << endl;
	return ans;
}
