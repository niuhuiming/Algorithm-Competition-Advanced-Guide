#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
typedef long long ll;
const int N = 1000010;
const int M = 50000;

int primes[M], pcnt;
bool vis[N];
int arr[N];

void get_primes(int x) {
	for (int i=2;i<=x;i++) {
	    if(vis[i] == false) {
			primes[pcnt++] = i;
			for (int j = i; j <= x;j += i)
				vis[j] = true;
		}
	}
}

int main() {
	get_primes(M);
	ll l, u;
	while (cin >> l >> u) {
		memset(vis, false, sizeof vis);
		for (int i = 0; i < pcnt; i++) {
			int p = primes[i];
			for (ll j = max((l + p - 1ll) / p * p, 2ll * p); j <= u; j += p) {
				vis[j - l] = true;
			}
		}
		
		int cnt = 0;
		for (int i = 0; i <= u - l; i++) {
			if (vis[i] == false && i + l > 1) {
				arr[cnt++] = i + l;
			}
		} 
		if (cnt < 2) cout << "There are no adjacent primes." << endl;
		else {
			int minp = 0, maxp = 0;
			for (int i = 0; i < cnt - 1; i++) {
				int dis = arr[i + 1] - arr[i];
				if (dis < arr[minp + 1] - arr[minp]) {
					minp = i;
				}
				if (dis > arr[maxp + 1] - arr[maxp]) {
					maxp = i;
				}
			} 
			cout << arr[minp] << "," << arr[minp + 1] << " are closest, " << arr[maxp] << "," << arr[maxp + 1] << " are most distant." << endl;
		}
	} 
	return 0;
}
