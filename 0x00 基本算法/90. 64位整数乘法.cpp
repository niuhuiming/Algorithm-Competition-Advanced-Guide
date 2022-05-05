#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long ll;
const int N = 10010;

// 1 ¡Ü a, b, p ¡Ü 1e18
ll ksc(ll a, ll b, ll p) {
	ll res = 0ll;
	while (b) {
		if (b & 1) res = (res + a) % p;
		a = a * 2 % p;
		b >>= 1;
	}
	return res;
}

int main() {
	ll a, b, p;
	cin >> a >> b >> p;
	cout << ksc(a, b, p) << endl;
	return 0;
} 
