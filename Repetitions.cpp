#include <iostream>
#include <string>
using namespace std;

int main()
{
	string n;
	cin >> n;
	int len = n.length();
	int current = 1;
	int max = 0;
	char latest = ' ';
	int left = 0;
	for (int i = 0; i < len; i++) {
		left++;
		if (n.at(i) == latest) {
			current++;
			/*if (i = len - 1) {
				max = (current > max) ? current : max;
			}*/
		}
		else {
			max = (current > max) ? current : max;
			current = 1;
		}
		latest = n.at(i);
		if (left = len) {
			max = max = (current > max) ? current : max;
		}
	}
	cout << max << endl;
}