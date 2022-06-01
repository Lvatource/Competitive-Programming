#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <utility>
#include <set>
#include <string>
#include <queue>
#include <tuple>
#include <stack>
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
	int n;
	cin >> n;
	int w, h;
	stack<int> S;
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> w >> h;
		while (h < S.top()) {
			S.pop();
			ans++;
		}
		if (h > S.top()) {
			S.push(h);
		}
	}
	cout << ans << endl;
}