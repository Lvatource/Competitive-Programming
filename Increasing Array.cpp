#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	long current;
	long long amount = 0;
	long arr[200000];
	for (int i = 0; i < n; i++) {
		cin >> current;
		arr[i] = current;
	}
	for (int i = 1; i < n; i++) {
		if (arr[i] < arr[i - 1]) {
			amount = amount + (arr[i - 1] - arr[i]);
			arr[i] = arr[i - 1];
		}
	}
	cout << amount;
}