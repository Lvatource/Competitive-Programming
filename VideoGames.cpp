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
#define pll pair<ll, ll>
#define vl vector<ll>
#define mp make_pair
#define vvpii vector<vector<pii>>
#define all(x) x.begin(), x.end()
const ll INF = 2e18, MOD = 1e9 + 7;

int main()
{
	ll n, k;
	cin >> n >> k;
	vl stands(n);
	vl shorter;
	shorter.pb(-(INF));
	for (int i = 0; i < n; i++) {
		cin >> stands[i];
	}
	int pindex = 0;
	for (int i = 0; i < n; i++) {
		if (stands[i] > 0) {
			pindex = i;
			break;
		}
	}
	ll tmp = stands[pindex];
	ll prev = stands[pindex];
	for (int i = pindex; i < n - 1; i++) {
		if (stands[i + 1] == 0) continue;
		if (prev * stands[i + 1] >= 0) {
			tmp += stands[i + 1];
		}
		else {
			shorter.pb(tmp);
			tmp = stands[i + 1];
		}
		prev = stands[i + 1];
	}
	shorter.pb(tmp);
	if (shorter[shorter.size() - 1] <= 0) {
		shorter.pop_back();
	}
	shorter.pb(-(INF));
	ll positives = (shorter.size() - 1) / 2;
	set<pll> ms;
	vl R(shorter.size());
	vl L(shorter.size());
	for (int i = 0; i < shorter.size(); i++) {
		auto t = mp(abs(shorter[i]), i);
		ms.insert(t);
		L[i] = i - 1;
		R[i] = i + 1;
	}
	R[shorter.size() - 1] = -1;
	while ((positives--) > k) {
		pll minimum = *(ms.begin());
		ms.erase(minimum);
		if (L[minimum.second] != -1) {
			pll left = mp(abs(shorter[L[minimum.second]]), L[minimum.second]);
			ms.erase(left);
			shorter[minimum.second] += shorter[L[minimum.second]];
			shorter[L[minimum.second]] = 0;
		} if (R[minimum.second] != -1) {
			pll right = mp(abs(shorter[R[minimum.second]]), R[minimum.second]);
			ms.erase(right);
			shorter[minimum.second] += shorter[R[minimum.second]];
			shorter[R[minimum.second]] = 0;
		}
		pll newp = mp(abs(shorter[minimum.second]), minimum.second);
		ms.insert(newp);
		if (L[minimum.second] != -1) {
			if (L[L[minimum.second]] != -1) {
				L[minimum.second] = L[L[minimum.second]];
				R[L[minimum.second]] = minimum.second;
			}
			else {
				L[minimum.second] = -1;
			}
		}
		if (R[minimum.second] != -1) {
			if (R[R[minimum.second]] != -1) {
				R[minimum.second] = R[R[minimum.second]];
				L[R[minimum.second]] = minimum.second;
			}
			else {
				R[minimum.second] = -1;
			}
		}
	}
	ll sum = 0;
	for (int i = 0; i < shorter.size(); i++) {
		if (shorter[i] > 0) {
			sum += shorter[i];
		}
	}
	cout << sum << endl;
}