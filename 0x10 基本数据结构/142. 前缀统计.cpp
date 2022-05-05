#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long ll;
const int N = 100010;


int n, m;

// Ç°×ºÍ³¼Æ
int son[N][26], cnt[N], idx;
char str[N];

void insert() {
    int p = 0;
    for (int i = 0; str[i]; i++) {
        int s = str[i] - 'a';
        if (son[p][s] == 0) son[p][s] = ++idx;
        p = son[p][s];
    }
    cnt[p]++;
}

int query() {
    int p = 0, res = 0;
    for (int i = 0; str[i]; i++) {
        int s = str[i] - 'a';
        if (son[p][s] == 0) break;
        p = son[p][s];
        res += cnt[p];
    }
    return res;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> str;
		insert();
	}
	while (m--) {
		cin >> str;
		cout << query() << endl;
	}
	return 0;
} 
