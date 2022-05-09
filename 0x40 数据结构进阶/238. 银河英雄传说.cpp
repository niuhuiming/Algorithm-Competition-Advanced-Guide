#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long ll;
const int N = 30010;

int fa[N], d[N], si[N];

int find(int x) {
	if (x != fa[x]) {
		int gra = find(fa[x]);
		d[x] += d[fa[x]];
		fa[x] = gra;
	}
	return fa[x];
}

int main() {
	for (int i = 0; i < N; i++) {
		si[i] = 1;
		fa[i] = i;
	}
	
	int t;
	cin >> t;
	while (t--) {
		string s;
		int x, y;
		cin >> s >> x >> y;
		if (s[0] == 'M') {
			x = find(x);
			y = find(y);
			d[x] = si[y];
			si[y] += si[x];
			fa[x] = y;
		} else {
			int fax = find(x);
			int fay = find(y);
			if (fax != fay) {
				cout << -1 << endl;
			} else {
				cout << max(0, abs(d[x] - d[y]) - 1) << endl;
			}
		}
	}
	return 0;
}

