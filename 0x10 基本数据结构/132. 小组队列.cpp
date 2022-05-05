#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <queue>
#include <map>
using namespace std;
typedef long long ll;
const int N = 1010;

int t;
 
int main() {
	int cnt = 0;
	while (cin >> t, t) {
		map<int, int> mp;
		for (int i = 1; i <= t; i++) {
			int n;
			cin >> n;
			while (n--) {
				int x;
				cin >> x;
				mp[x] = i;
			}
		}
		cout << "Scenario #" << ++cnt << endl;
		queue<int> team;
		queue<int> member[N];
		string op;
		while (cin >> op, op[0] != 'S') {
			if (op[0] == 'E') {
				int x;
				cin >> x;
				int teamId = mp[x];
				if (member[teamId].empty()) {
					team.push(teamId);
				}
				member[teamId].push(x);
			} else {
				int teamId = team.front();
				cout << member[teamId].front() << endl;
				member[teamId].pop();
				if (member[teamId].empty()) team.pop();
			}
		}
		cout << endl;
	}
	return 0;
} 
