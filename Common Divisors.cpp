#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int arr[200000];
	int current;
	int biggest = 0;
	for (int i = 0; i < n; i++) {
		cin >> current;
		arr[i] = current;
	}
	for (int i = 0; i < n; i++) {
		for (int k = i + 1; k < n; k++) {
			biggest = (__gcd(arr[i], arr[k]) > biggest) ? __gcd(arr[i], arr[k]) : biggest;
		}
	}
	cout << biggest << endl;
}
