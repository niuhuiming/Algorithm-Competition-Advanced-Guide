#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long ll;
const int N = 1010;

int n;
int p[10];
char ch[N][N];
int dx[] = {0, 1, 2, 2}, dy[] = {2, 1, 0, 2};

void dfs(int n) {
	if (n == 1) {
		ch[0][0] = 'X';
		return ;
	}
	dfs(n - 1);
	
	int len = p[n - 2];
	for (int k = 0; k < 4; k++) {
		for (int i = 0; i < len; i++) {
			for (int j = 0; j < len; j++) {
				int x = dx[k] * len + i;
				int y = dy[k] * len + j;
				ch[x][y] = ch[i][j];
			} 
		}
	}
}

int main() {
	p[0] = 1;
	for (int i = 1; i <= 7; i++) {
		p[i] = p[i - 1] * 3;
	}
	dfs(7);
	while (cin >> n, n != -1) {
		int len = p[n - 1];
		for (int i = 0; i < len; i++) {
			for (int j = 0; j < len; j++) {
				if (ch[i][j]) cout << ch[i][j];
				else cout << ' ';
			}
			cout << endl;
		} 
		cout << '-' << endl;
	} 
	return 0;
} 
