#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;
typedef unsigned long long ull;
const int N = 2000010;
const ull base = 13331;

char s[N], str[N];

int manacher(char *s) {
    char str[N] = {0};
    str[0] = '!', str[1] = '#';  // ÉÚ±østr[0]
    int n = strlen(s), m = n * 2 + 1;
    str[m + 1] = '@';  // ÉÚ±østr[m + 1]
    for (int i = 0; i < n; i++) {
        str[i * 2 + 2] = s[i];
        str[i * 2 + 3] = '#';
    }
    int rt = 0, mid = 0, res = 0;
    int p[N];
    for (int i = 1; i <= m; i++) {
        p[i] = i < rt ? min(p[2 * mid - i], rt - i) : 1;
        while (str[i + p[i]] == str[i - p[i]]) p[i]++;
        if (i + p[i] > rt) {
            rt = i + p[i];
            mid = i;
        }
        res = max(res, p[i] - 1);
    }
    return res;
}

int main() {
	int T = 1;
	while (scanf("%s", &s) && strcmp(s, "END")) {
		cout << "Case " << T++ << ": " << manacher(s) << endl;
	}
	return 0;
} 
