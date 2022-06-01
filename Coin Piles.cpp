#include <iostream>
#include <string>
using namespace std;

int main()
{
	int t, a, b;
	cin >> t;
	int fuck[100000];
	for (int i = 0; i < t; i++) {
		cin >> a;
		cin >> b;
		if ((a + b) % 3 == 0 && a - b <= b && b - a <= a) {
			fuck[i] = 1;
		}
		else {
			fuck[i] = 2;
		}
	}
	for (int i = 0; i < t; i++) {
		if (fuck[i] == 1) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}
}