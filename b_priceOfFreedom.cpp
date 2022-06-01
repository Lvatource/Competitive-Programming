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
const int INF = 2e18, MOD = 1e9 + 7;

int main() {
	int n, y = 0;
	ll sum = 0;
	cin >> n;
	vvi A(n + 1);
	int a, b;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		A[a].pb(b);
	}
	vi z(n + 1);
	z[0] = 0;
	for (int i = 1; i <= n; i++) {
		z[i] = z[i - 1] + A[i - 1].size();
	}
	int cnt = 0;
	multiset<int> ms;
	for (int j = n; j >= 0; j--) {
		cnt = 0;
		for (int i = 0; i < A[j].size(); i++) {
			ms.insert(A[j][i]);
		}
		for (int i = 0; i < j - (y + z[j]); i++) {
			if (!ms.empty()) {
				int minimum = *ms.begin();
				sum += minimum;
				cnt++;
				ms.erase(ms.begin());
			}
		}
		y += cnt;
	}
	cout << sum << endl;
	return 0;
}
