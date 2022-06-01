#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;

int main()
{
	pair<int, int> Movies[200000];
	int n, current;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> current;
		Movies[i].second = current;
		cin >> current;
		Movies[i].first = current;
	}
	sort(Movies, Movies + n);
	int hour = Movies[0].first;
	int TotMovies = 1;
	for (int i = 1; i < n; i++) {
		if (Movies[i].second >= hour) {
			hour = Movies[i].first;
			TotMovies++;
		}
	}
	cout << TotMovies << endl;
}