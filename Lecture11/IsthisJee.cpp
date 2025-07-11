#include<iostream>
#include<math.h>
#include<iomanip>
using namespace std;
#define PI 3.1415926535897

double F(double x, double b, double c) {
	return (((x * x) + (b * x) + c) / sin(x));
}

double F1(double x, double b, double c) {
	return (((2 * x + b) * sin(x)) - (cos(x) * ((x * x) + (b * x) + c)));
}


//Method1:Using Binary Search
double IsthisJee(double b, double c) {

	double s = 0, e = PI / 2;
	int count = 0;
	double ans = -1;//potential ans;

	while (s <= e) {
		double mid = (s + e) / 2;

		double slope = F1(mid, b, c);
		if (slope < 0) {
			s = mid;
			ans = mid;
		} else {
			e = mid;
			ans = mid;
		}

		count++;
		if (count > 100) {
			break;
		}

	}

	return ans;
}


//Method2: Using Ternary Search

double IsthisJee2(double b, double c) {

	double s = 0;
	double e = PI / 2;
	double error = 1e-6;
	double ans = -1;

	while ((e - s) > error) {
		double m1 = s + (e - s) / 3;
		double m2 = e - (e - s) / 3;

		if (F(m1, b, c) > F(m2, b, c)) {
			s = m1;
			ans = m2;
		} else if (F(m1, b, c) < F(m2, b, c)) {
			e = m2;
			ans = m1;

		} else {
			//F(m1,b,c)=F(m2,b,c)
			ans = m1;
			s = m1, e = m2;
		}
	}

	return ans;
}


int main() {
	int t;
	cin >> t;

	int i = 1;
	while (i <= t) {

		double b, c;
		cin >> b >> c;

		double val = IsthisJee(b, c);
		cout << fixed << setprecision(8) << F(val, b, c) << endl;
		double val2 = IsthisJee2(b, c);
		cout << fixed << setprecision(8) << F(val2, b, c) << endl;

		i++;
	}

}