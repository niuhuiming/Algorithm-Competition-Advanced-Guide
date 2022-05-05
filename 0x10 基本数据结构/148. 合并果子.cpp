#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
const int N = 10010;

int n;
priority_queue<int, vector<int>, greater<int>> q;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		q.push(x);
	}
	int res = 0;
	while (q.size() > 1) {
		int t = q.top();
		q.pop();
		int p = q.top();
		q.pop();
		res += t + p;
		q.push(t + p);
	}
	cout << res << endl;
	return 0;
}
