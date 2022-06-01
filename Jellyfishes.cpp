#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <utility>
#include <set>
#include <string>
#include <set>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>
#define pb push_back
#define ll long long
#define MAXN 410

vvi maximum(MAXN, vi(MAXN, INT_MIN));

int findMax(vi &vec, int start, int end) {
	if (maximum[start][end] != INT_MIN) {
		return maximum[start][end];
	}
	int max, cur;
	max = INT_MIN;
	for (int i = start; i < end+1; i++) {
		if (vec[i] > max) max = vec[i];
	}
	maximum[start][end] = max;
	return max;
}

int main()
{
	ios::sync_with_stdio(0);
	int N, K, cur;
	ll sum = 0;
	cin >> N >> K;
	vi jellyfish(N);
	vvi value(N, vi(K+1));
	for (int i = 0; i < N; i++) {
		cin >> cur;
		jellyfish[i] = cur;
		sum += cur;
	}
	for (int j = 0; j < K+1; j++) {
		value[0][j] = jellyfish[0];
	}
	for (int i = 0; i < N; i++) {
		value[i][0] = findMax(jellyfish, 0, i)*(i+1);
	}
	for (int i = 1; i < N; i++) {
		for (int j = 1; j < K + 1; j++) {
			int min = INT_MAX;
			for (int u = 1; u <= i; u++) {
				int mispar = value[u - 1][j - 1] + findMax(jellyfish, u, i)*(i-u+1);
				if (mispar < min) min = mispar;
			}
			value[i][j] = min;
		}
	}
	cout << value[N-1][K] - sum << endl;
}