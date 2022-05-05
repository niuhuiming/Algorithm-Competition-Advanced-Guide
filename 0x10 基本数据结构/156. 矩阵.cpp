#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <unordered_set>
using namespace std;
typedef unsigned long long ull;
const int N = 1010, M = N * N, P = 13331;

int n, m, a, b;
ull f[N][N], p[M];

ull get(ull f[], int l, int r) {
	return f[r] - f[l - 1] * p[r - l + 1];
}

int main() {
	cin >> m >> n >> a >> b;
	p[0] = 1;
	for (int i = 1; i <= m * n; i++) {
		p[i] = p[i - 1] *P;
	}
	for (int i = 1; i <= m; i++) {
		char str[N] = {0};
		cin >> (str + 1);
		for (int j = 1; j <= n; j++) {
			f[i][j] = f[i][j - 1] * P + (str[j] - '0'); 
		}
	}
	unordered_set<ull> hash;
	for (int i = b; i <= n; i++) {
		ull s = 0;
		int l = i - b + 1, r = i;
		for (int j = 1; j <= m; j++) {
			s = s * p[b] + get(f[j], l, r);
			if (j > a) s -= (get(f[j - a], l, r) * p[a * b]);
			if (j >= a) {
				hash.insert(s);
			}
		}
	}
	
	int k;
	cin >> k;
	while (k--) {
		ull s = 0;
		for (int i = 1; i <= a; i++) {
			char str[N] = {0};
			cin >> (str + 1);
			for (int j = 1; j <= b; j++) {
				s = s * P + (str[j] - '0');
			}
		}
		if (hash.count(s)) cout << 1 << endl;
		else cout << 0 << endl;
	}
	return 0;
} 
