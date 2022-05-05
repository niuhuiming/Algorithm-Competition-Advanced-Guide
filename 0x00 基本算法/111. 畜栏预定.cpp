#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
const int N = 50010;


int n;
pair<pii, int> ox[N];
priority_queue<pii, vector<pii>, greater<pii>> q;
int res[N];

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> ox[i].first.first >> ox[i].first.second;
		ox[i].second = i;
	}
	sort(ox, ox + n);
	
	for (int i = 0; i < n; i++) {
		if (q.empty() || ox[i].first.first <= q.top().first) {
			res[ox[i].second] = q.size();
			q.push({ox[i].first.second, q.size()});
		} else {
			res[ox[i].second] = q.top().second;
			q.pop();
			q.push({ox[i].first.second, res[ox[i].second]});
		}
	}
	cout << q.size() << endl;
	for (int i = 0; i < n; i++) {
		cout << res[i] + 1 << endl;
	}
	return 0;
} 
