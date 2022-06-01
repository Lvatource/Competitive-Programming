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
	int N, K, cur;
	cin >> N >> K;
	vi contests(N);
	int start, end;
	for (int i = 0; i < N; i++) {
		cin >> cur;
		contests[i] = cur;
		if (cur == 1) {
			start = i+1;
		}
		if (cur == K) {
			end = i+1;
		}
	}
	int current = 0;
	int counter = 0;
	bool win = false;
	while (!win) {
		current++;
		if (current == K) {
			win = true;
		}
		bool found = false;
		for (int i = 0; i < N; i++) {
			if (contests[i] == current) {
				found = true;
			}
			if (found && (contests[i] == current + 1)) {
				current++;
				if (current == K) {
					win = true;
				}
			}
		}
		counter++;
	}
	cout << (N * (counter)) - (N - end) - (start - 1) << endl;
}