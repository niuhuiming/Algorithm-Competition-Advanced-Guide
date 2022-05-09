#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <unordered_map>
using namespace std;
typedef long long ll;
const int N = 2000010;

struct Node {
	int x, y, e;
};

int n, m;
int fa[N];
unordered_map<int, int> S;
Node query[N];

int get(int x) {
	if (S.count(x) == 0) S[x] = ++n;
	return S[x];
}

int find(int x) {
	if (x == fa[x]) return x;
	return fa[x] = find(fa[x]);
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		n = 0;
		S.clear();
		cin >> m;
		for (int i = 0; i < m; i++) {
			int x, y, e;
			cin >> x >> y >> e;
			query[i] = {get(x), get(y), e};
		}
		for (int i = 1; i <= n; i++) {
			fa[i] = i;
		}
		for (int i = 0; i < m; i++) {
			if (query[i].e == 1) {
				int pa = find(query[i].x);
				int pb = find(query[i].y);
				fa[pa] = pb;
			}
		}
		
		bool has_confight = false;
		for (int i = 0; i < m; i++) {
			if (query[i].e == 0) {
				int pa = find(query[i].x);
				int pb = find(query[i].y);
				if (pa == pb) {
					has_confight = true;
					break;
				}
			}
		}
		if (has_confight) cout << "NO" << endl;
		else cout << "YES" << endl;
	}
	return 0;
} 
