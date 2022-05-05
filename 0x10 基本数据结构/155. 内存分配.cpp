#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <queue>
#include <set>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int N = 1000010;

int n, t, m, p;
queue<pii> wait;	// 长度 占用时间 
set<pii> run;		// 起始下标 长度 
priority_queue<pii, vector<pii>, greater<pii>> q;	// 释放时间 起始下标 

int endtime, waitcnt;

bool give(int t, int m, int p) {
	for (auto it = run.begin(); it != run.end(); it++) {
		auto jt = it;
		jt++;
		if (jt != run.end()) {
			if (m <= (jt->first) - (it->first + it->second - 1) - 1) {
				int st = it->first + it->second;
				run.insert({st, m});
				q.push({t + p, st});
				return true;
			}
		}
	}
	return false;
}

void finish(int t) {
	while (q.size() && q.top().first <= t) {
		int f = q.top().first;
		while (q.size() && q.top().first == f) {
			int tt = q.top().second;
			run.erase(run.lower_bound({tt, 0}));
			q.pop();
		}
		endtime = f;
		while (wait.size()) {
			pii front = wait.front();
			if (give(f, front.first, front.second)) {
				wait.pop();
			} else {
				break;
			}
		}
	}
}

int main() {
	cin >> n;
	run.insert({-1, 1});
	run.insert({n, 1});
	while (cin >> t >> m >> p, t || m || p) {
		finish(t);
		if (!give(t, m, p)) {
			wait.push({m, p});
			waitcnt++;
		}
	}
	finish(2e9);
	cout << endtime << endl << waitcnt << endl;
	return 0;
} 
