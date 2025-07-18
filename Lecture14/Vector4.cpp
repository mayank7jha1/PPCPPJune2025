#include<iostream>
#include<vector>
using namespace std;


int main() {


	//These vectors are exactly like dynamic array.
	vector<int>v1{5, 4, 3, 1, 6};
	// vector<int>v2(6);//Size is specified.
	// int n;
	// cin >> n;

	// for (int i = 0; i < n; i++) {
	// 	cin >> v2[i];//This hasmeaning.
	// 	// int x;
	// 	// cin >> x;
	// 	// v3.push_back(x);
	// }





	vector<int>v3;//Size is not specified.
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		//cin >> v3[i];//This has no meaning.
		int x;
		cin >> x;
		v3.push_back(x);
	}

	cout << v3.capacity() << endl;

	// vector<int>v2(6);//Size is specified.
	// int n;
	// cin >> n;

	// for (int i = 0; i < n; i++) {
	// 	//cin >> v2[i];//This has meaning.
	// 	int x;
	// 	cin >> x;
	// 	v2.push_back(x);
	// }
	// cout << v2.size() << endl;
	// cout << v2.capacity() << endl;

	// for (int i = 0; i < v2.size(); i++) {
	// 	cout << v2[i] << " ";
	// }





}





