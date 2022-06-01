#include "pch.h"
#include <iostream>
using namespace std;

int main()
{
	int t;
	long y, x;
	long dy = 1, dx = 1;
	int target = 2;
	long long cost = 1;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> y;
		cin >> x;
		while (dx != x || dy != y) {
			dx = target;
			cost = cost + target - dx;
			if (dx >= x && dy == y) {
				cost = cost - (dx - x);
				break;
			}
			dy = target;
			cost = cost + target - dy;
			if (dy >= y && dx == x) {
				cost = cost - (dy - y);
				break;
			}
			dx = 1;
			target++;
			dy = target;
			cost = cost + target - dy;
			if (dy >= y && dx == x) {
				cost = cost - (dy - y);
				break;
			}
		}
		cout << cost << endl;
		cost = 1;
	}
}