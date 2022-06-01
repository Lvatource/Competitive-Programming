#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

#define ll long long
#define vi vector<int>
#define vvi vector<vector<int>>
#define pb push_back

vvi graph;
vector<bool> check;
vector<int> roads;
void dfs(int cur) {
	if (check[cur]) {
		return;
	}
	check[cur] = true;
	for (int nei : graph[cur]) {
		dfs(nei);
	}
}

int main()
{
	int n, m, a, b;
	int counter = 0;
	cin >> n >> m;
	graph.resize(n);
	check.resize(n);
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		a--; b--;
		graph[a].pb(b);
		graph[b].pb(a);
	}
	for (int i = 0; i < n; i++) {
		if (!check[i]) {
			dfs(i);
			roads.pb(i);
			counter++;
		}
	}
	counter--;
	cout << counter << endl;
	for (int i = 0; i < counter; i++) {
		cout << roads[i] + 1 << " " << roads[i + 1] + 1 << endl;
	}
}