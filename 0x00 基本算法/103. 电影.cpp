#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>
using namespace std;
typedef long long ll;
const int N = 200010;

int n, m;
int a[N], b[N], c[N];
map<int, int> mp;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		mp[a[i]]++;
	} 
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> b[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> c[i];
	}
	int cnt1 = -1, cnt2 = -1, cnt3 = -1;
	for (int i = 0; i < m; i++) {
		cnt1 = max(cnt1, mp[b[i]]);
	}
	int res = -1; 
	for (int i = 0; i < m; i++) {
		if (mp[b[i]] < cnt1) continue;
		if (cnt2 < mp[c[i]]) {
			cnt2 = mp[c[i]];
			res = i;
		}
	}
	cout << res + 1 << endl;
	return 0;
} 
