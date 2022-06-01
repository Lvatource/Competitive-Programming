#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <utility>
#include <set>
using namespace std;

#define vi vector<int>
#define pb push_back

int main()
{
	long long N, current;
	cin >> N;
	vector<vi> grid(N);
	set<int> options;
	set<int> validoptions;
	for (int i = 0; i < N; i++) {
		vi row(N);
		cin >> current;
		for (int j = 0; j < N; j++) {
			row[j] = (current % 10);
			current /= 10;
		}
		for (int j = N-1; j >= 0; j--) {
			grid[i].pb(row[j]);
			options.insert(grid[i][N-1-j]);
			validoptions.insert(grid[i][N-1-j]);
		}
	}
	options.erase(0);
	validoptions.erase(0);
	for (int num : options) {
		int rightest = 0;
		int leftest = 9;
		int highest = 9;
		int lowest = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (grid[i][j] == num) {
					if (i > lowest) {
						lowest = i;
					}
					if (i < highest) {
						highest = i;
					}
					if (j > rightest) {
						rightest = j;
					}
					if (j < leftest) {
						leftest = j;
					}
				}
			}
		}
		for (int i = highest; i <= lowest; i++) {
			for (int j = leftest; j <= rightest; j++) {
				if (grid[i][j] != num) {
					validoptions.erase(grid[i][j]);
				}
			}
		}
	}
	cout << validoptions.size() << endl;
}