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

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N, T, pos, speed;
	cin >> N >> T;
	vector<pair<int, int>> swimmers(N);
	for (int i = 0; i < N; i++) {
		cin >> pos >> speed;
		swimmers[i].first = pos;
		swimmers[i].second = speed;
	}
	vector<ll> ggg(N);
	for (int i = 0; i < N; i++) {
		ggg[i] = swimmers[i].first + ((swimmers[i].second)*T);
	}
	vector<ll> lanes(N, 0);
	lanes[0] = ggg[0];
	for (int i = 1; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (ggg[i] > lanes[j]) {
				;
				lanes[j] = ggg[i];
				break;
			}
		}
	}
	int answer = 0;
	int l = 0;
	int r = N - 1;
	while (l < r) {
		if (r - l <= 2) {
			if (lanes[r] == 0) answer = r;
			if (lanes[r - 1] == 0) answer = r - 1;
			if (lanes[l] == 0) answer = l;
			break;
		}
		else {
			int mid = (l + r) / 2;
			if (lanes[mid] == 0) {
				r = mid - 1;
			}
			else {
				l = mid + 1;
			}
		}
	}
	cout << answer << endl;
}