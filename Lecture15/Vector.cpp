#include<iostream>
#include<vector>
using namespace std;


int main() {



	vector<int>v{1, 2, 3, 4, 5};
	cout << v.size() << endl;
	cout << v.capacity() << endl;

	v.clear();

	cout << v.size() << endl;
	cout << v.capacity() << endl;


}