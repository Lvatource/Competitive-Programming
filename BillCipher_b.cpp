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
	ll N, K, a;
	char b;
	string word;
	cin >> N >> word >> K;
	ll l, reisha, seifa, mid;
	vll ans(K);
	vll p(word.size());
	vll lines(K);
	vector<char> ch(K);
	for (ll i = 0; i < K; i++) {
		cin >> lines[i] >> ch[i];
	}
	for (ll j = 0; j < 26; j++) {
		if (word[0] == j + 'A') {
			p[0] = 1;
		}
		else {
			p[0] = 0;
		}
		for (ll t = 1; t < word.size(); t++) {
			if (word[t] == j + 'A')
				p[t] = p[t - 1] + 1;
			else {
				p[t] = p[t - 1];
			}
		}
		for (ll i = 0; i < K; i++) {
			if (ch[i] == j + 'A') {
				if (lines[i] % 2 == 0) {
					l = ((lines[i] / 2) % word.size() * (lines[i] - 1) % word.size()) % word.size();
				}
				else {
					l = (lines[i] %word.size() * ((lines[i] - 1) / 2) % word.size()) % word.size();
				}
				if (word.size() - l >= lines[i]) {
					if (l == 0) {
						ans[i] = p[l + lines[i] - 1];
					}
					else {
						ans[i] = (p[l + lines[i] - 1] - p[l - 1]);
					}
				}
				else {
					if (l == 0) {
						seifa = p[word.size() - 1];
					}
					else {
						seifa = p[word.size() - 1] - p[l - 1];
					}
					mid = ((lines[i] - word.size() + l) / word.size()) * p[word.size() - 1];
					if ((lines[i] - word.size() + l) % word.size() > 0) {
						reisha = p[(lines[i] - word.size() + l) % word.size() - 1];
					}
					else
					{
						reisha = 0;
					}
					ans[i] = (reisha + mid + seifa);
				}
			}
		}
	}
	for (ll i = 0; i < K; i++) {
		cout << ans[i] << endl;
	}
}