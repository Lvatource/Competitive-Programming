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
#define vvi vector<vi>

vi a;
vector<bool> check;
int count = 0;
void dfs(int cur) {
	if (check[cur]) {
		count++;
		return;
	}
	check[cur] = true;
	dfs(a[i]);
}

int main()
{
	int N, cur;
	cin >> N;
	check.resize(N, false);
	for (int i = 0; i < N; i++) {
		cin >> cur;
		a.pb(cur);
		check.pb(false);
	}
	for (int i = 0; i < N; i++) {
		if (!check[i]) {
			dfs(i);
		}
	}
	cout << count << endl;
}