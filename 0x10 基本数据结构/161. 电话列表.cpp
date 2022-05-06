#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long ll;
const int N = 100010;

int n;
int son[N][10], idx;
bool f[N];

bool insert(string s) {
	int p = 0;
	bool has_new = false;
	bool has_found = false;
	for (int i = 0; i < s.size(); i++) {
		int u = (s[i] - '0');
		if (son[p][u] == 0) {
			has_new = true;
			son[p][u] = ++idx;
		}
		p = son[p][u];
		if (f[p]) has_found = true;
	}
	f[p] = true;
	return has_new & !has_found;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		idx = 0;
		memset(f, false, sizeof f);
		memset(son, 0, sizeof son);
		
		cin >> n;
		bool succ = true;
		for (int i = 0; i < n; i++) {
			string s;
			cin >> s;
			if (!insert(s)) succ = false;
		}
		if (succ) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
} 
