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
	int N, a, b;
	cin >> N;
	vi judges(N + 1, 0);
	vector<pair<int, int>> bitcoin(N);
	int pointer = 0;
	int paid = 0;
	for (int i = 0; i < N; i++) {
		cin >> a;
		judges[a]++;
		cin >> b;
		bitcoin[i].first = a;
		bitcoin[i].second = b;
	}
	sort(bitcoin.begin(), bitcoin.end());
	int moves = 0;
	while (pointer < N) {
		moves += judges[pointer];
		if (moves > 0) {
			moves--;
			pointer++;
		}
		else {
			int min = bitcoin[N - 1].second;
			int am = bitcoin[N - 1].first;
			int index = N - 1;
			while (bitcoin[index].first == am) {
				if (bitcoin[index].second < min) {
					min = bitcoin[index].second;
				}
				index--;
			}
			paid += min;
			pointer++;
		}
	}
	cout << paid << endl;
}