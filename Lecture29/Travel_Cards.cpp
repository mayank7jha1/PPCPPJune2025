#include<iostream>
#include<map>
#include<algorithm>
#include<vector>
using namespace std;
#define int long long
int n, k, a, b, f;

bool compare(int x, int y) {
	return (x > y);
}


//Computation: nlog(n)+n+nlog(n)+n = 2(n+nlog(n)) ~ nlog(n)
int32_t main() {
	cin >> n >> a >> b >> k >> f;

	map<pair<string, string>, int>Route_Cost;
	string Previous_Point = "";

	for (int i = 0; i < n; i++) {

		string sp, ep;
		cin >> sp >> ep;

		//Cost tells you the cost of the current trip.
		int cost = 0;
		if (Previous_Point == sp) {
			cost = b;
		} else {
			cost = a;
		}
		Previous_Point = ep;

		if (sp > ep) {
			swap(sp, ep);
		}

		Route_Cost[ {sp, ep}] += cost;
	}

	vector<int>v;
	int TotalCost = 0;

	for (pair<pair<string, string>, int> x : Route_Cost) {
		TotalCost += x.second;
		v.push_back(x.second);
	}

	sort(v.begin(), v.end(), compare);
	// sort(v.begin(), end());
	// reverse(v.begin(), end());
	// sort(v.begin(), v.end(), greater<int>());
	//sort(v.rbegin(), v.rend());



	for (int i = 0; i < v.size() and i < k; i++) {
		if (v[i] > f) {
			//I can Buy TC for this trip.
			TotalCost = TotalCost - v[i] + f;
		} else {
			break;
		}
	}

	cout << TotalCost << endl;


}



// vector sort desc. order : R1: (Done)
// R2(done)
// R3(): R3 cost < f k exhaust hogaye.
// 	R4()
