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

bool ok(long R, vector<ll> flowers, long K) {
	ll lastflower = flowers[0];
	ll lastindex = 0;
	for (int i = 0; i < K; i++) {
		for (int j = lastindex; j < flowers.size(); j++) {
			if (flowers[j] <= lastflower + R + R) {
				if (j == flowers.size() - 1) return true;
			}
			else {
				lastflower = flowers[j];
				lastindex = j;
				break;
			}
		}
	}
	return false;
}

int main()
{
	ll N, K, cur;
	cin >> N >> K;
	vector<ll> flowers;
	for (int i = 0; i < N; i++) {
		cin >> cur;
		flowers.pb(cur);
	}
	sort(flowers.begin(), flowers.end());
	ll l = 0;
	ll r = ceil(((flowers[N - 1] - flowers[0]) / K));
	ll mid;
	ll ans = r;
	while (l < r) {
		if (r - l <= 2) {
			if (ok(r, flowers, K)) ans = r;
			if (ok(l + 1, flowers, K)) ans = l + 1;
			if (ok(l, flowers, K)) ans = l;
			break;
		}
		mid = (l + r) / 2;
		if (ok(mid, flowers, K)) {
			ans = mid;
			r = mid;
		}
		else {
			l = mid;
		}
	}
	cout << ans << endl;
}