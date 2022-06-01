#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <utility>
#include <set>
#include <string>
#include <queue>
using namespace std;

#define vi vector<int>
#define pb push_back
#define ll long long
#define vvi vector<vi>
#define all(x) x.begin(),x.end()
const int INF = 2e18, MOD = 1e9 + 7;

vvi graph(10e5);
vi teams(10e5, 0);
bool gay = false;

void dfs(int cur, int a) {
	if (!gay) {
		if (teams[cur] != 0) {
			if (teams[cur] == a) {
				return;
			}
			else {
				teams[cur] = a;
				gay = true;
				return;
			}
		}
		teams[cur] = a;
		for (int nei : graph[cur]) {
			if (a == 1) {
				dfs(nei, 2);
			}
			else {
				dfs(nei, 1);
			}
		}
	}
}

int main()
{
	int n, m, a, b;
	cin >> n;
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		a--; b--;
		graph[a].pb(b);
		graph[b].pb(a);
	}
	for (int i = 0; i < n; i++) {
		if (teams[i] == 0) {
			dfs(i, 1);
		}
	}
	if (gay) {
		cout << "IMPOSSIBLE" << endl;
	}
	else {
		for (int i = 0; i < n; i++) {
			cout << teams[i] << " ";
		} 
	}
}