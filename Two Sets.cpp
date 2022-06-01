#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	if (n % 4 == 0 || (n + 1) % 4 == 0) {
		int arr[1000000];
		int set1[500000];
		int set2[707106];
		long sum = 0;
		long num = 0;
		int index1 = 0, index2 = 0;
		for (int i = 0; i < n; i++) {
			arr[i] = i + 1;
			sum = sum + i + 1;
		}
		for (int i = n - 1; i >= 0; i--) {
			if (num + arr[i] <= sum / 2) {
				num = num + arr[i];
				set1[index1] = arr[i];
				index1++;
			}
			else {
				set2[index2] = arr[i];
				index2++;
			}
		}
		cout << "YES" << endl;
		cout << index1 << endl;
		for (int i = 0; i < index1; i++) {
			cout << set1[i] << " ";
		}
		cout << endl;
		cout << index2 << endl;
		for (int i = 0; i < index2; i++) {
			cout << set2[i] << " ";
		}
		cout << endl;
	}
	else {
		cout << "NO" << endl;
	}
}