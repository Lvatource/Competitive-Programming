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

int Crystal(int N, vi x, vi y, vi r) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < i; j++) {
			if (((x[i] - x[j])*(x[i] - x[j]) + (y[i] - y[j])*(y[i] - y[j])) >= ((r[i] * r[i]) + (r[j] * r[j]))) return i + 1;
		}
	}
	return -1;
}