#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long ll;
const int N = 1010;

string fridge[4], fr[4];

void click(int x, int y) {
	for (int i = 0; i < 4; i++) {
		if (fr[x][i] == '+') fr[x][i] = '-';
		else fr[x][i] = '+';
		if (fr[i][y] == '+') fr[i][y] = '-';
		else fr[i][y] = '+';
	}
	if (fr[x][y] == '+') fr[x][y] = '-';
	else fr[x][y] = '+';
}

bool open() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (fr[i][j] == '+') {
				return false;
			}
		} 
	} 
	return true;
}

int main() {
	for (int i = 0; i < 4; i++) {
		cin >> fridge[i];
	} 
	for (int i = 0; i < (1 << 16); i++) {
		for (int j = 0; j < 4; j++) {
			fr[j] = fridge[j];
		}
		int cnt = 0;
		for (int j = 0; j < 16; j++) {
			if ((i >> j) & 1) {
				cnt++;
				int row = j / 4, col = j % 4;
				click(row, col);
			}
		}
		if (open()) {
			cout << cnt << endl;
			for (int j = 0; j < 16; j++) {
				if ((i >> j) & 1) {
					cout << j / 4 + 1 << ' ' << j % 4 + 1 << endl;
				}
			} 
		}
	} 
	return 0;
} 
