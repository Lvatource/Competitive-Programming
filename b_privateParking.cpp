#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <utility>
#include <set>
#include <string>
#include <queue>
#include <tuple>
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
const ll INF = 2e18, MOD = 1e9 + 7;

ll GetMinCrossingPairs(int N, vi C, vi P) {
	vector<vector<pii>> cross(N, vector<pii>(N));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (C[i] == P[j]) {
				for (int diff = 0; diff < N; diff++) {
					cross[diff][i] = mp(i, (j + diff) % N);
				}
			}
		}
	}
	ll ans = INF;
	for (int diff = 0; diff < N; diff++) {
		ll cnt = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < i; j++) {
				if (cross[diff][j].second > cross[diff][i].second) cnt++;
			}
		}
		ans = min(ans, cnt);
	}
	return ans;
}