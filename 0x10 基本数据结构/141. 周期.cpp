#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long ll;
const int N = 1000010;

int n;
int ne[N];
char s[N];

void get_next() {
	for (int i = 2, j = 0; i <= n; i++) {
		while (j && s[i] != s[j + 1]) j = ne[j];
		if (s[i] == s[j + 1]) j++;
		ne[i] = j;
	}
}

int main() {
	int T = 1;
	while (cin >> n, n) {
		cin >> (s + 1);
		get_next();
		cout << "Test case #" << T++ << endl;
		for (int i = 1; i <= n; i++) {
			if (i % (i - ne[i]) == 0 && i / (i - ne[i]) > 1) {
				cout << i << ' ' << i / (i - ne[i]) << endl;
			}
		}
		cout << endl;
	}
	return 0;
} 
