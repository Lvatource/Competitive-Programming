#include "kindergarden.h"
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
#define vb vector<bool>
#define pb push_back
#define ll long long
#define vvi vector<vi>
#define pii pair<int, int>
#define mp make_pair
#define vvpii vector<vector<pii>>
#define all(x) x.begin(), x.end()
#define MAXN 1010
const int INF = 2e18, MOD = 1e9 + 7;

vi dist(MAXN);

void sp(int src, int n, vvpii adj) {
	for (int i = 0; i < n; i++) dist[i] = INF;
	vb done(n, false);
	dist[src] = 0;
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	pq.push({ 0, src });
	while (!pq.empty()) {
		pii tmp = pq.top(); pq.pop();
		int u = tmp.second, d = tmp.first;
		if (done[u]) continue;
		done[u] = true;
		for (auto ii : adj[tmp.second]) {
			int v = ii.first, w = ii.second;
			if (dist[v] > dist[u] + w) {
				dist[v] = dist[u] + w;
				pq.push({ dist[v], v });
			}
		}
	}
}

ll Renovate(int N, int M, int T, vi C, vi A, vi B, vi S) {
	vvpii adj(N);
	for (int i = 0; i < M; i++) {
		auto t = mp(B[i] - 1, S[i]);
		adj[A[i] - 1].pb(t);
		auto k = mp(A[i] - 1, S[i]);
		adj[B[i] - 1].pb(k);
	}
	ll price = 0;
	sp(0, N, adj);
	for (int i = 0; i < N; i++) {
		price += C[i] * dist[i];
	}
	cout << price << endl;
	ll best = 0;
	for (int i = 1; i < N; i++) {
		ll curprice = 0;
		auto t = mp(i, T);
		adj[0].pb(t);
		auto k = mp(0, T);
		adj[i].pb(k);
		sp(0, N, adj);
		for (int i = 0; i < N; i++) {
			curprice += C[i] * dist[i];
		}
		if (best < (price - curprice)) best = (price - curprice);
		cout << curprice << endl;
		adj[0].pop_back();
		adj[i].pop_back();
	}
	return best;
}
