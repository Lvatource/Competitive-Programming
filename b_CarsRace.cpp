#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <utility>
using namespace std;

#define vi vector<int>
#define pb push_back

int main()
{
	long long L, N, M, S, points, distance, total = 0, location = 0, past = 0;
	cin >> L;
	cin >> N;
	cin >> M;
	cin >> S;
	vector<pair<long long, long long>> stations(N);
	for (long long i = 0; i < N; i++) {
		cin >> distance;
		cin >> points;
		stations[i].first = points;
		stations[i].second = distance;
	}
	sort(stations.begin(), stations.end());
	long long i = N - 1;
	while (i > -1) {
		if (location < stations[i].second) {
			location = stations[i].second;
			total += stations[i].first * ((location - past)*(M - S));
			past = location;
		}
		i--;
	}
	cout << total << endl;
}