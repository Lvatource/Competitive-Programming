#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int current;
	long pile1 = 0;
	long pile2 = 0;
	long answer = 0;
	if (n % 2 == 0) {
		for (int i = 0; i < n; i++) {
			cin >> current;
			if (i % 2 == 0) {
				pile1 = pile1 + current;
			}
			if (i % 2 == 1) {
				pile2 = pile2 + current;
			}
		}
		answer = (pile1 > pile2) ? pile1 : pile2;
		cout << pile1 << " " << pile2 << endl;
		cout << answer << endl;
	}
	if (n % 2 == 1) {
		int first;
		int last;
		for (int i = 0; i < n; i++) {
			cin >> current;
			if (i % 2 == 0) {
				pile1 = pile1 + current;
			}
			if (i % 2 == 1) {
				pile2 = pile2 + current;
			}
			if (i == 0) {
				first = current;
			}
			if (i == n - 1) {
				last = current;
			}
		}
		if (first > last) {
			answer = answer + first;
			if ((pile1 - first) > pile2) {
				answer = answer + pile2;
			}
			else {
				answer = answer + pile1 - first;
			}
		}
		if (first < last) {
			answer = answer + last;
			if ((pile1 - last) > pile2) {
				answer = answer + pile2;
			}
			else {
				answer = answer + pile1 - last;
			}
		}
		if (first == last) {
			if (pile2 > pile1) {
				answer = last + pile1;
			}
			else {
				answer = first + pile2;
			}
		}
		cout << answer << endl;
	}
}