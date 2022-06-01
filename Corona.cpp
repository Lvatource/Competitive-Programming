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

int main()
{
	int N, cur;
	cin >> N;
	vi virus(N);
	vi trip(N, -1);
	for (int i = 0; i < N; i++) {
		cin >> cur;
		virus[i] = cur;
	}
	for (int i = 1; i < N; i++) {
		int pointer = i;
		int len = 1;
		set<int> past;
		past.insert(i);
		while ((past.find(virus[pointer]) == past.end()) && (virus[pointer] != -1)) {
			past.insert(pointer);
			pointer = virus[pointer];
			len++;
		}
		if (virus[pointer] == -1) {
			trip[i] = len;
		}
	}
	int pointer = 0;
	int len = 1;
	set<int> past;
	past.insert(0);
	while ((past.find(virus[pointer]) == past.end()) && (virus[pointer] != -1)) {
		past.insert(pointer);
		pointer = virus[pointer];
		len++;
	}
	trip[0] = len;
	int max = -1;
	int maxi = -1;
	for (int i = 0; i < N; i++) {
		if (trip[i] > max) {
			maxi = i;
			max = trip[i];
		}
	}
	vector<bool> check(N, false);
	pointer = maxi;
	while (virus[pointer] != -1 && !check[pointer]) {
		check[pointer] = true;
		pointer = virus[pointer];
	}
	pointer = 0;
	int first = 0;
	while ((virus[pointer] != 0) && (virus[pointer] != -1) && (!check[virus[pointer]])) {
		first++;
	}
	cout << first + trip[maxi] << endl;
}