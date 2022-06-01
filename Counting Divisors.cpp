#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

typedef long long ll;

vector<ll> primeFactors(ll n){
	vector<ll> v;
	while (n % 2 == 0) {
		v.push_back(2);
		n /= 2;
	}
	for (ll i = 3; i <= sqrt(n); i += 2){
		while (n % i == 0){
			v.push_back(i);
			n /= i;
		}
	}
	if (n>2) v.push_back(n);
	return v;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n,k; cin >> n;
	for (ll i = 0; i < n; i++) {
		cin >> k;
		if (k == 1) cout << 1 << " ";
		else {
			ll cnt = 1;
			vector<ll> v = primeFactors(k);
			vector<ll> v1;
			ll retzef = 1;
			for (ll j = 0; j < v.size()-1; j++) {
				if (v[j] == v[j + 1]) retzef++;
				else { 
					v1.push_back(retzef);
					retzef = 1; 
				}
			}
			v1.push_back(retzef);
			for (int a = 0; a < v1.size(); a++) {
				cnt *= (v1[a] + 1);
			}
			cout << cnt << endl;
			v1.clear();
		}
	}
}