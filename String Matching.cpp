#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	int occ = 0;
	string str;
	string patt;
	bool same = true;
	cin >> str;
	cin >> patt;
	int n = str.length();
	int m = patt.length();
	
	for (int i = 0; i <= n-m; i++) {
		if (str[i] == patt[0]) {
			for (int k = 1; k < m; k++) {
				if (str[k+i] != patt[k]) {
					same = false;
					break;
				}
			}
			if (same) {
				occ++;
			}
			same = true;
		}
	}
	cout << occ << endl;
}
//KMP ALGORITHM