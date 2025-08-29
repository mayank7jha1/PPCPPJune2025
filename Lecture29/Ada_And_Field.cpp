#include<iostream>
#include<set>
using namespace std;


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;

	while (t--) {

		int n, m, q;
		cin >> n >> m >> q;

		multiset<int>xc, yc, sx, sy;

		xc.insert(0);
		xc.insert(n);
		yc.insert(0);
		yc.insert(m);

		sx.insert(n);
		sy.insert(m);

		for (int i = 0; i < q; i++) {

			int a, b;
			cin >> a >> b;

			if (a == 0) {
				//Vertical Line on x = b
				if (xc.find(b) != xc.end()) {
					//I have already marked this division

					int LargestXSegment = *(--sx.end());
					int LargestYSegment = *(--sy.end());
					cout << LargestXSegment*LargestYSegment << endl;
					continue;
				}


				//Because small is an iterator
				multiset<int>::iterator small = xc.lower_bound(b);
				small--;
				auto large = xc.upper_bound(b);

				int Length = (*large - *small);

				sx.erase(sx.find(Length));
				sx.insert(b - *small);
				sx.insert(*large - b);

				xc.insert(b);

				int LargestXSegment = *(--sx.end());
				int LargestYSegment = *(--sy.end());
				cout << LargestXSegment*LargestYSegment << endl;


			} else {
				//Horizontal Line on y = b


				if (yc.find(b) != yc.end()) {
					//I have already marked this division

					int LargestXSegment = *(--sx.end());
					int LargestYSegment = *(--sy.end());
					cout << LargestXSegment*LargestYSegment << endl;
					continue;
				}

				//Because small is an iterator
				multiset<int>::iterator small = yc.lower_bound(b);
				small--;
				auto large = yc.upper_bound(b);

				int Length = (*large - *small);

				sy.erase(sy.find(Length));
				sy.insert(b - *small);
				sy.insert(*large - b);

				yc.insert(b);

				int LargestXSegment = *(--sx.end());
				int LargestYSegment = *(--sy.end());
				cout << LargestXSegment*LargestYSegment << endl;
			}
		}
	}

}