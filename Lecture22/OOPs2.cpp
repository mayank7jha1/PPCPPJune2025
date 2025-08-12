#include<iostream>
using namespace std;

/*
	Access Modifiers:
	private
	protected
	public

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


	//Member Functions:
	//Getter:It fetches us private data member of the class.
	//Setter:It sets value to private data member of the class.

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
	Car y;
	y.name = "BMW";
	y.condition = "Very Good";
	y.model = 5.2;
	y.color = "Black";
	// y.cost = 100000;
	//cout << y.get_value() << endl;
	y.set_value(90000);
	y.Print();





}