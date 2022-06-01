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

#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define vb vector<bool>
#define vvi vector<vi>
#define vvll vector<vll>
#define pii pair<int, int>
#define pll pair<ll,ll>
#define vvpii vector<vector<pii>>
#define vvpll vector<vector<pll>>
#define mp make_pair
#define pb push_back
#define all(x) x.begin(), x.end()
const ll INF = 2e18, MOD = 1e9 + 7;

int cost(char c) {
	if (c == 'S') return 1;
	return 0;
}

int GetGoodReception(int R, int C, int D, int K, vector<string> G) {
	vvi pref(R + 1, vi(C + 1, 0));
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			pref[i + 1][j + 1] = pref[i + 1][j] + pref[i][j + 1] - pref[i][j] + cost(G[i][j]);
		}
	}
	int cnt = 0;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (G[i][j] == 'M') {
				if (pref[min(i + 1 + D, R)][min(j + 1 + D, C)] - pref[min(i + 1 + D, R)][max(j - D, 0)] - pref[max(i - D, 0)][min(j + 1 + D, C)] + pref[max(0, i - D)][max(0, j - D)] >= K) {
					cnt++;
				}
			}
		}
	}
	return cnt;
}

int cost(char c) {
	if (c == '*') return 1;
	else return 0;
}

int main() {
	int n, q;
	cin >> n >> q;
	vector<string> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	vvi pref(n + 1, vi(m + 1, 0));
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			pref[i + 1][j + 1] = pref[i + 1][j] + pref[i][j + 1] - pref[i][j] + cost(G[i][j]);
		}
	}
	int i, j;
	for (int t = 0; t < q; t++) {
		cin >> i >> j;
		i--; j--;
		cout << pref[min(i + 1 + D, R)][min(j + 1 + D, C)] - pref[min(i + 1 + D, R)][max(j - D, 0)] - pref[max(i - D, 0)][min(j + 1 + D, C)] + pref[max(0, i - D)][max(0, j - D)] << endl;
	}
}