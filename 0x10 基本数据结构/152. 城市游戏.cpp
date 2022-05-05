#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <stack>
using namespace std;
typedef long long ll;
const int N = 1010;

int n, m;
int s[N][N];

void get(int* h, int* last) {
	stack<int> st;
	st.push(0);
	for (int i = 1; i <= m; i++) {
		while (h[st.top()] >= h[i]) st.pop();
		last[i] = st.top();
		st.push(i);
	}
}

int calc(int* h) {
	int l[N] = {0}, r[N] = {0};
	get(h, l);
	reverse(h + 1, h + m + 1);
	get(h, r);
	reverse(h + 1, h + m + 1);
	int res = 0;
	for (int i = 1; i <= m; i++) {
		res = max(res, h[i] * (m - r[m - i + 1] - l[i]));
	} 
	return res;
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			string str;
			cin >> str;
			if (str[0] == 'F') {
				s[i][j] = s[i - 1][j] + 1;
			} else {
				s[i][j] = 0;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		s[i][0] = s[i][m + 1] = -1;
	}
	int res = 0;
	for (int i = 1; i <= n; i++) {
		res = max(res, calc(s[i]));
	}
	cout << 3 * res << endl;
	return 0;
} 
