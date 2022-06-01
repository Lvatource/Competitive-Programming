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
const int INF = 1e9 + 1e6, MOD = 1e9 + 7;

int MinSub(int N, int K, int T, vi P, vi B, vi Q) {
	int l = 0, r = 0;
	vi cnts(T, 0);
	int ans = INF;
	int sum = 0;
	vi rb(K, -1);
	for (int i = 0; i < T; i++) rb[B[i]] = i;
	if (rb[P[0]] > -1) {
		cnts[rb[P[0]]]++;
		if (Q[rb[P[0]]] == cnts[rb[P[0]]]) {
			sum++;
		}
	}
	while (r < N && l < N) {
		if (sum == T) {
			ans = min(ans, r - l + 1);
			if (rb[P[l]] > -1) {
				cnts[rb[P[l]]]--;
				if (cnts[rb[P[l]]] == (Q[rb[P[l]]] - 1)) sum--;
			}
			l++;
		}
		else {
			r++;
			if (rb[P[r]] > -1) {
				cnts[rb[P[r]]]++;
				if (cnts[rb[P[r]]] == Q[rb[P[r]]]) sum++;
			}
		}
	}
	if (ans == INF) return -1;
	return ans;
}