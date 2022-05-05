#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <deque>
using namespace std;
typedef long long ll;
const int N = 10010;

deque<int> pk[14];
int pos[14];

void play(int x) {
	if (pk[x].empty()) return ;
	
	int t = pk[x].back();
	pk[x].pop_back();
	if (t == 13) return ;
	
	pos[t]++;
	play(t);
}

int main() {
	for (int i = 1; i <= 13; i++) {
		for (int j = 0; j < 4; j++) {
			string s;
			cin >> s;
			if ('2' <= s[0] && s[0] <= '9') pk[i].push_back((s[0] - '0'));
			else if (s[0] == 'A') pk[i].push_back(1);
			else if (s[0] == '0') pk[i].push_back(10);
			else if (s[0] == 'J') pk[i].push_back(11);
			else if (s[0] == 'Q') pk[i].push_back(12);
			else pk[i].push_back(13);
		}
	}
	while (pk[13].size()) {
		play(13);
	}
	int res = 0;
	for (int i = 1; i <= 12; i++) {
		if (pos[i] == 4) res++;
	}
	cout << res << endl;
	return 0;
} 
