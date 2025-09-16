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
	map<T, int>visited;
public:

	void AddEdge(T x, T y) {
		mp[x].push_back(y);
	}

	void dfs_helper(T node, list<int>&order) {
		visited[node] = 1;
		for (int nbr : mp[node]) {
			if (visited[nbr] == 0) {
				dfs_helper(nbr, order);
			}
		}

		//I am returning from this node.
		order.push_front(node);
	}

	void dfs(T scr) {

		list<int>order;
		for (auto x : mp) {
			visited[x.first] = 0;
		}


		//Dfs call from every node:
		for (pair<int, list<int>>	x : mp) {
			T node = x.first;
			if (visited[node] == 0) {
				dfs_helper(node, order);
			}
		}


		for (int x : order) {
			cout << x << " ";
		}

		cout << endl;
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

	gr.dfs(1);

}