#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
const int N = 10010;

int n;
pair<int, int> g[N];
priority_queue<int, vector<int>, greater<int>> q;

int main() {
	while (cin >> n) {
		for (int i = 0; i < n; i++) {
			cin >> g[i].second >> g[i].first;
		}
		sort(g, g + n);
		for (int i = 0; i < n; i++) {
			q.push(g[i].second);
			if (q.size() > g[i].first) {
				q.pop();
			}
		}
		
		int res = 0;
		while (q.size()) {
			res += q.top();
			q.pop();
		}
		cout << res << endl;
	}
	return 0;
}
