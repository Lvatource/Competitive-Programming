#include <iostream>
#include <vector>
using namespace std;

long long Dice(int n, vector<long long> vi) {
	for (int i = 8; i <= n; i++) {
		vi.push_back((((2 * vi[i - 1] - vi[i - 7]) % 1000000007) + 1000000007) % 1000000007);
	}
	return vi[n];
}

int main()
{
	int n;
	cin >> n;
	vector<long long> vi;
	vi.push_back(0);
	vi.push_back(1);
	vi.push_back(2);
	vi.push_back(4);
	vi.push_back(8);
	vi.push_back(16);
	vi.push_back(32);
	vi.push_back(63);
	cout << Dice(n, vi);
}