#include<iostream>
using namespace std;



class Test {
	int x;
};


template<typename T>
class ClassTest {
	T y;
};


template<typename T>
class UnitTest {
	T s;
};

template<typename T1, typename T2>
class Check {
	T1 s;
	T2 p;
};


int main() {

	Test t;
	ClassTest<int>ct;
	UnitTest<string>ut;
	Check<string, int>p;
	// Check<Check<int>>st;

	vector<vector<int>>v;

}