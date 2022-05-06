#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long ll;
const int N = 2000010;

char a[N], b[N];

int get_min(char* s) { // 返回最小表示法开始的下标
	int n = strlen(s + 1);
	for (int i = 1; i <= n; i++) s[n + i] = s[i];
	int i = 1, j = 2, k;
	while (i <= n && j <= n) {
		for (k = 0; k < n && s[i + k] == s[j + k]; k++) {};
		if (k == n) break;
		if (s[i + k] > s[j + k]) {
			i = i + k + 1;
			if (i == j) i++;
		} else {
			j = j + k + 1;
			if (i == j) j++;
		}
	}
	return min(i, j);
}

int main() {
	cin >> (a + 1) >> (b + 1);
	int len = strlen(a + 1);
	if (strlen(b + 1) != len) {
	    cout << "No" << endl;
	    return 0;
	}
	int pa = get_min(a);
	int pb = get_min(b);
	string sa, sb;
	for (int i = pa; i <= len; i++) {
		sa += a[i];
	}
	for (int i = 1; i < pa; i++) {
		sa += a[i];
	}
	for (int i = pb; i <= len; i++) {
		sb += b[i];
	}
	for (int i = 1; i < pb; i++) {
		sb += b[i];
	}
	if (sa == sb) {
		cout << "Yes" << endl << sa << endl;
	} else {
		cout << "No" << endl;
	}
	return 0;
} 
