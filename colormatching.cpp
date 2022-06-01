#include <iostream>
using namespace std;

int main()
{
	int n, m;
	cin >> n;
	cin >> m;
	int ssum = (n*(n - 1)*(n - 2)) / 6;
	int colora, colorb;
	int arr[200] = { 0 };
	for (int i = 0; i < m; i++) {
		cin >> colora;
		cin >> colorb;
		arr[colora - 1]++;
		arr[colorb - 1]++;
		ssum = ssum - (n - 2);
		if (arr[colora - 1] > 1) {
			ssum = ssum + (arr[colora - 1] - 1);
		}
		if (arr[colorb - 1] > 1) {
			ssum = ssum + (arr[colorb - 1] - 1);
		}
	}
	cout << ssum << endl;
}