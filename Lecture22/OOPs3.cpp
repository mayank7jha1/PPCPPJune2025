#include<iostream>
using namespace std;

/*
	4 Things are Self Invoked for every class.
	1. Constructor
	2. Copy Constructor
	3. Copy Assignment Operator
	4. Destructor


	1. Constructor : Initialise karna at the time of definition.

*/


//Definition of the Class Car/ Data Type Car.
class Car {

	//Data Members:
private:
	int cost = 100000;
public:
	string name;
	string condition;
	double model;
	string color;

	int get_value() {
		return cost;
	}

	void set_value(int v) {
		if (v >= 70000) {
			cost = v;
		} else {
			cost = 70000;
		}
	}

	//Constructor Overloading
	//Default Constructor
	Car() {
		cout << "Inside My Default Constructor" << endl;
	}

	//Parameterised Constructor
	Car(string name, string c, double m, string col, int price) {
		cout << "Inside My Parameterised Constructor" << endl;
		this->name = name;
		this->condition = c;
		model = m;
		color = col;
		set_value(price);
	}

	void Print() {
		cout << name << endl;
		cout << condition << endl;
		cout << model << endl;
		cout << color << endl;
		cout << cost << endl;
		cout << "-----------------" << endl;
	}

};


int main() {
	Car y;//Definition of your object y.
	y.name = "BMW";
	y.condition = "Very Good";
	y.model = 5.2;
	y.color = "Black";
	y.set_value(90000);
	y.Print();

	//Initialisation with the help of contructor.
	Car z("Maruti", "Good", 7.9, "White", 100000);
	z.Print();

}