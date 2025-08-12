#include<iostream>
using namespace std;


// template<typename T1, typename T2>
template<typename T>

class Vector {
public:

	T *a;
	int cs;
	int ts;

	//Default Constructor
	Vector() {
		cs = 0;
		ts = 1;
	}


	//Parameterised Constructor
	Vector(int n) {
		cs = 0;
		ts = n;
		a = new T[ts];
	}

	//Member Functions:
	void push_back(T x) {

		if (cs == ts) {
			T *b = a;
			a = new T[2 * ts];

			//Copy the data of b to a.
			for (int i = 0; i < ts; i++) {
				a[i] = b[i];
			}

			ts *= 2;
			delete[]b;
		}

		a[cs] = x;
		cs++;
	}

	int size() {
		return cs;
	}

	int capacity() {
		return ts;
	}

	void pop_back() {
		cs--;
	}

	T front() {
		return a[0];
	}

	T back() {
		return a[cs - 1];
	}

	T operator[](int i) {
		return a[i];
	}

	// vector<int>v;
	// v[i];
	// v.operator[](i);
};



