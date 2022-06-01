#include "allstar.h"
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
#define pb push_back
#define ll long long
#define vvi vector<vi>
#define pii pair<int, int>
#define all(x) x.begin(),x.end()
const int INF = 2e18, MOD = 1e9 + 7;

tuple<int, int, int> GetReport() {
	int a = 1, b = 1, c = 1;
	for (int i = 0; i < 20; i++) {
		int p = CheckGuess(a, b, c);
		if (p == 1) a++;
		if (p == 2) b++;
		if (p == 3) c++;
	}
	auto t = make_tuple(a, b, c);
	return t;
}