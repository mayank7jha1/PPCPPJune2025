#include<iostream>
#include<map>
#include<list>
#include<utility>
#include<algorithm>
using namespace std;


//Undirected/Directed Unweighted Graph.
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

	void dfs_helper(T node, map<T, bool>&visited) {

		cout << node << " ";
		visited[node] = 1;

		for (int nbr : mp[node]) {
			if (visited[nbr] == 0) {
				dfs_helper(nbr, visited);
			}
		}

	}

	void dfs(T scr) {

		map<T, bool>visited;
		for (auto x : mp) {
			visited[x.first] = 0;
		}

		//Create a new function and then apply recursion there.
		dfs_helper(scr, visited);
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
	cout << endl << "-------------------------------------" << endl;
	gr.dfs(1);
}