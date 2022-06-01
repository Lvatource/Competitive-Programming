#include <iostream>
using namespace std;

int main()
{
	int a, b;
	cin >> a;
	cin >> b;
	int sum = 0;
	while (a + b != 2) {
		if (a == b) {
			sum++;
			a = 1;
			b = 1;
		}
		if (a > b) {
			a = a - b;
			sum++;
		}
		if (a < b) {
			b = b - a;
			sum++;
		}
	}
	cout << sum << endl;
}