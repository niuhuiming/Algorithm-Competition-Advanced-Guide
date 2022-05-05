#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <stack>
using namespace std;
typedef long long ll;
const int N = 1000010;

stack<int> st, ba;
int s[N];
int f[N] = {-0x3f3f3f3f};

int main() {
	int t;
	cin >> t;
	while (t--) {
		int x;
		string op;
		cin >> op;
		if (op[0] == 'I') {
			cin >> x;
			st.push(x);
			s[st.size()] = s[st.size() - 1] + st.top();
			f[st.size()] = max(f[st.size() - 1], s[st.size()]);
		} else if (op[0] == 'D') {
			if (st.size()) st.pop();
		} else if (op[0] == 'L') {
			if (st.size()) {
				ba.push(st.top());
				st.pop();
			}
		} else if (op[0] == 'R') {
			if (ba.size()) {
				st.push(ba.top());
				ba.pop();
				s[st.size()] = s[st.size() - 1] + st.top();
				f[st.size()] = max(f[st.size() - 1], s[st.size()]);
			}
		} else if (op[0] == 'Q') {
			cin >> x;
			cout << f[x] << endl; 
		}
	} 
	return 0;
} 
