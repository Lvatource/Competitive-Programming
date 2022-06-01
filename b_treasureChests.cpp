#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <utility>
#include <set>
#include <string>
using namespace std;

#define vi vector<int>
#define pb push_back
#define ll long long
#define vvi vector<vi>

vvi graph(1e6);
vector<bool> check(1e6, false);
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
	int N, cur;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> cur;
		cur--;
		graph[cur].pb(i);
		graph[i].pb(cur);
	}
	cur = 0;
	for (int i = 0; i < N; i++) {
		if (!check[i]) {
			dfs(i);
			cur++;
		}
	}
	cout << cur << endl;
}