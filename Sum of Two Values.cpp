#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n, low = 0, high, current;
	cin >> n;
	int x;
	cin >> x;
	vector<int> v(n);
	vector<int> temp(n);
	for (int i = 0; i < n; i++) {
		cin >> current;
		v[i] = current;
		temp[i] = current;
	}
	high = n - 1;
	sort(v.begin(), v.end());
	bool isFound = false;
	while (low < high) {
		if (v[low] + v[high] == x) {
			isFound = true;
			int small = v[low];
			int big = v[high];
			bool foundSmall = false;
			bool foundBig = false;
			int first, second;
			for (int i = 0; i < n; i++) {
				if (temp[i] == small && !foundSmall) {
					first = i + 1;
					foundSmall = true;
				}
				else if (temp[i] == big && !foundBig) {
					second = i + 1;
					foundBig = true;
				}
			}
			cout << first << " " << second << endl;
			break;
		}
		if (v[low] + v[high] < x) {
			low++;
		}
		if (v[low] + v[high] > x) {
			high--;
		}
	}
	if (!isFound) {
		cout << "IMPOSSIBLE" << endl;
	}
}