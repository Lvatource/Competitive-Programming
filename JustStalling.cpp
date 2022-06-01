#include "pch.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <utility>
#include <set>
#include <string>
using namespace std;

#define vi vector<int>
#define pb push_back
#define ll long long

long long factorial(int a) {
	if (a == 1) {
		return a;
	}
	return a * factorial(a - 1);
}

int main()
{
	int N, cur;
	cin >> N;
	vector<ll> cows(N);
	vector<ll> stalls(N);
	for (int i = 0; i < N; i++) {
		cin >> cur;
		cows[i] = cur;
	}
	for (int i = 0; i < N; i++) {
		cin >> cur;
		stalls[i] = cur;
	}
	long long answer = factorial(N);
	for (int i = 0; i < N; i++) {
		int amount = 0;
		for (int j = 0; j < N; j++) {
			if (cows[i] > stalls[j]) {
				amount++;
			}
		}
		answer -= amount * factorial(N - 1);
	}
	cout << answer << endl;
}