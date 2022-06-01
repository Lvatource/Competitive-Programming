#include <iostream>
#include <set>
using namespace std;

int main()
{
	set<int> s;
	int current, n;
	int sum = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> current;
		if (s.count(current) > 0) {
			sum++;
		}
		s.insert(current);
	}
	cout << n-sum << endl;
}