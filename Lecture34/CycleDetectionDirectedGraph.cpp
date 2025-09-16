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

	bool dfs_helper(T node, map<T, int>&visited, map<T, int>&Instack) {
		visited[node] = 1;
		Instack[node] = 1;

		for (auto nbr : mp[node]) {

			if ((visited[nbr] == 0) and ((dfs_helper(nbr, visited, Instack) == 1)) or (Instack[nbr] == 1)) {
				return true;
			}

		}

		//Backtracking
		Instack[node] = 0;

		return false;
	}

	bool dfs(T scr) {

		map<T, int>visited, Instack;
		for (auto x : mp) {
			visited[x.first] = 0;
			Instack[x.first] = 0;
		}

		return dfs_helper(scr, visited, Instack);
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
	cout << gr.dfs(1);

}