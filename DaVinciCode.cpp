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

bool DecodeDaVinci(vector<vector<char>> T, int n, int m, vector<vector<char>> M, int a, int b) {
	vector<pii> positions;
	bool first = true;
	int rx, ry;
	for (int i = 0; i < a; i++) {
		for (int j = 0; j < b; j++) {
			if (M[i][j] == 'x') {
				if (first) {
					rx = j;
					ry = i;
					first = false;
				}
				positions.pb(mp(i - ry, j - rx));
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (T[i][j] == 'x') {
				for (int z = 0; z < positions.size(); z++) {
					if ((i + positions[z].first) < n && (i + positions[z].first) > -1 && (j + positions[z].second) < m && (j + positions[z].second) > -1) {
						if (T[i + positions[z].first][j + positions[z].second] == 'x') {
							T[i + positions[z].first][j + positions[z].second] = '.';
						}
						else {
							return false;
						}
					}
					else {
						return false;
					}
				}
			}
		}
	}
	return true;
}