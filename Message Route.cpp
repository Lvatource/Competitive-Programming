#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;

#define ll long long
#define vi vector<int>
#define vvi vector<vector<int>>
#define pb push_back

vvi graph;
vector<bool> check;
queue<int> bfsq;
vi parent; //parent[i] = the parent node of i
vi parents;
void bfs(int cur) {
	queue<int> bfsq;
	check[cur] = true;
	bfsq.push(cur);
	parent[cur] = cur;
	while (bfsq.size()) {
		int f = bfsq.front();
		bfsq.pop();
		for (int nei : graph[f]) {
			if (!check[nei]) {
				parent[nei] = f;
				bfsq.push(nei);
				check[nei] = true;
			}
		}
	}
}

int main()
{
	int n, m, a, b;
	cin >> n >> m;
	graph.resize(n);
	check.resize(n);
	parent.resize(n);
	parents.resize(0);
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		a--; b--;
		graph[a].pb(b);
		graph[b].pb(a);
	}
	bfs(0);
	if (check[n - 1] == false) {
		cout << "IMPOSSIBLE" << endl;
		return 0;
	}
	int i = n - 1;
	while (parent[i] != 0) {
		parents.pb(parent[i]);
		i = parent[i];
	}
	parents.pb(0);
	reverse(parents.begin(), parents.end());
	cout << parents.size() + 1 << endl;;
	for (int i = 0; i < parents.size(); i++) {
		cout << parents[i] + 1 << " ";
	}
	cout << n << endl;
}