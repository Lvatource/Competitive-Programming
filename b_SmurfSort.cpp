#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

#define vi vector<int>
#define pb push_back

int main()
{
	int N, current, counter = 0;
	vi smurfs;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> current;
		smurfs.pb(current);
	}
	for (int i = N - 1; i >= 0; i--) {
		if (smurfs[i] - smurfs[i - 1] < 0) {
			counter = i;
			break;
		}
	}
	cout << counter << endl;
}
