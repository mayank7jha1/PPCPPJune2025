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
		mp[y].push_back(x);
	}

	bool dfs_helper(T node, T parent, int color) {
		visited[node] = color;
		/*
			visited[node]=0 this is means node is unvisisted.
			visited[node]=1 this means node is visited and is with
			a color 1.
			visited[node]=2 this means node is visited and is with color
			2.
		*/

		for (auto nbr : mp[node]) {
			if (visited[nbr] == 0) {
				bool small_ans = dfs_helper(nbr, node, 3 - color);
				if (small_ans == 0) {
					return false;
				}
			} else if (nbr != parent and visited[nbr] == color) {
				return false;
			}
		}

		return true;
	}


	bool dfs(T scr) {

		for (auto x : mp) {
			visited[x.first] = 0;
		}

		int color = 1;

		//scr node : 1 and Its parent is -1.
		return dfs_helper(1, -1, color);
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

	cout << gr.dfs(1) << endl;

}