#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int n;
	cin >> n;
	long long cum;
	for (int i = 1; i <= n; i++) {
		long k = i * i;
		cum = 4*(k-3) + 8*(k-4) + 4*(i-4)*(k-5) + 4*(k-5) + 4*(i-4)*(k-7) + (k-(8*i)+16)*(k-9);
		cout << cum/2 << endl;
	}
}