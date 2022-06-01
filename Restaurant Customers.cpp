#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int firstEnt = 1000000001;
	int lastEnt = 0;
	long long a, b;
	vector<int> vi(2 * n);
	fill(vi.begin(), vi.end(), 0);
	int most = 0;
	int num = 0;
	for (int i = 0; i < n; i++) {
		cin >> a;
		cin >> b;
		firstEnt = (a < firstEnt) ? a : firstEnt;
		lastEnt = (a > lastEnt) ? a : lastEnt;
		vi[a]++;
		vi[b]--;
	}
	for (int i = firstEnt; i <= lastEnt; i++) {
		num = num + vi[i];
		most = (num > most) ? num : most;
	}
	cout << most << endl;
}