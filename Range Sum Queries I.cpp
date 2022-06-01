#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int q;
	cin >> q;
	long long sum = 0;
	vector<long long> sums(n);
	int current;
	for (int i = 0; i < n; i++) {
		cin >> current;
		sum += current;
		sums[i] = sum;
	}
	int a;
	int b;
	for (int i = 0; i < q; i++) {
		cin >> a;
		cin >> b;
		if (a == 1) {
			cout << sums[b - 1] << endl;
		}
		else {
			cout << sums[b - 1] - sums[a - 2] << endl;
		}
	}
}