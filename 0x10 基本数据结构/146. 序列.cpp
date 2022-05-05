#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
const int N = 10010;
typedef pair<int, int> pii;

int n, m;
int a[N], b[N], c[N];

void merge() {
	priority_queue<pii, vector<pii>, greater<pii>> q;
	for (int i = 0; i < n; i++) {
		q.push({a[0] + b[i], 0});
	}
	for (int i = 0; i < n; i++) {
		int x = q.top().first;
		int idx = q.top.second;
		q.pop();
		q.push({x - a[idx] + a[idx + 1], idx + 1});
		c[i] = x;
	}
	for (int i = 0; i < n; i++) {
		a[i] = c[i];
	}
}


int main() {
	int T;
	cin >> T;
	while (T--) {
		cin >> m >> n;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		sort(a, a + n);
		for (int i = 0; i < m - 1; i++) {
			for (int j = 0; j < n; j++) {
				cin >> b[j];
			}
			merge();
		}
		for (int i = 0; i < n; i++) {
			cout << a[i] << ' ';
		}
		cout << endl;
	}
	return 0;
}
