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
#define vpii vector<pii>
#define mp make_pair
#define vvpii vector<vector<pii>>
#define all(x) x.begin(), x.end()
const int INF = 2e18, MOD = 1e9 + 7;

ll findlongestdecreasingsubsecuence(int n, vector<ll> v) {
	ll longest = 0;
	vector<ll> a(n + 1, INF);
	for (int i = 0; i < n; i++) {
		ll lo = 1, hi = longest + 1;
		while (lo < hi) {
			int mid = (lo + hi) / 2;
			if (v[i] > a[mid]) hi = mid;
			else lo = mid + 1;
		}
		a[lo] = v[i];
		longest = max(longest, lo);
	}
	return longest;
}

int main()
{
	ll N, T, a, b, ans = 0; cin >> N >> T;
	vector<ll> pos(N);
	for (int i = 0; i < N; i++) {
		cin >> a >> b;
		pos[i] = a + (b * T);
	}
	cout << findlongestdecreasingsubsecuence(N, pos) << endl;
}