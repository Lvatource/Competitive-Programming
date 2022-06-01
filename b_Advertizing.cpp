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

int N, K;

bool ok(long long target, vector<ll> cars) {
	int sum = 0;
	for (int i = N / 2; i < N; i++) {
		if (cars[i] < target) {
			sum += target - cars[i];
		}
		else {
			break;
		}
	}
	return sum <= K;
}

int main()
{
	cin >> N >> K;
	long long cur;
	vector<ll> cars;
	for (int i = 0; i < N; i++) {
		cin >> cur;
		cars.pb(cur);
	}
	sort(cars.begin(), cars.end());
	long long r, l, mid, ans;
	l = cars[0];
	r = cars[N - 1] + K;
	ans = cars[0];
	while (l < r) {
		if ((r - l) <= 2) {
			if (ok(l, cars)) ans = l;
			if (ok(l + 1, cars)) ans = l + 1;
			if (ok(r, cars)) ans = r;
			break;
		}
		mid = (l + r) / 2;
		if (ok(mid, cars)) {
			l = mid + 1;
			ans = mid;
		}
		else {
			r = mid - 1;
		}
	}
	cout << ans << endl;
}