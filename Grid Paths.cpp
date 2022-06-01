#include "pch.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int arr[51][51] = {} ;
	string A[50][50];
	string current;
	for (int i = 0; i < n; i++) {
		cin >> current;
		for (int j = 0; j < n; j++) {
			A[i][j] = current[j];
		}
	}
	arr[1][1] = 1;
	for (int x = 1; x <= n; x++) {
		for (int y = 1; y <= n; y++) {
			if (A[y][x] == "*") {
				arr[y+1][x+1] = 0;
			}
			else {
				arr[y][x] = arr[y - 1][x] + arr[y][x - 1];
			}
		}
	}
	cout << arr[n][n] << endl;
}