#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
typedef long long ll;
const int N = 1000010;

int primes[N], pcnt;
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
	int n;
	cin >> n;
	get_primes(n);
	for (int i = 0; i < pcnt; i++) {
		int p = primes[i];
		int s = 0;
		for (int j = p; j <= n; j *= p) {
			s += (n / j);
			if (j > n / p) break;
		} 
		cout << p << ' ' << s << endl;
	} 
	return 0;
}
