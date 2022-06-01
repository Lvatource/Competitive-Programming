#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int sum = 0;
	int answer = 1;
	int power = 1;
	while (answer != 0) {
		sum = sum + answer;
		answer = n / pow(5, power);
		power++;
	}
	cout << sum - 1 << endl;
}