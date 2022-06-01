#include <iostream>
#include <vector>
using namespace std;

int solve(int sum, vector<int> value, vector<int> coins) {
	int m = 1000000007;
	for (int i = 1; i <= sum; i++) {
		for (auto c : coins) {
			if (i - c >= 0) {
				value[i] += value[i - c];
				value[i] %= m;
			}
		}
	}
	return value[sum];
}

int main()
{
	int num, sum, current;
	cin >> num;
	cin >> sum;
	vector<int> coins(num);
	vector<int> value(sum + 1);
	for (int i = 0; i < num; i++) {
		cin >> current;
		coins.push_back(current);
	}
	value[0] = 1;
	cout << solve(sum, value, coins) << endl;
}