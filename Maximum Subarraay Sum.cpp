#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n, current;
	long long sum = -1000000000;
	long long best = -1000000000;
	cin >> n;
	long long arr[200000];
	for (int i = 0; i < n; i++) {
		cin >> current;
		arr[i] = current;
	}
	for (int i = 0; i < n; i++) {
		sum = max(arr[i], arr[i] + sum);
		best = max(sum, best);
	}
	cout << best << endl;
}