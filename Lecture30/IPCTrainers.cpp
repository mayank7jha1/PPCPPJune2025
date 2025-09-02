#include<iostream>
#include<set>
#include<queue>
using namespace std;
const int N = 1e5 + 2;


int main() {

	int t;
	cin >> t;
	while (t--) {

		int n, d;
		cin >> n >> d;

		int AD[N] {0}, Lecture[N] {0}, Sadness[N] {0};

		priority_queue <pair<int, int>>pq;//Max Heap

		for (int i = 0; i < n; i++) {
			cin >> AD[i] >> Lecture[i] >> Sadness[i];
			pq.push({Sadness[i], i});

		}

		set<int>s;
		for (int i = 1; i <= d; i++) {
			s.insert(i);
		}

		int Lectures_Taken[N] {0};

		while (!pq.empty()) {

			pair<int, int>Current_Prof = pq.top();
			pq.pop();

			int Arrival_Day = AD[Current_Prof.second];
			int Optimistic_End_Day = Arrival_Day + Lecture[Current_Prof.second] - 1;

			for (int i = Arrival_Day; i <= Optimistic_End_Day; i++) {
				set<int>::iterator it = s.lower_bound(i);

				if (it == s.end()) {
					break;
				} else {
					s.erase(it);
					Lectures_Taken[Current_Prof.second]++;
				}

			}
		}


		int total_sadness = 0;
		for (int i = 0; i < n; i++) {
			total_sadness += ((Lecture[i] - Lectures_Taken[i]) * Sadness[i]);
		}

		cout << total_sadness << endl;

	}

}


