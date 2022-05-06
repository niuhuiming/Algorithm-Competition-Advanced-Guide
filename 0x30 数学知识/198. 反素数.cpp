#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
typedef long long ll;
const int N = 10010;

int n;
int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
int minx, sum;

void dfs(int u, int last, int p, int s) {
	if (s > sum || s == sum && p < minx) {
		minx = p;
		sum = s;
	}
	for (int i = 1; i <= last; i++) {
		if ((ll)p * primes[u] > n) break;
		p *= primes[u];
		dfs(u + 1, i, p, s * (i + 1));
	} 
}

int main() {
	cin >> n;
	dfs(0, 30, 1, 1);
	cout << minx << endl;
	return 0;
}
