#include<iostream>
#include<algorithm>
using namespace std;

class Activity {
public:
	int start;
	int end;

	Activity() {
		start = 0;
		end = 0;
	}
};


bool compare(Activity x, Activity y) {

	if (x.end <= y.end) {
		return true;
	} else {
		return false;
	}

}

int main() {

	int t;
	cin >> t;

	while (t--) {

		int n;
		cin >> n;

		Activity a[n];
		for (int i = 0; i < n; i++) {
			cin >> a[i].start >> a[i].end;
		}

		sort(a, a + n, compare);

		//All the activities based on the end point in ASC. order.


		int ans = 1;
		int Prev_End_Point = a[0].end;

		for (int i = 1; i < n; i++) {
			if (a[i].start >= Prev_End_Point) {
				ans++;
				Prev_End_Point = a[i].end;
			}
		}

		cout << ans << endl;
	}


}