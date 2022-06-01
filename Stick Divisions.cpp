#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int x, n;
	cin >> x;
	cin >> n;
	int sum = 0;
	int arr[200000];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	for (int i = n-1; i > 0; i--) {
		sum = sum + x;
		x = x - arr[i];
	}
	cout << sum << endl;
}