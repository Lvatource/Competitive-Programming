#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <utility>
#include <set>
#include <string>
#include <queue>
#include <tuple>
#include "MoneyHeist.h"
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

void CrackTheSafe() {
	vi p;
	vi a;
	int first, second, third, last;
	bool ffirst = false, fsecond = false, fthird = false, flast = false;
	for (int i = 0; i < 10; i++) {
		for (int t = 0; t < 16; t++) {
			a[t] = 0;
		}
		for (int j = 0; j < 4; j++) {
			if (j == 0) {
				if (!ffirst) {
					for (int t = 0; t < 4; t++) {
						p[t] = 0;
					}
					p[j] = 1;
					a[i] = 1;
					if (i <= 5) a[i + 10] = 1;
					if (Check(p, a)) {
						first = i;
						ffirst = true;
					}
				}
			}
			if (j == 1) {
				if (!fsecond) {
					for (int t = 0; t < 4; t++) {
						p[t] = 0;
					}
					p[j] = 1;
					a[i] = 1;
					if (i <= 5) a[i + 10] = 1;
					if (Check(p, a)) {
						second = i;
						fsecond = true;
					}
				}
			}
			if (j == 2) {
				if (!fthird) {
					for (int t = 0; t < 4; t++) {
						p[t] = 0;
					}
					p[j] = 1;
					a[i] = 1;
					if (i <= 5) a[i + 10] = 1;
					if (Check(p, a)) {
						third = i;
						fthird = true;
					}
				}
			}
			if (j == 3) {
				if (!flast) {
					for (int t = 0; t < 4; t++) {
						p[t] = 0;
					}
					p[j] = 1;
					a[i] = 1;
					if (i <= 5) a[i + 10] = 1;
					if (Check(p, a)) {
						last = i;
						flast = true;
					}
				}
			}
		}
	}
	p[0] = first;
	p[1] = second;
	p[2] = third;
	p[3] = last;
	ReturnPassword(p);
}