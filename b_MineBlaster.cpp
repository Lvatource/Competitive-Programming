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

typedef long long int63;
typedef pair<int63, int63> point;
typedef pair<double, double> dpoint;

double get_radius(vector<int> X, int N) {
	sort(all(X));
	vector<int63>lreq(N, 0);
	vector<int63>rreq(N, 0);
	int63 l = 0;
	for (int i = 1; i < N; i++) {
		if (X[i] - X[i - 1] >= lreq[i - 1] + 1) {
			lreq[i] = X[i] - X[i - 1];
			continue;
		}
		lreq[i] = lreq[i - 1] + 1;
		while (lreq[l] < lreq[i - 1]) {
			if (X[i] - X[l] <= lreq[l] + 1) {
				lreq[i] = lreq[i - 1];
				break;
			}
			else {
				l++;
			}
		}
	}
	int63 r = N - 1;
	for (int i = N-2; i >= 0; i--) {
		if (X[i + 1] - X[i] >= rreq[i + 1] + 1) {
			rreq[i] = X[i + 1] - X[i];
			continue;
		}
		rreq[i] = rreq[i + 1] + 1;
		while (rreq[r] < rreq[i + 1]) {
			if (X[r] - X[i] <= rreq[r] + 1) {
				rreq[i] = rreq[i + 1];
				break;
			}
			else {
				r--;
			}
		}
	}
	double ans = rreq[0];
	for (int i = 0; i < N; i++) {
		int63 lo = 0, hi = i, md;
		while (hi > lo) {
			md = hi + lo;
			md /= 2;
			if (max({ (double)lreq[md] + 1, (double)(X[i] - X[md]) * 0.5 }) < max({ (double)lreq[md + 1] + 1, (double)(X[i] - X[md + 1]) * 0.5 })) {
				hi = md;
			}
			else if (max({ (double)lreq[md] + 1, (double)(X[i] - X[md]) * 0.5 }) > max({ (double)lreq[md + 1] + 1, (double)(X[i] - X[md + 1]) * 0.5 })) {
				lo = md + 1;
			}
			else {
				if (lreq[md] < lreq[md + 1]) {
					lo = md + 1;
				}
				else {
					hi = md;
				}
			}
		}
		ans = min(ans, max({ (double)rreq[i] + 1, (double)lreq[lo] + 1, (double)(X[i] - X[lo]) * 0.5 }));
	}
	return ans;
}

int main() {
	ll n;
	cin >> n;
	vector<ll> mines(n);
	for (int i = 0; i < n; i++) {
		cin >> mines[i];
	}
	cout << get_radius(mines, n) << endl;
}