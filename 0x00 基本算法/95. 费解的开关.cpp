#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
typedef long long ll;
const int N = 100010;

int dx[] = {0, 0, 1, -1, 0}, dy[] = {1, -1, 0, 0, 0};

int n;
string light[5], tmp[5];

void click(int x, int y) {
	for (int i = 0; i < 5; i++) {
		int nx = dx[i] + x, ny = dy[i] + y;
		if (nx >= 0 && nx < 5 && ny >= 0 && ny < 5) {
			if (tmp[nx][ny] == '0') tmp[nx][ny] = '1';
			else tmp[nx][ny] = '0';
		}
	}
}

int main() {
	cin >> n;
	while (n--) {
		for (int i = 0; i < 5; i++) {
			cin >> light[i];
		}
		int res = 6;
		for (int i = 0; i < (1 << 5); i++) {
			for (int j = 0; j < 5; j++) {
				tmp[j] = light[j];
			}
			int cnt = 0;
			for (int j = 0; j < 5; j++) {
				if ((i >> j) & 1) {
					cnt++;
					click(0, j);
				}
			}
			for (int j = 1; j < 5; j++) {
				for (int k = 0; k < 5; k++) {
					if (tmp[j - 1][k] == '0') {
						cnt++;
						click(j, k);
					}
				} 
			}
			res = min(res, cnt);
		}
		if (res == 6) res = -1;
		cout << res << endl;
	} 
	return 0;
}
