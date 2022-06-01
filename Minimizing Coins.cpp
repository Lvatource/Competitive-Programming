#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solve(int sum, vector<int> coins, vector<int> value) {
	value[0] = 0;
	for (int i = 1; i <= sum; i++) {
		value[i] = 1000001;
		for (auto c : coins) {
			if (i - c >= 0) {
				value[i] = min(value[i], value[i - c] + 1);
			}
		}
	}
	if (value[sum] != 1000001) {
		return value[sum];
	}
	else {
		return -1;
	}
}

int main()
{
	int n, sum, current;
	cin >> n;
	cin >> sum;
	vector<int> coins(n);
	vector<int> value(sum + 1);
	for (int i = 0; i < n; i++) {
		cin >> current;
		coins.push_back(current);
	}
	cout << solve(sum, coins, value) << endl;
}