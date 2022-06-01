#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n, m, k, current, x = 0, y = 0, sum = 0, lastUsed = 0;
	cin >> n;
	cin >> m;
	cin >> k;
	vector<int> applicants(n);
	vector<int> apartments(m);
	for (int i = 0; i < n; i++) {
		cin >> current;
		applicants[i] = current;
	}
	sort(applicants.begin(), applicants.end());
	for (int i = 0; i < m; i++) {
		cin >> current;
		apartments[i] = current;
	}
	sort(apartments.begin(), apartments.end());
	while (x < n && y < m) {
		if (apartments[y] <= (applicants[x] + k) && apartments[y] >= (applicants[x] - k)) {
			sum++;
			x++;
			lastUsed = y;
		}
		y++;
		if (y == m) {
			x++;
			y = lastUsed + 1;
		}
	}
	cout << sum << endl;
}