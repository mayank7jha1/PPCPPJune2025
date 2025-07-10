#include<iostream>
using namespace std;
#define int long long


int32_t main() {

	char ch[105];
	cin >> ch;

	int nb, ns, nc;
	cin >> nb >> ns >> nc;


	int pb, ps, pc;
	cin >> pb >> ps >> pc;

	int r;
	cin >> r;

	//Calculate sb,ss,sc:
	//How many breads are required in one hamburger
	//based on recipe and vice versa.

	int sb = 0, ss = 0, sc = 0;

	for (int i = 0; ch[i] != '\0'; i++) {
		if (ch[i] == 'B') {
			sb++;
		} else if (ch[i] == 'S') {
			ss++;
		} else {
			sc++;
		}
	}

	int s = 0, e = 100 + 1e12;
	int ans = -1;
	while (s <= e) {

		int mid = (s + e) / 2;

		//Paisa Required to make mid amount of hamburger.
		int PRB = ((mid * sb) - nb) * pb;
		if (PRB < 0) {
			PRB = 0;
		}

		int PRS = ((mid * ss) - ns) * ps;
		if (PRS < 0) {
			PRS = 0;
		}

		int PRC = ((mid * sc) - nc) * pc;
		if (PRC < 0) {
			PRC = 0;
		}

		int Total = PRB + PRS + PRC;


		if (Total <= r) {

			ans = mid;
			s = mid + 1;

		} else {
			e = mid - 1;
		}
	}




	cout << ans << endl;

}