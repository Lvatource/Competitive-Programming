#include <iostream>
using namespace std;

int main()
{
	int N;
	int m = 1000000007;
	cin >> N;
	int ans = 1;
	for (int i = 0; i < N; i++) {
		ans = (ans * 2) % m;
	}
	cout << ans << endl;
}