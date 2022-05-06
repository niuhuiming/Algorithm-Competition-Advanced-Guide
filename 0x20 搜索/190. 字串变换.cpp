#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <queue>
#include <unordered_map>
using namespace std;
const int N = 6;

int n;
string a[N], b[N];

int extend(queue<string>& q, unordered_map<string, int>& da, unordered_map<string, int>& db, string a[], string b[]) {
	for (int k = 0, qs = q.size(); k < qs; k++) {
		string t = q.front();
		q.pop();
		for (int i = 0; i < t.size(); i++) {
			for (int j = 0; j < n; j++) {
				if (t.substr(i, a[j].size()) == a[j]) {
					string state = t.substr(0, i) + b[j] + t.substr(i + a[j].size());
					if (da.count(state)) continue;
					if (db.count(state)) return da[t] + 1 + db[state];
					da[state] = da[t] + 1;
					q.push(state);
				}
			} 
		}
	}
	return 11;
}

int bfs(string A, string B) {
	queue<string> qa, qb;
	unordered_map<string, int> da, db;
	qa.push(A), da[A] = 0;
	qb.push(B), db[B] = 0;
	while (qa.size() && qb.size()) {
		int t;
		if (qa.size() <= qb.size()) {
			t = extend(qa, da, db, a, b);
		} else {
			t = extend(qb, db, da, b, a);
		}
		if (t <= 10) return t;
	}
	return 11;
}

int main() {
	string A, B;
	cin >> A >> B;
	if (A == B) {
	    cout << 0 << endl;
	    return 0;
	}
	while (cin >> a[n] >> b[n]) {
		n++;
	}
	
	int step = bfs(A, B);
	if (step > 10) cout << "NO ANSWER!" << endl;
	else cout << step << endl;
	return 0;
}
