#include<iostream>
#include<map>
#include<list>
#include<utility>
#include<algorithm>
#include<queue>
#include<climits>
using namespace std;


//Undirected & Unweighted Graph.
template<typename T>
class Graph {
private:
	map<T, list<T>>mp;//Adj. List
public:

	void addedge(T x, T y, int direction) {
		mp[x].push_back(y);

		if (direction == 0) {
			//This is an undirected egde.
			mp[y].push_back(x);
		}
	}

	void bfs(T scr, T destination) {
		// map<node,It is visited or not?>mp;
		map<T, int>distance;

		//This is to mark every node in the current graph/adj. list is unvisited.
		for (pair<int, list<int>> x : mp) {
			int node = x.first;
			distance[node] = INT_MAX;
		}

		queue<T>q;
		q.push(scr);
		distance[scr] = 0;

		while (!q.empty()) {

			T node = q.front();
			q.pop();

			for (int nbr : mp[node]) {

				if (distance[nbr] == INT_MAX) {
					q.push(nbr);
					distance[nbr] = distance[node] + 1;
				}
			}
		}

		cout << "Distance between " << scr << " and " << destination << " is " << distance[destination] << endl;
		cout << endl << "---------------------------------------" << endl;
		for (pair<int, list<int>>x : mp) {
			cout << "Distance between " << scr << " and " << x.first << " is " << distance[x.first] << endl;
		}

	}

	void Print() {
		//Print the Adj List.
		for (pair<int, list<int>> info : mp) {
			int node = info.first;
			list<int>nbr_info = info.second;
			cout << node << " : ";
			for (int nbrs : nbr_info) {
				cout << nbrs << " ";
			}
			cout << endl;
		}
	}

};


int main() {

	int n, m;
	cin >> n >> m;

	int direction = 0;

	Graph<int>gr;
	for (int i = 0; i < m; i++) {
		int sp, ep;
		cin >> sp >> ep;
		gr.addedge(sp, ep, direction);
	}

	gr.Print();

	cout << endl << "--------------------------" << endl;
	gr.bfs(1, 5);
}