#include<iostream>
#include<vector>
#include<cstring>
using namespace std;


int main() {

	//Define:
	vector<vector<int>>v;
	vector<vector<int>>v1(5, vector<int>(7));
	int a[10];

	//Meaning:
	//this is a vector of size 5x7 which is initialised with value 3.
	vector<vector<int>>v2(5, vector<int>(7, 3));

	//It is a vector of size 10 and initialised with value 20.
	vector<int>v3(10, 20);
	v3.resize(15);
	v3.resize(20, 7);
	v3.clear();


	//-1,0,1
	memset(a, -1, sizeof(a));
}












