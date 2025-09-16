#include<iostream>
#include<list>
#include<map>
#include<queue>
#include<algorithm>
#include<climits>
using namespace std;

template<typename T>
class Graph {
	map<T, list<T>>mp;
public:

	void AddEdge(T x, T y) {
		mp[x].push_back(y);
	}

	void bfs() {

		map<T, int>indegree;
		for (auto x : mp) {
			indegree[x.first] = 0;
		}

		//Calculating the indegree of each node:
		for (pair<T, list<int>> x : mp) {
			T node = x.first;
			for (int nbr : mp[node]) {
				indegree[nbr]++;
			}
		}

		queue<T>q;

		//Put all the nodes with zero indegree in
		//the queue.
		for (pair<T, int> x : indegree) {
			if (x.second == 0) {
				//The current node will have indegree as zero.
				q.push(x.first);
			}
		}

		while (!q.empty()) {

			T node = q.front();
			q.pop();

			cout << node << " ";

			for (int nbr : mp[node]) {
				indegree[nbr]--;
				if (indegree[nbr] == 0) {
					q.push(nbr);
				}
			}

		}

	}


};


int main() {
	int n, m;
	cin >> n >> m;
	Graph<int>gr;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		gr.AddEdge(x, y);
	}

	gr.bfs();

}