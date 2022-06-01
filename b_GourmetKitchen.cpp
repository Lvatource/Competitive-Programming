
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
	int N;
	cin >> N;
	vector<ll> sum(N);
	int min = INT_MAX;
	int mini = -1;
	long long cur;
	long long sumi = 0;
	for (int i = 0; i < N; i++) {
		cin >> cur;
		sumi += cur;
		sum[i] = sumi;
	}
	for (int i = 0; i < N-1; i++) {
		cin >> cur;
		cin >> cur;
	}
	for (int i = 0; i < N; i++) {
		if (i != 0) {
			if (max(sum[i - 1], sum[N - 1] - sum[i]) < min) {
				min = max(sum[i - 1], sum[N - 1] - sum[i]);
				mini = i;
			}
		}
		else {
			if (max((long long)0, sum[N - 1] - sum[i]) < min) {
				min = max((long long)0, sum[N - 1] - sum[i]);
				mini = i;
			}
		}
		
	}
	cout << mini << endl;
}