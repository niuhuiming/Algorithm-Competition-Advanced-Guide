#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <map>
using namespace std;
typedef long long ll;
const int N = 5010;

int n, p, h, m;
int height[N];
map<pair<int, int>, bool> mp;

int main() {
	cin >> n >> p >> h >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		if (a > b) swap(a, b);
		if (mp[{a, b}]) continue;
		mp[{a, b}] = true;
		height[a + 1]--;
		height[b]++;
	}
	for (int i = 1; i <= n; i++) {
	    height[i] += height[i - 1];
		cout << height[i] + h << endl;
	}
	return 0;
}
