#include <iostream>
using namespace std;

int main()
{
	int n, in;
	int sum = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		sum = sum + i;
	}
	for (int i = 0; i < n - 1; i++) {
		cin >> in;
		sum = sum - in;
	}
	cout << sum << endl;
}