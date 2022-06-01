#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
	int n;
	int current;
	cin >> n;
	vector<int> apples(n);
	for (int i = 0; i < n; i++) {
		cin >> current;
		apples[i] = current;
	}
	sort(apples.begin(), apples.end());
	int pile1 = 0;
	int pile2 = 0;
	for (int i = n - 1; i >= 0; i--) {
		if (pile1 < pile2) {
			pile1 += apples[i];
		}
		else {
			pile2 += apples[i];
		}
	}
	cout << abs(pile1 - pile2) << endl;
}