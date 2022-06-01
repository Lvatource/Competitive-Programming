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

int main()
{
	int N;
	int counter = 0;
	cin >> N;
	vi smurfs(N);
	for (int i = 0; i < N; i++) {
		cin >> smurfs[i];
		smurfs[i]--;
	}
	vvi seg(18, vi(N + 2, 0));
	for (int i = N - 1; i > 0; i--) {
		seg[0][smurfs[i]] = 1;
		if (smurfs[i] - smurfs[i - 1] < 0) {
			counter = i;
			break;
		}
	}
	vi ans(counter);
	cout << counter << endl;
	int jmax = N;
	for (int i = 1; i < 18; i++) {
		jmax /= 2;
		for (int j = 0; j < jmax + 1; j++) {
			seg[i][j] = seg[i - 1][j * 2] + seg[i - 1][j * 2 + 1];
		}
	}
	for (int i = 0; i < counter; i++) {
		int righti = smurfs[i];
		int j = 0;
		int sum = 0;
		while (righti > 0) {
			if (righti % 2 == 0) {
				sum += seg[j][righti];
				righti--;
			}
			righti /= 2;
			j++;
		}
		sum += seg[j][righti];
		seg[0][smurfs[i]] = 1;
		int tmp = smurfs[i];
		for (int i = 1; i < 18; i++) {
			tmp /= 2;
			seg[i][tmp] = seg[i - 1][tmp * 2] + seg[i - 1][tmp * 2 + 1];
		}
		ans[i] = sum + counter - i - 1;
	}
	for (int i = 0; i < counter; i++) {
		cout << ans[i] << " ";
	}
}