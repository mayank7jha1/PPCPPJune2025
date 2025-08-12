#include<iostream>
#include<cstring>
using namespace std;

/*
	4 Things are Self Invoked for every class.
	1. Constructor
	2. Copy Constructor
	3. Copy Assignment Operator
	4. Destructor

	3. Copy Assignment Operator

	//Operator Overloading


*/


//Definition of the Class Car/ Data Type Car.
class Car {

	//Data Members:
private:
	int cost = 100000;
public:
	//This is a array defined in static memory.
	char name[100];
	string condition;
	double model;
	string color;
	//This is a pointer that is going to point to an array in heap/dynamic memory.
	char *engine = new char[100];

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
	Car(char* name, string c, double m, string col, int price, char *e) {
		cout << "Inside My Parameterised Constructor" << endl;
		strcpy(this->name, name);

		this->condition = c;
		model = m;
		color = col;
		set_value(price);
		engine = new char[strlen(e) + 1];
		strcpy(engine, e);
	}

	//Copy Constructor
	Car(Car &x) {
		cout << "Inside My own Copy Constructor" << endl;
		strcpy(name, x.name);

		condition = x.condition;
		model = x.model;
		color = x.color;
		set_value(x.cost);

		//Deep Copy
		engine = new char[strlen(x.engine) + 1];
		strcpy(engine, x.engine);
	}

	//Operator Overloading
	void operator=(Car &x) {
		cout << "Inside My own Copy Assignment Operator" << endl;
		strcpy(name, x.name);

		condition = x.condition;
		model = x.model;
		color = x.color;
		set_value(x.cost);

		//Deep Copy
		engine = new char[strlen(x.engine) + 1];
		strcpy(engine, x.engine);
	}

	void Print() {
		cout << name << endl;
		cout << condition << endl;
		cout << model << endl;
		cout << color << endl;
		cout << cost << endl;
		cout << engine << endl;
		cout << "---------------- -" << endl;
	}

};


int main() {

	Car y;//Definition of your object y.
	strcpy(y.name, "BMW\0");
	y.condition = "Very Good";
	y.model = 5.2;
	y.color = "Black";
	y.set_value(90000);
	strcpy(y.engine, "V8");
	y.Print();

	//Initialisation with the help of contructor.
	Car z("Maruti\0", "Good", 7.9, "White", 100000, "V9");
	z.Print();

	Car p(z);//This will invoke copy constructor
	p.Print();

	z.name[0] = 'T';
	z.engine[0] = 'Z';

	z.Print();
	p.Print();

	Car m;
	m = p;//This is copy assignment
	m.Print();

	/*
		m=p;
		m.operator=(p);

		string m="Bat";
		string l="Lat";

		m=(m+l);
		string z= m.operator+(l);

		cout<<"Mayank"<<endl<<"Samyak"<<endl;
		cout.operator<<("Mayank");
		cout.operator<<(endl);

	*/

}