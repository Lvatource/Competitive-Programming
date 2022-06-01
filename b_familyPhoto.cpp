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
	vi family(N);
	vi sortedfamily(N);
	if (N == 2) {
		cout << 1 << endl;
	}
	else {
		for (int i = 0; i < N; i++) {
			cin >> cur;
			family[i] = cur;
			sortedfamily[i] = cur;
		}
		sort(sortedfamily.begin(), sortedfamily.end());
		bool same = true;
		for (int i = 0; i < N; i++) {
			if (family[i] != sortedfamily[i]) same = false;
		}
		if (same) {
			cout << 0 << endl;
		}
		else {
			int pointer1 = 0;
			int pointer2 = N - 1;
			while (family[pointer1] == sortedfamily[pointer1]) {
				pointer1++;
			}
			while (family[pointer2] == sortedfamily[pointer2]) {
				pointer2--;
			}
			int doubles = 0;
			for (int i = pointer1; i < pointer2; i++) {
				if (family[i] == family[i + 1]) doubles++;
			}
			cout << pointer2 - pointer1 - doubles << endl;
		}
	}
}